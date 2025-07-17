#include <ECE3.h>

uint16_t sensorValues[8];
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
  Serial.println("loading");
  delay(5000);
  Serial.println("Value: ");
  ECE3_read_IR(sensorValues);
  pos = getPosition(sensorValues);
  Serial.println(pos);
}

int getPosition(uint16_t* values) {
  return ((((values[0] -527) / 1708) * 1000 * -15)
      + (((values[1] - 573) / 1927) * 1000 * -14)
      + (((values[2] - 550) / 1950) * 1000 * -12)
      + (((values[3] - 619) / 1881) * 1000 * -8)
      + (((values[4] - 708) / 1792) * 1000 * 8)
      + (((values[5] - 573) / 1927) * 1000 * 12)
      + (((values[6] - 527) / 1432) * 1000 * 14)
      + (((values[7] - 619) / 1881) * 1000 * 15))/ 8;
}