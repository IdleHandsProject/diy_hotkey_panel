/*
  DIY Arcade HotKey

  Modififed version of the KeyboardReprogram firmware -
  http://www.arduino.cc/en/Tutorial/KeyboardReprogram

  Allows you to set different buttons to be hotkeys for the computer.

*/

#include "Keyboard.h"

// use this option for OSX.
// Comment it out if using Windows or Linux:
//char ctrlKey = KEY_LEFT_GUI;
// use this option for Windows and Linux.
// leave commented out if using OSX:
char ctrlKey = KEY_LEFT_CTRL;
char altKey = KEY_LEFT_ALT;

int buttonNum[5] = {3, 4, 2, 0, 1};
int buttSelect = 0;
int buttFlag = 0;
void setup() {

  Serial.begin(115200);
  for (int x = 0; x < 5; x++) {
    pinMode(buttonNum[x], INPUT_PULLUP);
    attachInterrupt(buttonNum[x], buttPressed, LOW);
  }

  Keyboard.begin();
}

void loop() {
  while (buttFlag == 0) {
    delay(10);
  }
  Serial.print("Button ");
  Serial.print(buttSelect);
  Serial.println(" pressed.");
  switch (buttSelect) {
    case 0:
      Command0();
      break;
    case 1:
      Command1();
      break;
    case 2:
      Command2();
      break;
    case 3:
      Command0();
      break;
    case 4:
      Command1();
      delay(1000);
      Command2();
      break;
    default:
      break;
  }
  int pressed = digitalRead(buttSelect);
  while (pressed == 0) {
    pressed = digitalRead(buttSelect);
  }

  buttFlag = 0;
}

void buttPressed() {
  buttFlag = 1;
  for (int x = 0; x < 5; x++) {
    int butt = digitalRead(x);
    if (butt == LOW) {
      buttSelect = x;
      break;
    }
  }
}

//Add your own Hot-Key combinations below.


//Upload to Arduino
void Command0() {
  Serial.println("Pressing CTRL+U");
  Keyboard.press(ctrlKey);
  Keyboard.press('u');
  delay(100);
  Keyboard.releaseAll();

  delay(500);
}

void Command1() {
  Serial.println("Pressing CTRL+ALT+N");
  Keyboard.press(ctrlKey);
  Keyboard.press(altKey);
  Keyboard.press('n');
  delay(100);
  Keyboard.releaseAll();

  delay(500);
}

void Command2() {
  Keyboard.println("HelloWorld");
  }
void Command3() {}

void Command4() {}




