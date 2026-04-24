$ErrorActionPreference = "Stop"

$buildDir = "build_win"

if (!(Test-Path $buildDir)) {
    New-Item -ItemType Directory -Path $buildDir | Out-Null
}

Set-Location $buildDir

if (!(Test-Path "CMakeCache.txt")) {
    cmake .. -G "Visual Studio 17 2022" -A x64
}

cmake --build . --config Release

Write-Host "`nBuild complete. Run: build_win\Release\sdl3-demo.exe"
