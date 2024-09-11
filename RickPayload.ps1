# Define a function to adjust system volume using the Windows API
Add-Type -TypeDefinition @"
using System;
using System.Runtime.InteropServices;

[Guid("5CDF2C82-841E-4546-9722-0CF74078229A"),
InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAudioEndpointVolume
{
    // Method to set the system volume (0.0 is mute, 1.0 is full volume)
    int SetMasterVolumeLevelScalar(float fLevel, System.Guid pguidEventContext);
}

[Guid("1CB9AD4C-DBFA-4c32-B178-C2F568A703B2"),
InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IAudioClient
{
    // Some IAudioClient methods go here if needed
}

[Guid("A95664D2-9614-4F35-A746-DE8DB63617E6")]
public class MMDeviceEnumerator
{
}

public class AudioUtilities
{
    public static void SetVolume(float level)
    {
        // Create a device enumerator
        var enumerator = (IMMDeviceEnumerator)(new MMDeviceEnumerator());
        IMMDevice device;
        enumerator.GetDefaultAudioEndpoint(0, 1, out device);

        // Activate the audio endpoint volume interface
        IAudioEndpointVolume volume = (IAudioEndpointVolume)device.Activate(
            typeof(IAudioEndpointVolume).GUID, 0, IntPtr.Zero);

        // Set the volume (from 0.0 to 1.0)
        volume.SetMasterVolumeLevelScalar(level, Guid.Empty);
    }
}

[ComImport, Guid("A95664D2-9614-4F35-A746-DE8DB63617E6")]
public interface IMMDeviceEnumerator
{
    int GetDefaultAudioEndpoint(int dataFlow, int role, out IMMDevice ppDevice);
}

[ComImport, Guid("D666063F-1587-4E43-81F1-B948E807363F")]
public interface IMMDevice
{
    int Activate([MarshalAs(UnmanagedType.LPStruct)] Guid iid, int dwClsCtx, IntPtr pActivationParams, [MarshalAs(UnmanagedType.IUnknown)] out object ppInterface);
}
"@

# Set the system volume to 100% (1.0 is full volume)
[AudioUtilities]::SetVolume(1.0)

# Wait for a second to ensure volume is adjusted
Start-Sleep -Seconds 1


Start-Process "C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe" "https://www.youtube.com/watch?v=dQw4w9WgXcQ"
