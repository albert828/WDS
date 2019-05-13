
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600,SERIAL_8E1);
}

uint8_t vertical = 0, horizontal = 255;
void loop() {
  // put your main code here, to run repeatedly:
  ++vertical;
  --horizontal;
  Serial.print("V");
  Serial.print(vertical);
  Serial.print(" H");
  Serial.print(horizontal);
  Serial.println();
  delay(500);
}
