-- AntimonyTutorial.md uses a bare '[TOC]' line so Doxygen's markdown
-- extension auto-generates a table of contents there. Pandoc has no such
-- extension and would otherwise render that line as a literal paragraph, so
-- this filter drops it; pandoc's own '--toc' flag supplies the real one.
function Para(el)
  if #el.content == 1 and el.content[1].t == "Str" and el.content[1].text == "[TOC]" then
    return {}
  end
end
