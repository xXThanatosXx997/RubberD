#include <Keyboard.h>

// Function to simulate pressing Windows key, typing a number, and pressing Enter
void runProgram(const char *programName) {
  // Press the Windows key
  Keyboard.press(KEY_LEFT_GUI);  // Press Windows Key (Left GUI key)
  delay(200);
  Keyboard.release(KEY_LEFT_GUI); // Release the Windows Key
  
  delay(500);  // Wait for the Start menu to open
  
  // Type the program name (in this case, "1", "2", or "3")
  Keyboard.print(programName);
  
  delay(500);  // Wait for typing to complete
  
  // Press Enter to run the program
  Keyboard.press(KEY_RETURN);  // Press Enter
  delay(100);
  Keyboard.release(KEY_RETURN);  // Release Enter key
}

// Program 1 - Simulate Windows key + type "1"
void runProgram1() {
  runProgram("1");  // Replace with typing "1"
}

// Program 2 - Simulate Windows key + type "2"
void runProgram2() {
  runProgram("2");  // Replace with typing "2"
}

// Program 3 - Simulate Windows key + type "3"
void runProgram3() {
  runProgram("3");  // Replace with typing "3"
}

void setup() {
  // Initialize the Keyboard
  Keyboard.begin();
  delay(500); // Wait for the PC to recognize the device
}

void loop() {
  // Wait until any key is pressed
  if (Serial.available() > 0) {
    char keyPressed = Serial.read(); // Read the key

    // Check which function key was pressed
    if (keyPressed == KEY_F1) {
      runProgram1();  // F1 key triggers typing "1"
    } else if (keyPressed == KEY_F2) {
      runProgram2();  // F2 key triggers typing "2"
    } else if (keyPressed == KEY_F3) {
      runProgram3();  // F3 key triggers typing "3"
    }
  }

  delay(100); // Short delay to prevent the loop from running too quickly
}
