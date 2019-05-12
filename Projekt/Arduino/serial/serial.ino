void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600,SERIAL_8E1);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Test");
  delay(500);
}
