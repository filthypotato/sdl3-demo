# sdl3-demo

A 2D side-scrolling platformer/shooter demo built by following an SDL3 tutorial. Not original work — shared for reference and as a starting point for others learning SDL3.

Developed on Arch Linux and Windows using Neovim. Cross-platform fixes were added to get it running on Linux in addition to Windows.

## Controls

| Key | Action |
|-----|--------|
| A / D | Move left / right |
| Space | Jump |
| Q | Shoot |
| F10 | Toggle debug overlay |
| F11 | Toggle fullscreen |

---

## Just Want to Play?

Download the latest release from the [Releases](../../releases) page. Extract the zip and run `sdl3-demo.exe` (Windows) or `sdl3-demo` (Linux). No install required.

---

## Building from Source

### Important: Folder Name

If you download the source as a zip from GitHub, it will extract as `sdl3-demo-main`. **You must rename it to `sdl3-demo`** before building, otherwise CMake will not find the source files.

If you clone with git it will already be named correctly:

```bash
git clone git@github.com:filthypotato/sdl3-demo.git
```

### Dependencies

You need the following libraries installed before building:

- [SDL3](https://github.com/libsdl-org/SDL)
- [SDL3_image](https://github.com/libsdl-org/SDL_image)
- [SDL3_mixer](https://github.com/libsdl-org/SDL_mixer)
- [GLM](https://github.com/g-truc/glm)

#### Arch Linux

```bash
sudo pacman -S sdl3 sdl3_image sdl3_mixer glm
```

#### Windows

Install via [vcpkg](https://vcpkg.io/) or manually place the SDL3, SDL3_image, and SDL3_mixer development libraries somewhere CMake can find them.

### Building on Linux

From inside the `sdl3-demo` folder:

```bash
cmake -B build_linux -DCMAKE_BUILD_TYPE=Release
cmake --build build_linux
```

### Building on Windows

From inside the `sdl3-demo` folder in PowerShell:

```powershell
.\build_win.ps1
```

This requires CMake 3.21+ and Visual Studio 2022 with the C++ workload installed.

---

## Running

### Linux

```bash
./build_linux/sdl3-demo
```

### Windows

```
build_win\Release\sdl3-demo.exe
```

The binary can be run from any directory — it finds its assets automatically.
