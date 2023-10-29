/*  This code basically increments the number of times the LED Blinks depending on the number of claps or snaps detected. 
It des not reset the snap count and thus, it is basically an incremental counter. Use this code as you wish as it is mostly ChatGPT Generated */

const int soundSensorPin = 2;  // Digital pin for the sound sensor
const int ledPin = 13;        // Digital pin for the LED

int snapCount = 0;            // Counter for snap detections

void setup() {
  pinMode(soundSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int soundValue = digitalRead(soundSensorPin); // Read the digital value from the sound sensor

  if (soundValue == HIGH) {  // Adjust this condition based on your sensor's behavior
    snapCount++;  // Increment the snap count
    Serial.print("Snap detected! Total snaps: ");
    Serial.println(snapCount);

    // Blink the LED based on the snap count
    for (int i = 0; i < snapCount; i++) {
      digitalWrite(ledPin, HIGH);  // Turn on the LED
      delay(500);  // LED on time
      digitalWrite(ledPin, LOW);   // Turn off the LED
      delay(500);  // LED off time
    }
  }

  // Serial print the snap count
  Serial.print("Snap count: ");
  Serial.println(snapCount);
}
