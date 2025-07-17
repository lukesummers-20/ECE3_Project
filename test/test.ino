#include <ECE3.h>

uint16_t sensorValues[8];
float sensorFloats[8];
int pos;

int getPosition(uint16_t* values);

void setup() {
  // put your setup code here, to run once:
  ECE3_Init();
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  ECE3_read_IR(sensorValues);
  pos = getPosition(sensorValues);
  Serial.println(pos);
}

int getPosition(uint16_t* values) {
  return (((((values[0] -527) * 1000 * -15) / 1708)
      + (((values[1] - 573.0) * 1000 * -14.0) / 1927)
      + (((values[2] - 550)  * 1000 * -12) / 1950)
      + (((values[3] - 619)  * 1000 * -8) / 1881)
      + (((values[4] - 708)  * 1000 * 8) / 1792)
      + (((values[5] - 573)  * 1000 * 12) / 1927)
      + (((values[6] - 527)  * 1000 * 14) / 1432)
      + (((values[7] - 619)  * 1000 * 15) / 1881))/ 8) - 250;
}