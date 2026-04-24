# sdl3-demo

A 2D side-scrolling platformer/shooter built in C++20 using SDL3. Work done following an SDL3 tutorial — shared for learning purposes.

Built and edited using **Neovim** on Arch Linux and Windows.

---

## Gameplay

Run, jump, and shoot your way through a level full of shambling enemies. Enemies track you at close range, take damage, flash on hit, and die with a full death animation. Bullets have their own collision states and screen-edge culling. A parallax scrolling background reacts to your movement speed.

**Controls**

| Key | Action |
|-----|--------|
| A / D | Move left / right |
| Space | Jump |
| Q | Shoot |
| F10 | Toggle debug overlay |
| F11 | Toggle fullscreen |

---

## Tech

- **C++20** — unions, designated initializers, lambdas
- **SDL3** — window, renderer, input, vsync
- **SDL3_image** — PNG texture loading
- **SDL3_mixer** — WAV/MP3 audio with track-based looping music
- **GLM** — 2D vectors for position, velocity, acceleration
- Custom **animation**, **timer**, and **AABB collision** systems

---

## Just Want to Play?

Download the latest zip from the [Releases](../../releases) page, extract it, and run the binary. No install needed — everything is bundled.

---

## Building from Source

### Before You Start

> **Important:** If you downloaded the source as a zip from GitHub it will extract as `sdl3-demo-main`. You **must rename the folder to `sdl3-demo`** before building or CMake will not find the source files.
>
> Cloning with git avoids this entirely:
> ```bash
> git clone https://github.com/YOUR_USERNAME/sdl3-demo.git
> ```

### Dependencies

| Library | Arch Linux | Windows |
|---------|-----------|---------|
| SDL3 | `sudo pacman -S sdl3` | vcpkg or manual |
| SDL3_image | `sudo pacman -S sdl3_image` | vcpkg or manual |
| SDL3_mixer | `sudo pacman -S sdl3_mixer` | vcpkg or manual |
| GLM | `sudo pacman -S glm` | vcpkg or manual |

### Linux

```bash
cmake -B build_linux -DCMAKE_BUILD_TYPE=Release
cmake --build build_linux
./build_linux/sdl3-demo
```

### Windows

Requires Visual Studio 2022 (C++ workload) and CMake 3.21+.

```powershell
.\build_win.ps1
```

Binary will be at `build_win\Release\sdl3-demo.exe`. SDL3 DLLs are copied automatically alongside it.

---

The binary finds its `resources/` folder relative to itself, so it runs correctly from any directory.
