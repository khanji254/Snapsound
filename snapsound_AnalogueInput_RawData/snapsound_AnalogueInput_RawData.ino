const int soundSensorPin = A0; // Analog input pin for the sound sensor

void setup() {
  Serial.begin(9600); // Start Serial communication
}

void loop() {
  int soundValue = analogRead(soundSensorPin); // Read the sound sensor value
  Serial.println(soundValue); // Print the value to the Serial Plotter
  delay(100); // Add a small delay to control the data rate
}
