$ErrorActionPreference = "Stop"

$buildDir = "build_win"

# Create folder if missing
if (!(Test-Path $buildDir)) {
    New-Item -ItemType Directory -Path $buildDir | Out-Null
}

Set-Location $buildDir

Write-Host "== Configuring =="

cmake .. -G "Visual Studio 17 2022" -A x64

if ($LASTEXITCODE -ne 0) {
    Write-Error "CMake configure failed"
    exit 1
}

Write-Host "== Building =="

cmake --build . --config Release

if ($LASTEXITCODE -ne 0) {
    Write-Error "Build failed"
    exit 1
}

Write-Host "== Packaging =="

$releaseDir = "Release"
$zipName = "..\sdl3-demo-windows.zip"

if (Test-Path $zipName) {
    Remove-Item $zipName
}

Compress-Archive -Path "$releaseDir\*" -DestinationPath $zipName

Write-Host "`nBuild complete. Release zip: sdl3-demo-windows.zip"
