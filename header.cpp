#pragma once

#include <stdio.h>
#include <wiringPy.h>
#include <softPwm.h>


#define IN1_PIN     1   // Motor pins
#define IN2_PIN     4
#define IN3_PIN     5
#define IN4_PIN     6

#define LEFT_IR_PIN     27  // IR sensor -> Top
#define RIGHT_IR_PIN    26

#define LEFT_TRACER_PIN     10  //IR tracer pins -> Bottom
#define RIGHT_TRACER_PIN    11

#define MAX_SPEED   50
#define MIN_SPEED   0

void motor_init () {
    digitalWrite(1, HIGH);
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH);
}

void go_forward () {
    digitalWrite(1, HIGH); 
    digitalWrite(4, LOW); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, LOW);
}

void go_back () {
    digitalWrite(4, HIGH); 
    digitalWrite(1, LOW); 
    digitalWrite(6, HIGH); 
    digitalWrite(5, LOW);
}

void go_right () {
    digitalWrite(1, HIGH); 
    digitalWrite(4, LOW); 
    digitalWrite(6, HIGH); 
    digitalWrite(5, LOW);
}

void go_left() {
    digitalWrite(4, HIGH); 
    digitalWrite(1, LOW); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, LOW);
}

void stop() {
    digitalWrite(1, LOW);  
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW);
}


void pwm_motor_init()
{
	pinMode(IN1_PIN, SOFT_PWM_OUTPUT);
	pinMode(IN2_PIN, SOFT_PWM_OUTPUT);
	pinMode(IN3_PIN, SOFT_PWM_OUTPUT);
	pinMode(IN4_PIN, SOFT_PWM_OUTPUT);
}

void pwm_go_forward(int speed){
	softPwmWrite(IN1_PIN, speed);
	softPwmWrite(IN2_PIN, MIN_SPEED);
	softPwmWrite(IN3_PIN, speed);
	softPwmWrite(IN4_PIN, MIN_SPEED);
}

void pwm_go_back(int speed){
	softPwmWrite(IN1_PIN, MIN_SPEED);
	softPwmWrite(IN2_PIN, speed);
	softPwmWrite(IN3_PIN, MIN_SPEED);
	softPwmWrite(IN4_PIN, speed);
}

void pwm_left(int gspeed){
	softPwmWrite(IN1_PIN, MIN_SPEED);
	softPwmWrite(IN2_PIN, speed);
	softPwmWrite(IN3_PIN, speed);
	softPwmWrite(IN4_PIN, MIN_SPEED);
}

void pwm_right(int speed){
	softPwmWrite(IN1_PIN, speed);
	softPwmWrite(IN2_PIN, MIN_SPEED);
	softPwmWrite(IN3_PIN, MIN_SPEED);
	softPwmWrite(IN4_PIN, speed);
}

void pwm_stop() {
	softPwmWrite(IN1_PIN, MIN_SPEED);
	softPwmWrite(IN2_PIN, MIN_SPEED);
	softPwmWrite(IN3_PIN, MIN_SPEED);
	softPwmWrite(IN4_PIN, MIN_SPEED);
}
