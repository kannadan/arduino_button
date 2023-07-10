#include <Keyboard.h>

const int buttonPin = 10;
int buttonState = HIGH;
int previousButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != previousButtonState) {
    Serial.println("Button pressed1!");
    if (buttonState == LOW) {
      Keyboard.press(KEY_F20);
      delay(50); // Adjust the delay if needed
      Keyboard.release(KEY_F20);
    }
    previousButtonState = buttonState;
  }
}