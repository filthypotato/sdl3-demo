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
> git clone https://github.com/filthypotato/sdl3-demo.git
> ```

---

### Linux (Arch)

**1. Install dependencies**

```bash
sudo pacman -S sdl3 sdl3_image sdl3_mixer glm
```

**2. Build**

```bash
cmake -B build_linux -DCMAKE_BUILD_TYPE=Release
cmake --build build_linux
```

**3. Run**

```bash
./build_linux/sdl3-demo
```

---

### Windows

**1. Install the tools**

- [Visual Studio 2022](https://visualstudio.microsoft.com/) — during install, select the **Desktop development with C++** workload
- [CMake 3.21+](https://cmake.org/download/) — tick "Add to PATH" during install
- [Git](https://git-scm.com/download/win)

**2. Install vcpkg** (this manages the SDL3 libraries for you)

Open a terminal and run:

```powershell
git clone https://github.com/microsoft/vcpkg.git C:\vcpkg
C:\vcpkg\bootstrap-vcpkg.bat
```

Then set the environment variable so the build script can find it. Run this once in PowerShell as admin:

```powershell
[System.Environment]::SetEnvironmentVariable("VCPKG_ROOT", "C:\vcpkg", "Machine")
```

Restart your terminal after doing this.

**3. Install the libraries**

```powershell
C:\vcpkg\vcpkg.exe install sdl3 sdl3-image sdl3-mixer glm
```

This will take a few minutes the first time.

**4. Build**

In the `sdl3-demo` folder, run:

```powershell
.\build_win.ps1
```

If PowerShell says it can't run scripts, run this first then try again:

```powershell
Set-ExecutionPolicy -Scope CurrentUser RemoteSigned
```

**5. Run**

```
build_win\Release\sdl3-demo.exe
```

The build script also produces `sdl3-demo-windows.zip` in the project folder, which contains everything needed to share or run on another machine.

---

The binary finds its `resources/` folder relative to itself, so it runs correctly from any directory.
