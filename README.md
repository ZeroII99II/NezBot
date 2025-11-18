# NezBot Workspace Layout

This repository is now organized to mirror the official GigaLearnCPP leak structure so you can follow the published installation instructions verbatim.

```
NezBot/
├── GigaLearnCPP-Leak/
│   ├── CMakeLists.txt
│   ├── CMakeSettings.json
│   ├── README.md (upstream notes + NezBot specific guidance)
│   ├── docs/
│   │   └── INSTALLATION.md (step-by-step setup and RLBot integration guide)
│   ├── tools/
│   │   └── checkpoint_converter.py (stub entry point for model transfers)
│   └── GigaLearnCPP/
│       ├── src/ (RLBot client + entry points)
│       ├── rlbot/ (agent configuration files)
│       ├── libtorch/ (drop the LibTorch distribution here)
│       └── collision_meshes/ (drop your arena collision meshes here)
└── README.md (this file)
```

Drop the upstream leak inside `GigaLearnCPP-Leak/` and follow `docs/INSTALLATION.md` to finish configuring CUDA, LibTorch, RLBot, and the NezBot training assets.
