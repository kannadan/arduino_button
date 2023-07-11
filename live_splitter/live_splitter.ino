#include <Keyboard.h>

const int buttonPin = 10;
int buttonState = HIGH;
int previousButtonState = HIGH;
const int debounceDelay = 50;  
int lastDebounceTime = millis();  
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && previousButtonState == HIGH && millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis(); 
    Serial.println("Button press");
    Keyboard.press(KEY_F20);
    delay(50); // Adjust the delay if needed
    Keyboard.release(KEY_F20);
    delay(550);
  }
  previousButtonState = buttonState;
}