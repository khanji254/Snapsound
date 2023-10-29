/*This is a simple code that turns on the The LED Once when a sound is detected then turns it Off when the sound is detected again before resetting the count*/



const int soundSensorPin = 2;  // Digital pin for the sound sensor
const int ledPin = 13;         // Digital pin for the LED

int snapCount = 0;                         // Counter for snap detections
unsigned long lastSnapTime = 0;            // Time of the most recent snap detection
unsigned long lastClapTime = 0;            // Time of the most recent clap detection
const unsigned long debounceDelay = 200;   // Debounce delay in milliseconds
const unsigned long clapThreshold = 2000;  // Minimum time between claps in milliseconds

void setup() {
  pinMode(soundSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Snap counter is ready.");
}

void loop() {
  int soundValue = digitalRead(soundSensorPin);  // Read the digital value from the sound sensor
  unsigned long currentTime = millis();

  if (soundValue == HIGH) {  // Adjust this condition based on your sensor's behavior
    // Check if there's a debounce delay since the last snap
    if (currentTime - lastSnapTime >= debounceDelay) {
      snapCount++;  // Increment the snap count
      Serial.print("Snap detected! Total snaps: ");
      Serial.println(snapCount);
    }
    lastSnapTime = currentTime;

    // Update the last clap time for each clap detected
    lastClapTime = currentTime;
  }

  // Check if there's a 2-second gap since the most recent clap
  if (snapCount > 0 && snapCount < 2 ) {
    digitalWrite(ledPin, HIGH);  // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED
    snapCount = 0;
    
  }
}
