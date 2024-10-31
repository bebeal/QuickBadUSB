#include <HID-Project.h>
#include <HID-Settings.h>

// Author: bebeal
// Description: Produces matrix rain effect on MacOS using cmatrix (via Homebrew)
// Title: MatrixRain
// Target: MacOS

void setup()
{
  Keyboard.begin();
  delay(500);  // Wait for USB initialization

  // Open Spotlight with precise timing for macOS
  Keyboard.press(KEY_LEFT_GUI); // Press Command
  delay(100);  // Add delay to ensure Command is registered
  Keyboard.press(KEY_SPACE);    // Press Space for Spotlight
  delay(100);  // Hold both keys
  Keyboard.releaseAll();        // Release both keys

  delay(500);  // Wait for Spotlight to open

  // Open Terminal
  Keyboard.print("terminal.app");
  delay(300);  // Wait for input to register
  Keyboard.write(KEY_ENTER);
  
  delay(1000);  // Wait for Terminal to open

  // Stop any running command in Terminal
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('c');
  Keyboard.releaseAll();

  delay(200);

  // Navigate to home directory
  Keyboard.print("cd ~");
  delay(200);
  Keyboard.write(KEY_ENTER);

  delay(200);

  // Install cmatrix using Homebrew
  Keyboard.print("brew install cmatrix");
  delay(200);
  Keyboard.write(KEY_ENTER);

  delay(5000);  // Wait for installation

  // Run cmatrix
  Keyboard.print("cmatrix");
  delay(200);
  Keyboard.write(KEY_ENTER);

  Keyboard.end();
}

void loop() {}
