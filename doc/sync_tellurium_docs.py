#!/usr/bin/env python3
"""
Report which sections of AntimonyTutorial.rst (the antimony repo's
pandoc-generated tutorial) have changed relative to the hand-maintained
copy in the tellurium repo (docs/antimony.rst), so only the changed bits
need to be copied over by hand.

Sections are matched by heading text rather than by raw line diff, so the
comparison survives the two files using slightly different RST rendering
(quote characters, underline choices, line wrapping) and survives the
tellurium copy having extra Tellurium-specific sections interspersed.

This tool only prints a report -- it does not modify either file.

Usage:
    python sync_tellurium_docs.py [SOURCE_RST] TARGET_RST

Defaults:
    SOURCE_RST defaults to AntimonyTutorial.rst next to this script.
    TARGET_RST is required (e.g. .../tellurium/docs/antimony.rst).
"""
import argparse
import difflib
import re
import sys
from pathlib import Path

UNDERLINE_CHARS = set('=-~^"\'`#*+.:_')

# Sections that are expected to always differ for structural reasons, not
# because of real content drift -- e.g. tellurium's antimony.rst uses a
# '.. contents::' auto-directive where AntimonyTutorial.rst has a literal
# pandoc-rendered nested list. Matched case-insensitively against the
# (normalized) heading text.
DEFAULT_IGNORE = {'table of contents'}


def parse_sections(text):
    """Split RST text into heading-anchored chunks.

    A heading is any non-blank line immediately followed by a line made of
    a single repeated punctuation character at least as long as the
    (stripped) heading text -- the standard docutils convention, and the
    one both AntimonyTutorial.rst and tellurium's antimony.rst use. Each
    section's body is everything up to the next heading of any level, so
    nested subsections are compared independently of their parent.

    docutils assigns heading levels by the *order in which underline
    characters are first seen* in the document, not by a fixed per-character
    level -- so level is computed the same way here. Each section also gets
    'path', the tuple of ancestor titles above it, since the same title can
    legitimately appear more than once in one of these documents (e.g. two
    separate 'Compartments' sections, one introductory and one reference);
    matching on title alone would conflate them.
    """
    lines = text.splitlines()
    heading_idxs = []
    i = 0
    while i < len(lines) - 1:
        title = lines[i].rstrip()
        underline = lines[i + 1].rstrip()
        if (title and underline and len(set(underline)) == 1
                and underline[0] in UNDERLINE_CHARS
                and len(underline) >= max(3, int(len(title) * 0.9))):
            heading_idxs.append((i, title, underline[0]))
            i += 2
        else:
            i += 1

    level_of_char = {}
    for _, _, ch in heading_idxs:
        if ch not in level_of_char:
            level_of_char[ch] = len(level_of_char)

    sections = []
    ancestors = []  # stack of titles, indexed by level
    for n, (idx, title, ch) in enumerate(heading_idxs):
        level = level_of_char[ch]
        ancestors = ancestors[:level]
        path = tuple(ancestors)
        ancestors.append(title)

        body_start = idx + 2
        body_end = heading_idxs[n + 1][0] if n + 1 < len(heading_idxs) else len(lines)
        sections.append({
            'title': title,
            'path': path,
            'char': ch,
            'level': level,
            'body': lines[body_start:body_end],
            'line': idx + 1,
        })
    return sections


def normalize_title(title):
    # Smart quotes and whitespace can differ between the two RST variants
    # even when the heading is 'the same' -- normalize before matching.
    t = title.replace('‘', "'").replace('’', "'")
    t = t.replace('“', '"').replace('”', '"')
    t = re.sub(r'\s+', ' ', t.strip())
    return t.casefold()


def section_key(section):
    """Matching key: normalized ancestor path + own title, so two sections
    with the same title but different parents (e.g. 'Model Elements >
    Compartments' vs 'Language Reference > Compartments') don't collide."""
    return tuple(normalize_title(p) for p in section['path']) + (normalize_title(section['title']),)


def breadcrumb(section):
    return ' > '.join(section['path'] + (section['title'],))


# Tellurium's antimony.rst wraps several shared code examples (the Signals
# sections: Step Input, Ramp, Pulse, etc.) in a '.. code:: python' block that
# calls te.loada("""...""")/r.simulate()/r.plot() around the same antimony
# snippet AntimonyTutorial.rst gives bare in a plain '::' block. That wrapper
# always differs and never carries content worth copying -- but the antimony
# code inside it can still change, so instead of ignoring these sections
# outright, the wrapper lines are filtered out before deciding whether a
# section actually changed. If real content differs too, the section is
# still reported (with the full, unfiltered diff, for context).
WRAPPER_NOISE_PATTERNS = [
    re.compile(r'^\.\.\s+code::\s+python\s*$'),
    re.compile(r'^::\s*$'),
    re.compile(r'^import tellurium as te\s*$'),
    re.compile(r'^import roadrunner\s*$'),
    re.compile(r'^r\s*=\s*te\.loada\("""\s*$'),
    re.compile(r'^"""\)\s*$'),
    re.compile(r'^m\s*=\s*r\.simulate\s*\(.*\)\s*$'),
    re.compile(r'^r\.plot\(\)\s*$'),
]


def strip_wrapper_noise(section):
    """Body lines with known Tellurium wrapper boilerplate, blank lines, and
    the redundant figure-caption line pandoc adds (a line that just repeats
    the section's own title) removed, for deciding whether content actually
    changed."""
    title_key = normalize_title(section['title'])
    out = []
    for line in section['body']:
        stripped = line.strip()
        if not stripped:
            continue
        if any(p.match(stripped) for p in WRAPPER_NOISE_PATTERNS):
            continue
        if normalize_title(stripped) == title_key:
            continue
        out.append(stripped)
    return out


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                      formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('source', nargs='?',
                         default=str(Path(__file__).resolve().parent / 'AntimonyTutorial.rst'),
                         help='antimony repo AntimonyTutorial.rst (source of truth)')
    parser.add_argument('target',
                         help='tellurium repo docs/antimony.rst (hand-maintained)')
    parser.add_argument('--ignore', action='append', default=[],
                         help='additional heading text to skip (repeatable); '
                              f'always skips: {", ".join(sorted(DEFAULT_IGNORE))}')
    args = parser.parse_args()

    ignore = DEFAULT_IGNORE | {normalize_title(t) for t in args.ignore}

    source_path = Path(args.source)
    target_path = Path(args.target)
    source_text = source_path.read_text(encoding='utf-8')
    target_text = target_path.read_text(encoding='utf-8')

    source_sections = [s for s in parse_sections(source_text)
                        if normalize_title(s['title']) not in ignore]
    target_sections = [s for s in parse_sections(target_text)
                        if normalize_title(s['title']) not in ignore]

    for label, sections in (('source', source_sections), ('target', target_sections)):
        seen = set()
        for s in sections:
            key = section_key(s)
            if key in seen:
                print(f"WARNING: duplicate section path in {label} -- "
                      f"{breadcrumb(s)!r} appears more than once; only the "
                      f"last occurrence will be matched.", file=sys.stderr)
            seen.add(key)

    target_by_key = {section_key(s): s for s in target_sections}
    source_keys = {section_key(s) for s in source_sections}

    changed, unchanged, wrapper_noise_only, new_in_source = [], [], [], []

    for s in source_sections:
        t = target_by_key.get(section_key(s))
        if t is None:
            new_in_source.append(s)
        elif s['body'] == t['body']:
            unchanged.append(s)
        elif strip_wrapper_noise(s) == strip_wrapper_noise(t):
            wrapper_noise_only.append(s)
        else:
            changed.append((s, t))

    only_in_target = [t for t in target_sections
                       if section_key(t) not in source_keys]

    print(f"Compared {len(source_sections)} sections in {source_path}")
    print(f"     against {len(target_sections)} sections in {target_path}\n")

    if changed:
        print(f"=== {len(changed)} section(s) changed -- copy these into {target_path} ===\n")
        for s, t in changed:
            print(f"--- {breadcrumb(s)}  "
                  f"(source line {s['line']}, target line {t['line']}) ---")
            diff = difflib.unified_diff(
                t['body'], s['body'],
                fromfile=f"{target_path.name}:{t['title']}",
                tofile=f"{source_path.name}:{s['title']}",
                lineterm='')
            print('\n'.join(diff))
            print()

    if new_in_source:
        print(f"=== {len(new_in_source)} section(s) new in {source_path} "
              f"-- need manual placement in {target_path} ===\n")
        for s in new_in_source:
            print(f"--- {breadcrumb(s)} (source line {s['line']}) ---")
            print('\n'.join(s['body']).strip())
            print()

    if only_in_target:
        print(f"=== {len(only_in_target)} section(s) only in {target_path} "
              f"(assumed Tellurium-specific, left alone) ===")
        for t in only_in_target:
            print(f"  - {breadcrumb(t)} (line {t['line']})")
        print()

    if wrapper_noise_only:
        print(f"=== {len(wrapper_noise_only)} section(s) differ only in the "
              f"Tellurium te.loada()/r.plot() wrapper -- no action needed ===")
        for s in wrapper_noise_only:
            print(f"  - {breadcrumb(s)} (source line {s['line']})")
        print()

    print(f"{len(unchanged)} section(s) unchanged.")

    if not changed and not new_in_source:
        sys.exit(0)
    sys.exit(1)


if __name__ == '__main__':
    main()
