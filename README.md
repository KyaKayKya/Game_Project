# <center>**Illuminati: The end of the world** 😋</center>

## 🤩 Introduction

> This is a 2D RPG game developed using C language and the SDL library.

![Game Trailer Teaser](static/game-trailer.gif)

> Check out the full game trailer [here](game-trailer.mp4).

## 🚀 Quick Start Guide
Download the latest version of installation package.zip from the Releases section. After extracting, run either `Illuminati: The End of the World.msi` or `setup.exe` to install the game. 🤗

The savings folder includes multiple backup save files to help you avoid getting stuck. 😘 Here's how to use them:

- Pick the save file you need from the saving folder.

- Copy it to the `\S` folder in your game directory.

- Rename the file to `gamesave.dat1.dat` — it will take effect right away!

## 😋 Enjoy the game~

---

## 🛠️ Developer Reference

### Story Overview

Prince and Ellie are survivors of a world destroyed by Dragon (leader of Illuminati) using a biochemical bomb. They discover a time machine and travel back to the past to stop his plan. Along the way they encounter scientist Wyvern (mechanically controlled by Dragon), nurse Emma, researcher DC, and the mysterious Lamy.

---

### Gameplay Phases

| Phase | Map ID | Description |
|---|---|---|
| Intro (Hallway) | 0 | Opening dialogue, free exploration |
| Lab area | 1, 12–18 | Multi-room exploration, collect 3 disks + ID card |
| Time Puzzle | 2 | Calendar-based time machine puzzle (defeat the time phantom) |
| Plane fight | 3, 20 | Dodge bullets for 20 seconds in a scrolling shooter |
| Forest | 21, 22 | Exploration after crash-landing |
| Parkour | 23 | Auto-runner section |
| Rock hole | 24 | Short exploration cave |
| Boss 1 — Wyvern | 5 / 18 | Top-down bullet avoider with mechanical flies & frogs |
| Boss 2 — Dragon | 25 | Bomb-dodge battle, uses ID card shield ability |
| Final Puzzle | 26 | Logic circuit puzzle to defuse the bio bomb |

---

### Project Structure

```
Game_Project-main/
├── SDL2_test/
│   ├── Main.cpp            ← Main entry point & game loop (all map logic lives here)
│   ├── SDL2_test.h         ← Global types, structs, constants, function declarations
│   │
│   ├── Puzzle1.cpp         ← (Older standalone prototype – NOT compiled in current build)
│   ├── 3.cpp / 3.h         ← Final bomb-defusal logic circuit puzzle (Puzzle 3 / Map 26)
│   │
│   ├── BOSS1.cpp / BOSS.h  ← Boss 1 (Wyvern): flies, frogs, ID card mechanic
│   ├── BOSS2.cpp / BOSS2.h ← Boss 2 (Dragon): bombs, floor elements, shields
│   │
│   ├── Run Game.cpp / Run Game.h  ← Parkour auto-runner mini-game (Map 23)
│   ├── test2.cpp / test2.h        ← Pause menu, image slideshow loader
│   ├── dialogue(1.cpp             ← Dialogue rendering helpers, audio callback
│   ├── log_in.cpp                 ← Title screen text fade-in/out
│   ├── enter.h                    ← Save/load system, splash screen, GameData struct
│   │
│   ├── assets/
│   │   ├── Audio/     ← BGM and sound effects
│   │   ├── character/ ← Player sprite sheets
│   │   ├── Font/      ← TTF font files
│   │   ├── Ingame/    ← Dialogue background and scene images
│   │   └── Menu/      ← Menu background images
│   └── Avatars/       ← Character portrait images for dialogue boxes
│
└── Savings/           ← Backup save files (see Quick Start above)
```

---

### Key Source Files

| File | Role |
|---|---|
| `Main.cpp` | Game loop, all map render functions (`Map_0`–`Map_8`, `Map_21`–`Map_24`), dialogue strings, `INIT/LOAD/QUIT`, `Map_Shift` (fade + auto-save), `present()` dialogue box, collision system |
| `enter.h` | `GameData` struct, `saveGame/loadGame` (binary I/O to `S/gamesave.datN.dat`), splash screen `Load_IN()` |
| `BOSS1.cpp` | Wave attack system, fly/frog/star mechanics, health bars |
| `BOSS2.cpp` | Bomb-drop system, 4-floor arena, ID card shield, two difficulty states based on `kill_Scientist` flag |
| `3.cpp` | Click-to-toggle circuit simulator (switches, wires, AND/OR gates) |
| `Run Game.cpp` | Flappy-bird-style auto-runner; returns `1` win / `-1` lose / `0` quit |
| `test2.cpp` | `Pause()` overlay, `show_instruction()` image page-flipper |

---

### Controls

| Key | Action |
|---|---|
| `W A S D` | Move / navigate |
| `E` | Interact / activate ID card special (boss) |
| `Enter` | Confirm / advance dialogue |
| `Space` | Next attack round (Boss 1) |
| `Escape` | Pause menu |
| `Y / N` | Yes/No choice prompts |

---

### Build Requirements

- Visual Studio 2022 (toolset v143), x64 target
- SDL2 all-in-one package at `D:\SDL2\msvc(VS)\SDL2-2.26.0-allinone\`  
  *(update paths in `SDL2_test.vcxproj` if installed elsewhere)*
- Required DLLs next to the executable: `SDL2.dll`, `SDL2_image.dll`, `SDL2_ttf.dll`, `SDL2_mixer.dll`
- Working directory must contain `assets/` and `Avatars/` folders

---

### Notes for Developers

- `Puzzle1.cpp` is an older standalone prototype kept for reference; **it is not compiled** (not listed in `.vcxproj`). The active game logic is entirely in `Main.cpp`.
- `SDL2_test.cpp` is fully commented out — legacy code only.
- `enter.h` contains full function definitions (not just declarations). **Do not include it in more than one `.cpp` file** or you will get linker duplicate-symbol errors.
- Map transitions call `Map_Shift()`, which also triggers `save()` — game is auto-saved on every map change.
- Window title randomly cycles between 6 "Illuminati: ..." subtitles every 30 seconds.
