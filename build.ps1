$ErrorActionPreference = "Stop"

$compiler = $null

if (Get-Command g++ -ErrorAction SilentlyContinue) {
    $compiler = "g++"
}
elseif (Test-Path "C:\msys64\ucrt64\bin\g++.exe") {
    $compiler = "C:\msys64\ucrt64\bin\g++.exe"
}
else {
    Write-Host "ERROR: g++ compiler was not found."
    Write-Host "Install MinGW-w64/MSYS2 or add g++ to PATH."
    exit 1
}

Write-Host "Compiler: $compiler"

if (!(Test-Path "build")) {
    New-Item -ItemType Directory -Path "build" | Out-Null
}

Write-Host "Building linear version..."
& $compiler "lab1\linear.cpp" -o "build\linear.exe"
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "Building pointer version..."
& $compiler "lab1\pointers.cpp" -o "build\pointers.exe"
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "Building modular version..."
& $compiler "modular\main.cpp" "modular\functions.cpp" -o "build\modular.exe"
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host ""
Write-Host "Build completed successfully."
Write-Host ""
Write-Host "Run each version with isolated data:"
Write-Host ".\run.ps1 linear"
Write-Host ".\run.ps1 pointers"
Write-Host ".\run.ps1 modular"
