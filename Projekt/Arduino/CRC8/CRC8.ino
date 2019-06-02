char CRC8(const char*,int);

const char text[] = "hello";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600,SERIAL_8E1);
}

uint8_t H = 0, V = 0, L = 0, I = 0, U = 0, P = 0, CRC = 0;
String data;
void loop() {
  ++H; ++V; ++L; ++I, ++U, ++P;
  data = String("H");
  data += String(H, DEC);
  data += String(" V");
  data += String(V, DEC);
  data += String(" L");
  data += String(L, DEC);
  data += String(" U");
  data += String(U, DEC);
  data += String(" I");
  data += String(I, DEC);
  data += String(" P");
  data += String(P, DEC);

  CRC = CRC8(data.c_str(), data.length());
  data += String(" CRC");
  data += String(CRC, DEC);
  data += '\n';
  Serial.print(data);
  delay(1000);
}

char CRC8(const char *data,int len) 
{
   char crc = 0x00;
   char extract;
   char sum;
   for(int i=0;i<len;i++)
   {
      extract = *data;
      for (char tempI = 8; tempI; tempI--) 
      {
         sum = (crc ^ extract) & 0x01;
         crc >>= 1;
         if (sum)
            crc ^= 0x8C;
         extract >>= 1;
      }
      data++;
   }
   return crc;
}
