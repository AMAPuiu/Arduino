const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
const int red_potPin = A0;
const int green_potPin = A1;
const int blue_potPin = A2;
int ledPin = 0;
int potPin = 0;
int ledValue = 0;
int potValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(red_potPin, INPUT);
  pinMode(green_potPin, INPUT);
  pinMode(blue_potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  setColor(redPin, red_potPin, potValue, ledValue);
  setColor(greenPin, green_potPin, potValue, ledValue);
  setColor(bluePin, blue_potPin, potValue, ledValue);
}
void setColor(const int ledPin,const int potPin, int potValue, int ledValue){
 potValue = analogRead(potPin);
 ledValue = map(potValue, 0, 1023, 0, 255);
 analogWrite(ledPin, ledValue);
}
