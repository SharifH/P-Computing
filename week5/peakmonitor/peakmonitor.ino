int threshold = 500;
int lastReading = 0;
int reallyOldReading = 0;
int noise = 6;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor = analogRead(A0);
  //  Serial.println(sensor)

  if (sensor > threshold) {
    if ((reallyOldReading < lastReading + noise) && (sensor + noise < lastReading < 0)) {
      int peak = lastReading;
      Serial.print("The peak is: ");
      Serial.println(peak);
    }
  }
  reallyOldReading = lastReading;
  lastReading = sensor;
}
