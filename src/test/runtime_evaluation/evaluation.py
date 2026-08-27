import antimony
import libsbml
from pathlib import Path
import re
import time
import csv
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from scipy.stats import t


COLORS = {
    "sbml_to_antimony": "#0072B2",
    "antimony_to_sbml": "#E69F00",
}


def load_results(results_file_name):
    results_file = Path(results_file_name)

    if results_file.exists():
        with open(results_file) as f:
            return list(csv.DictReader(f))

    return None


def get_sbml_models(models_dir):
    return [
        {
            "path": p,
            "biomodel_id": re.search(r"BIOMD\d+", str(p)).group(),
            "file_size": p.stat().st_size,
        }
        for p in Path(models_dir).rglob("*.xml")
    ]


def save_results(results):
    with open("evaluation_results.csv", "w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=results[0].keys())
        writer.writeheader()
        writer.writerows(results)


def benchmark():
    results = load_results("evaluation_results.csv")
    if results is not None:
        return results

    results = []
    models = get_sbml_models("./large_biomodels")
    for model in models:
        sbml_document = libsbml.readSBMLFromFile(str(model["path"]))
        sbml_string = libsbml.writeSBMLToString(sbml_document)

        for repeat in range(10):
            # SBML -> Antimony
            antimony.clearPreviousLoads()
            start = time.perf_counter()
            antimony.loadSBMLString(sbml_string)
            antimony_string = antimony.getAntimonyString(None)
            t1 = time.perf_counter() - start

            # Antimony -> SBML
            antimony.clearPreviousLoads()
            start = time.perf_counter()
            antimony.loadAntimonyString(antimony_string)
            module = antimony.getMainModuleName()
            antimony.getSBMLString(module)
            t2 = time.perf_counter() - start

            results.append({
                "biomodel_id": model["biomodel_id"],
                "file_size": model["file_size"],
                "repeat": repeat + 1,
                "sbml_to_antimony_s": t1,
                "antimony_to_sbml_s": t2,
            })

    save_results(results)
    return results


def process_results(results):
    df = pd.DataFrame(results)

    numeric_cols = [
        "file_size",
        "sbml_to_antimony_s",
        "antimony_to_sbml_s",
    ]
    df[numeric_cols] = df[numeric_cols].apply(pd.to_numeric)

    df["model"] = df["biomodel_id"].str.replace("BIOMD", "").astype(int)

    return df.groupby("model").agg(
        file_size=("file_size", "first"),
        s2a_mean=("sbml_to_antimony_s", "mean"),
        s2a_sem=("sbml_to_antimony_s", "sem"),
        a2s_mean=("antimony_to_sbml_s", "mean"),
        a2s_sem=("antimony_to_sbml_s", "sem"),
        n=("sbml_to_antimony_s", "count"),
    ).sort_values("file_size", ascending=False)


def set_plot_style():
    plt.rcParams.update({
        "font.family": "sans-serif",
        "font.sans-serif": ["Helvetica Neue", "Arial", "DejaVu Sans"],
        "font.size": 11,
        "axes.titlesize": 13,
        "axes.labelsize": 11,
        "xtick.labelsize": 9.5,
        "ytick.labelsize": 9.5,
        "legend.fontsize": 10,
        "axes.edgecolor": "#888888",
        "text.color": "#222222",
        "axes.labelcolor": "#222222",
        "xtick.color": "#444444",
        "ytick.color": "#444444",
    })


def add_bars(ax, results, x, width, ci, error_style):
    bars = [
        ("s2a", -width / 2, "sbml_to_antimony", "SBML $\\rightarrow$ Antimony"),
        ("a2s",  width / 2, "antimony_to_sbml", "Antimony $\\rightarrow$ SBML"),
    ]

    for prefix, offset, color, label in bars:
        ax.bar(
            x + offset,
            results[f"{prefix}_mean"],
            width,
            yerr=ci * results[f"{prefix}_sem"],
            error_kw=error_style,
            color=COLORS[color],
            alpha=0.9,
            label=label,
        )


def format_axes(ax, results, x):
    ax.set_xticks(x)
    ax.set_xticklabels(results.index, fontsize=11)

    for xi, size in zip(x, results["file_size"]):
        ax.annotate(
            f"({size / 1e6:.1f} MB)",
            xy=(xi, 0),
            xycoords=("data", "axes fraction"),
            xytext=(0, -18),
            textcoords="offset points",
            ha="center",
            va="top",
            fontsize=9.5,
            color="#444444",
        )

    ax.set_xlabel("BioModels ID (SBML file size)", labelpad=26)
    ax.set_ylabel("Runtime (s)")
    ax.spines[["top", "right"]].set_visible(False)
    ax.spines[["left", "bottom"]].set_color("#888888")
    ax.tick_params(axis="both", length=0)
    ax.yaxis.grid(True, linewidth=0.6, alpha=0.15)
    ax.set_axisbelow(True)
    ax.legend(frameon=False, loc="upper right", fontsize=11)


def plot_results(results):
    set_plot_style()

    ci = t.ppf(0.975, results["n"] - 1)
    x = np.arange(len(results))
    width = 0.38

    fig, ax = plt.subplots(figsize=(10, 5.5))
    error_style = {
        "elinewidth": 1,
        "ecolor": "#333333",
        "capsize": 0,
        "alpha": 0.8,
    }
    add_bars(ax, results, x, width, ci, error_style)
    format_axes(ax, results, x)

    fig.tight_layout()
    fig.savefig("evaluation_results.png", bbox_inches="tight")
    plt.show()


def main():
    results = benchmark()
    processed_results = process_results(results)
    plot_results(processed_results)


if __name__ == "__main__":
    main()
