const int dry = 580;
const int wet = 260;
const int relay = 12;

void setup() {
  pinMode(relay, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int sensorVal = analogRead(A0);
  Serial.println(sensorVal);
  int percentageHumidity = map(sensorVal, wet, dry, 100, 0);

  Serial.print(percentageHumidity);
  Serial.println("%");  

  if (percentageHumidity < 25){
    digitalWrite(relay, HIGH);
    delay(5000); // wait 5 seconds
    digitalWrite(relay, LOW);
  }

  delay(30000); //scan every 30 seconds
 
}
