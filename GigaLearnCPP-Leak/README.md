# GigaLearnCPP Leaked Version

-------------
# This is the version that cheaters decided to leak :(

### This library was intended to be private, but apparently we can't have nice things. 

A trusted former GigaLearn user (with source code access) decided to join the cheaters and then share around this library, now it's public.
Thus, I am formally publishing this specific version for anyone to use.

-------------

GigaLearn is an even-faster C++ machine learning framework for Rocket League bots.
This is a progression far beyond my previous C++ learning framework, RLGymPPO-CPP (which I have stopped developing).

## Speed
Collection speeds are around 2x faster in GigaLearn than RLGymPPO-CPP, and around 10x faster than RLGym-PPO (on my machine).
Consumption speeds are a bit faster than RLGymPPO-CPP, although this varies heavily.
This speed is not at all final and I plan to make the library much faster once I finish other important features.

## Features
**Basic Features (Shared With Most Frameworks)**:
- Fast PPO implementation
- Configurable model layer sizes
- Checkpoint saving/loading
- Working example
- Return standardization and obs standardization support
- Built-in visualization support
- Easy custom metrics suppport

**Unique Learning Features**:
- Extremely fast monolithic single-process inference model
- Complete and proper action masking
- Built-in shared layers support (enabled by default)
- Built-in configurable ELO-based skill tracking system 
- Configurable model activation functions
- Configurable model optimizers
- Configurable model layer norm (recommended)
- Policy version saving system (required if using the skill tracker)
- Built-in reward logging

**Unique Environment/State Features**:
- Access to previous states (e.g. `player.prev->pos`)
- Simpler access to previous actions, final bools
- Inherented access to all `CarState` and `BallState` fields (e.g. `player.isFlipping`)
- No more duplicate state fields
- Simpler access to current state events (e.g. `if (player.eventState.shot) ...`)
- User-led setup of arenas and cars during environment creation
- RocketSim-based state setting (you are given the arena to state-set)
- Configurable action delay

***Coming Soon**:
- Training against older versions

## Installation
*There's no installation guide for now as I plan to rework several aspects of the library to make it easier to install.*

## Bringing In Rewards/Obs Builders/Etc. from RLGymPPO_CPP
State changes:
- `PlayerData` -> `Player`
- `player.phys` -> `player.`
- `player.carState` -> `player`
- `state.ballState` -> `state.ball`

Reward changes:
- `GetReward(const PlayerData& player, const GameState& state, const Action& prevAction)` -> `GetReward(const Player& player, const GameState& state, bool isFinal) override`
- `prevAction (argument)` -> `player.prevAction`
- `GetFinalReward()` -> `isFinal (argument)`

Metrics:
- `metrics.AccumAvg(), metrics.GetAvg()` -> `report.AddAvg()`

Learner config:
- `cfg.numThreads, cfg.numGamesPerThread` -> `cfg.numGames`
- `cfg.ppo.policyLayerSizes` -> `cfg.ppo.policy.layerSizes`
- `cfg.ppo.criticLayerSizes` -> `cfg.ppo.critic.layerSizes`
- `cfg.expBufferSize` -> `(experience buffer removed)`

---

## NezBot Workspace Notes

The original README above is preserved for historical context. For day-to-day development:

- Follow `docs/INSTALLATION.md` for CUDA, LibTorch, RLBot, and Python configuration.
- Drop the official LibTorch bundle inside `GigaLearnCPP/libtorch/` and keep only the `.gitkeep` file tracked.
- Place arena collision meshes inside `GigaLearnCPP/collision_meshes/` and update the path inside `src/ExampleMain.cpp`.
- RLBot configs live in `GigaLearnCPP/rlbot/`. Edit `CppPythonAgent.cfg` after you compile `rlbot.exe` so it points to the correct path.
- The RLBot entry point is `GigaLearnCPP/src/rlbotmain.cpp`, which already wires up the client stub in this repo.

This layout ensures the repository mirrors the official leak and the RLBot example so your scripted install steps can be followed without guesswork.
