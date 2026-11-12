# my_sokoban

A Sokoban puzzle game written in C, playable in the terminal (ncurses) or in a window (CSFML).

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![ncurses](https://img.shields.io/badge/ncurses-333333?style=flat&logo=gnubash&logoColor=white)
![CSFML](https://img.shields.io/badge/CSFML-8CC445?style=flat&logo=sfml&logoColor=white)
![Epitech](https://img.shields.io/badge/Epitech-1st%20year-0B5AB4?style=flat)

> Epitech project · 1st year (2024–2025) · Solo project

## About

The player pushes boxes (`X`) onto storage locations (`O`) in a warehouse. The game is won when every box is stored, and lost when no box can be moved anymore. The mandatory part of the project is the ncurses version; I added a graphical CSFML mode, sounds and a random map generator on top of it.

## Features

- Terminal mode with ncurses, centred map and a "window too small" warning
- Graphical mode with CSFML (`-csfml`), with cell size adapted to large maps
- Random map generation (`-r`)
- Win and lose detection
- Move counter and timer
- Sound effects for footsteps, collisions and victory
- Map reset at any time

## Screenshots

![CSFML mode](https://github.com/user-attachments/assets/e4194157-bd5e-45da-bb55-31d0e8bc7c89)
![Terminal mode](https://github.com/user-attachments/assets/72d845f0-33be-4807-96dd-08023157e757)

## Getting started

### Requirements

- GCC and Make
- ncurses (on Debian/Ubuntu: `sudo apt install libncurses-dev`)
- [CSFML](https://www.sfml-dev.org/download/csfml/) (on Debian/Ubuntu: `sudo apt install libcsfml-dev`)

### Build

```bash
make
```

### Usage

```bash
./my_sokoban map.txt            # terminal mode
./my_sokoban map.txt -csfml     # graphical mode
./my_sokoban -r -csfml          # random map, graphical mode
./my_sokoban -h                 # print the usage
```

### Map format

| Character | Meaning |
|-----------|---------|
| `#` | Wall |
| `P` | Player |
| `X` | Box |
| `O` | Storage location |
| ` ` | Floor |

```
############
#      X O #
#   P   ####
#          #
#######    #
#    ##    #
#    ##    #
#    X     #
#          #
# O     #  #
############
```

## Controls

| Key | Action |
|-----|--------|
| Arrow keys | Move the player |
| `Space` | Reset the map |
| `q` | Quit |

## Project structure

```
.
├── src/
│   ├── map/              # map loading, checks and display
│   ├── map_generation/   # random map generator
│   ├── player/           # movement and box pushing
│   ├── csfml/            # graphical mode
│   └── error_handling/   # arguments, map and sound checks
├── include/              # headers
├── lib/my/               # C utility library (libmy, my_printf)
└── assets/               # textures, sounds and font
```

## Author

- Thomas Pezé ([@Thomas-Peze28](https://github.com/Thomas-Peze28))
