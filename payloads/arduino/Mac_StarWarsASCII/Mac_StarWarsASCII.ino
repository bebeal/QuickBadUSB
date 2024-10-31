#include <HID-Project.h>
#include <HID-Settings.h>

// Author: bebeal
// Description: Connects to a teletype stream showing Star Wars in ASCII
// Title: StarWarsASCII
// Target: MacOS

void setup()
{
  Keyboard.begin();
  delay(500);  // Allow USB to initialize

  // Open Spotlight
  Keyboard.press(KEY_LEFT_GUI);
  delay(100);
  Keyboard.press(KEY_SPACE);
  delay(100);
  Keyboard.releaseAll();

  delay(500);  // Ensure Spotlight opens

  // Open Terminal
  Keyboard.print("terminal");
  delay(300);
  Keyboard.write(KEY_ENTER);
  
  delay(1000);  // Wait for Terminal to open

  // Connect to Star Wars ASCII stream
  Keyboard.print("nc towel.blinkenlights.nl 23");
  delay(200);
  Keyboard.write(KEY_ENTER);

  Keyboard.end();
}

void loop() {}
