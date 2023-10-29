const int soundSensorPin = 8;  // Digital pin for sound sensor
const int ledPin = 13;         // Digital pin for the LED
bool ledState = false;         // To track the LED state

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(soundSensorPin, INPUT);  // Set the sound sensor pin as an input
  Serial.begin(9600);
}

void loop() {
  int soundLevel = digitalRead(soundSensorPin); // Read the sound sensor value

  Serial.print("Sound Level: ");
  Serial.println(soundLevel);

  if (soundLevel) {
    if (!ledState) {
      digitalWrite(ledPin, HIGH);  // Turn on the LED
      ledState = true;
      Serial.println("Sound detected! LED on.");
    }
  } else {
    if (ledState) {
      digitalWrite(ledPin, LOW);  // Turn off the LED
      ledState = false;
      Serial.println("No sound detected. LED off.");
    }
  }
}
