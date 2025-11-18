# GigaLearnCPP + RLBot Installation Guide

This document captures the steps from Speed's announcement and the RLBot example repository so everything required to train and deploy NezBot is tracked in one place.

## 1. Clone the leak
```bash
git clone https://github.com/ZealanL/GigaLearnCPP-Leak --recurse
```
After cloning, copy the files from this repository so the folder tree matches the structure documented in the root `README.md`.

## 2. Install CUDA 11.8 (optional but recommended)
If you have an NVIDIA GPU, install CUDA 11.8 from the [official archive](https://developer.nvidia.com/cuda-11-8-0-download-archive). Skip this step if you only plan to run on CPU.

## 3. Download LibTorch
Grab the LibTorch distribution that matches your CUDA installation (CUDA 11.8 build if you installed CUDA, CPU-only build otherwise) from [the PyTorch website](https://pytorch.org/get-started/locally/). Extract it into `GigaLearnCPP/libtorch/`.

> Only keep the `.gitkeep` file committed; the rest of the LibTorch payload is downloaded per-machine.

## 4. Open the project with CMake
Open `GigaLearnCPP-Leak/` as a CMake project in your IDE of choice (Visual Studio with the C++ Desktop workload is recommended on Windows).

## 5. Build type
Set the CMake build configuration to `RelWithDebInfo`. Debug works, but it is extremely slow and not officially supported.

## 6. Python dependencies
Install a global Python distribution (3.9+ recommended) and add `wandb` unless you plan to disable metrics:
```bash
pip install wandb
```

## 7. Build
Configure and build the project through CMake / your IDE. The `rlbot.exe` target is what the RLBot runner launches.

## 8. Collision meshes
Drop your `collision_meshes` folder next to the compiled executable (e.g. `GigaLearnCPP/build/RelWithDebInfo/collision_meshes`). Also update the path inside `GigaLearnCPP/src/ExampleMain.cpp` so the runtime knows where to load them.

If you do not already have the meshes, generate them with [RLArenaCollisionDumper](https://github.com/ZealanL/RLArenaCollisionDumper).

---

# RLBot Integration Checklist

These steps mirror the [`GigaLearn-RLBot-Example`](https://github.com/Kuenec/GigaLearn-RLBot-Example) repository.

1. **Replace core files** – Copy the `CMakeLists.txt`, `RLBotClient.*`, and `rlbotmain.cpp` files from this repo into `GigaLearnCPP/` and `GigaLearnCPP/src/`.
2. **Configure the agent** – Copy `CppPythonAgent.cfg` into `GigaLearnCPP/rlbot/` and edit `cpp_executable_path` so it points at your compiled `rlbot.exe`.
3. **Port configuration** – Ensure the port declared in `rlbotmain.cpp` matches the value in `rlbot/port.cfg`.
4. **Checkpoints** – Place your trained checkpoints next to the compiled executable. The runner automatically loads the newest checkpoint unless you hard-code the path in `src/rlbotmain.cpp`.
5. **Optional override** – Uncomment `checkpointPath =` inside `rlbotmain.cpp` to force a specific `POLICY.lt` file. Remember to escape Windows paths with double backslashes (`\\`).
6. **Run RLBot** – Add `GigaLearnCPP/rlbot/CppPythonAgent.cfg` to the RLBot GUI and start a match. Your bot should connect through the RLBot client stub provided here.

## Troubleshooting
- **Bot missing in RLBot:** verify the `cpp_executable_path` value and make sure the executable actually exists.
- **"Could not connect to server" errors:** double-check the port configuration in `rlbotmain.cpp` and `rlbot/port.cfg`.
- **Event loop stopped:** ensure matching port configuration; if the issue persists install `websockets==12.0` in your RLBot Python environment.

## Notes
- Ball prediction is not supported by default. If your observation builder requires it, feed a `RocketSimArena` into `rlbotmain.cpp` and modify the builder accordingly.
- Padded observations are supported; change `auto obsBuilder = std::make_unique<AdvancedObs>();` to `auto obsBuilder = std::make_unique<YourObsNamePadded>(3);` and set the padding parameter you used during training.
