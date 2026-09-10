param(
    [Parameter(Mandatory = $true)]
    [ValidateSet("linear", "pointers", "modular")]
    [string]$Version
)

$ErrorActionPreference = "Stop"

$repoRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$exePath = Join-Path $repoRoot "build\$Version.exe"
$dataDir = Join-Path $repoRoot "run-data\$Version"

if (!(Test-Path $exePath)) {
    Write-Host "ERROR: $Version.exe was not found."
    Write-Host "Run .\build.ps1 first."
    exit 1
}

if (!(Test-Path $dataDir)) {
    New-Item -ItemType Directory -Path $dataDir -Force | Out-Null
}

Push-Location $dataDir
try {
    & $exePath
}
finally {
    Pop-Location
}
