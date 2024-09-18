#include <Keyboard.h>

void setup() {
  // Start the keyboard emulation
  Keyboard.begin();

  // Short delay before starting the sequence
  delay(500);

  // Open Run dialog (Windows + R)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(500);
  Keyboard.releaseAll();

  // Wait for Run dialog to open
  delay(500);

  // Type "msedge.exe" to open Microsoft Edge
  Keyboard.print("msedge.exe");
  delay(500);

  // Press Enter to execute the command
  Keyboard.press(KEY_RETURN);
  delay(500);
  Keyboard.releaseAll();

  // Wait for Edge to open
  delay(1000);

  // Type the URL
  Keyboard.print("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
  delay(500);

  // Press Enter to navigate to the URL
  Keyboard.press(KEY_RETURN);
  delay(500);
  Keyboard.releaseAll();

  // End the keyboard emulation
  Keyboard.end();
}

void loop() {
  // Do nothing in loop
}
