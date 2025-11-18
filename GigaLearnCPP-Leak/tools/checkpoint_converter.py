"""Stub script for converting checkpoints between Python and C++ formats.

Fill this script with the logic from `tools/checkpoint_converter.py` in the
original leak so that exported PyTorch weights match the LibTorch runtime.
"""

from pathlib import Path


def convert_checkpoint(source: Path, destination: Path) -> None:
    destination.write_text(
        "This is a placeholder. Implement conversion logic from the upstream repo.\n"
    )


def main() -> None:
    repo_root = Path(__file__).resolve().parents[1]
    checkpoints = repo_root / "GigaLearnCPP" / "checkpoints"
    checkpoints.mkdir(exist_ok=True)
    sample_src = checkpoints / "SAMPLE.pt"
    sample_dst = checkpoints / "SAMPLE.lt"
    convert_checkpoint(sample_src, sample_dst)


if __name__ == "__main__":
    main()
