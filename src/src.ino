#include <ECE3.h>

const int left_p = -1;
const int right_p = 1;
const int left_d = 1;
const int right_d = 1;
const int forward = HIGH;
const int backward = LOW;
const int speed = 50;
int position = 0;
int last_position = 0;
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

  ECE3_Init();
  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  position = getPosition(sensorValues);
  analogWrite(left_pwm_pin, speed + (position * left_p));
  analogWrite(right_pwm_pin,speed + (position * right_p));
  // analogWrite(left_pwm_pin, speed + (position * left_p) + ((position - last_position) * left_d));
  // analogWrite(right_pwm_pin, speed + (position * right_p) + ((position - last_position) * right_d));
}
