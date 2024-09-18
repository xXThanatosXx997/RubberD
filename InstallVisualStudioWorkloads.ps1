$vsInstallerPath = "C:\Program Files (x86)\Microsoft Visual Studio\Installer\vs_installer.exe"
if (-Not (Test-Path $vsInstallerPath)) {
    Write-Host "Visual Studio Installer not found. Please make sure Visual Studio is installed."
    exit 1
}
Start-Process -FilePath $vsInstallerPath -ArgumentList `
    "modify --installPath `""C:\Program Files\Microsoft Visual Studio\2022\Community`" --add Microsoft.VisualStudio.Workload.NetCoreTools --add Microsoft.VisualStudio.Workload.Game --includeRecommended --passive --norestart" `
    -Wait
Write-Host "Installation of .NET Development Pack and Unity Development Pack complete!"
