# sdl3-demo

A 2D side-scrolling platformer/shooter demo built by following an SDL3 tutorial. Not original work — shared for reference and as a starting point for others learning SDL3.

Developed on Arch Linux and Windows using Neovim. Cross-platform fixes were added to get it running on Linux in addition to Windows.

## Features

- Parallax scrolling background
- Sprite animation system
- AABB collision detection
- Enemy AI with damage/death states
- Audio via SDL3_mixer (music + sound effects)
- Debug overlay (F10)
- Fullscreen toggle (F11)

## Controls

| Key | Action |
|-----|--------|
| A / D | Move left / right |
| Space | Jump |
| Q | Shoot |
| F10 | Toggle debug overlay |
| F11 | Toggle fullscreen |

## Dependencies

- [SDL3](https://github.com/libsdl-org/SDL)
- [SDL3_image](https://github.com/libsdl-org/SDL_image)
- [SDL3_mixer](https://github.com/libsdl-org/SDL_mixer)
- [GLM](https://github.com/g-truc/glm)

### Arch Linux

```bash
sudo pacman -S sdl3 sdl3_image sdl3_mixer glm
```

### Windows

Install dependencies via vcpkg or manually place SDL3, SDL3_image, and SDL3_mixer development libraries where CMake can find them.

## Building

### Linux

```bash
cmake -B build_linux -DCMAKE_BUILD_TYPE=Release
cmake --build build_linux
./build_linux/sdl3-demo
```

### Windows

```powershell
.\build_win.ps1
```

The binary will be at `build_win\Release\sdl3-demo.exe`.

The binary can be run from any directory — it finds its assets relative to its own location.
