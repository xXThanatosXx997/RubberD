#include <Keyboard.h>

void setup() {
  // Start the Keyboard communication
  Keyboard.begin();
  
  // Wait a second for the system to get ready
  delay(1000);

  // Open the Run dialog (Windows + R)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(500);
  Keyboard.releaseAll();

  // Type the Blender download URL
  typeText("https://www.blender.org/download/release/Blender4.2/blender-4.2.1-windows-x64.msi/");
  Keyboard.press(KEY_RETURN);  // Press Enter
  delay(5000);  // Wait for the browser to open and download to begin

  // Delay to allow for the download (adjust this for the speed of the download)
  delay(20000);

  // Open Run dialog again (Windows + R) to execute the installer
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(500);
  Keyboard.releaseAll();

  // Navigate to the Downloads folder and run the downloaded installer
  // Adjust the path according to your environment
  typeText("C:\\Users\\Admin\\Downloads\\blender-4.2.1-windows-x64.msi");
  Keyboard.press(KEY_RETURN);  // Press Enter
  
}

void loop() {
  // The loop is empty because we only need to run the script once
}

// Function to type a string of text
void typeText(const char *str) {
  while (*str) {
    Keyboard.write(*str);
    str++;
    delay(50);  // Small delay between each character for safety
  }
}
