#include "pitches.h"

const int activeBuzzerPin = 11;
const int passiveBuzzerPin = A0 ;
const int pushButton = 2;

int buttonState = HIGH;
int passiveBuzzerValue = 0;


const int threshold = 1;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
int waitTime = 5000;

int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
  };
int noteDurations[] = {
4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
pinMode(passiveBuzzerPin, INPUT);
pinMode(activeBuzzerPin, OUTPUT);
pinMode(pushButton, INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
  
  passiveBuzzerValue = analogRead(passiveBuzzerPin);
  
  if (passiveBuzzerValue > threshold) {
    Serial.println("Knock");
    while(millis() - previousMillis < waitTime){
    }
    currentMillis = millis();
    if(millis() - previousMillis >= waitTime){
      previousMillis = currentMillis;
      buttonState = digitalRead(pushButton);
      while(buttonState == HIGH){
        buttonState = sing(activeBuzzerPin); 
      }
      buttonState = HIGH;
    }
    
  }

}

int sing(const int activeBuzzerPin){
  int buttonState = HIGH;
  for (int thisNote = 0; thisNote < 8 && buttonState == HIGH; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(activeBuzzerPin, melody[thisNote], noteDuration);
  
    int pauseBetweenNotes = noteDuration * 1.30;
    unsigned long beforePause = millis();
    while(millis() - beforePause < pauseBetweenNotes){
    }
 
    noTone(8);
    buttonState = digitalRead(pushButton);
  }
  return buttonState;
}
