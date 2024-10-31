#include <HID-Project.h>
#include <HID-Settings.h>

// Author: bebeal
// Description: Connects to a teletype stream showing Star Wars in ASCII
// Title: StarWarsASCII
// Target: Windows

void setup()
{
  Keyboard.begin();
  delay(500);  // Allow USB to initialize

  // Open Run dialog
  Keyboard.press(KEY_LEFT_GUI);
  delay(100);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();

  delay(500);  // Ensure Run dialog opens

  // Open Command Prompt
  Keyboard.print("cmd");
  delay(300);
  Keyboard.write(KEY_ENTER);

  delay(1000);  // Wait for Command Prompt to open

  // Connect to Star Wars ASCII stream
  Keyboard.print("telnet towel.blinkenlights.nl");
  delay(200);
  Keyboard.write(KEY_ENTER);

  Keyboard.end();
}

void loop() {}
