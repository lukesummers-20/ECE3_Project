#include <ECE3.h>

const int max_pos = 2260;
const int left_p = -80;
const int right_p = 80;
const int left_d = 0;
const int right_d = 0;
const int forward = LOW;
const int backward = HIGH;
const int speed = 20;
const int min_speed = 20;
const int max_speed = 60;
int position = 0;
int last_position = 0;
uint16_t center[8] = ??;
uint16_t sensorValues[8];
const int left_nslp_pin=31; // nslp ==> awake & ready for PWM
const int left_dir_pin=29;
const int left_pwm_pin=40;
const int right_nslp_pin=11;
const int right_dir_pin=30;
const int right_pwm_pin=39;

void setup() {
  // put your setup code here, to run once:
  pinMode(left_nslp_pin,OUTPUT);
  pinMode(left_dir_pin,OUTPUT);
  pinMode(left_pwm_pin,OUTPUT);
  pinMode(right_nslp_pin,OUTPUT);
  pinMode(right_dir_pin,OUTPUT);
  pinMode(right_pwm_pin,OUTPUT);

  digitalWrite(left_nslp_pin,HIGH);
  digitalWrite(right_nslp_pin,HIGH);
  digitalWrite(left_dir_pin,forward);
  digitalWrite(right_dir_pin,forward);

  last_position = getPosition(sensorValues);
  ECE3_Init();
  Serial.begin(9600);
  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  position = getPosition(sensorValues);
  if ((position == 0) && (speed < max_speed)) {
    speed += 5;
  } else if (speed > min_speed) {
    speed -= 5;
  }
  analogWrite(left_pwm_pin, speed + ((position / max_pos) * left_p) + ((position - last_position) * left_d));
  analogWrite(right_pwm_pin, speed + ((position / max_pos) * right_p) + ((position - last_position) * right_d));
  last_position = position;
  // delay(1000);
  // Serial.println(position);
}
