#include "Arduino.h"

#include <Wire.h>
#include <NXShield.h>
#include <NXTTouch.h>

#include <ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Empty.h>

ros::NodeHandle  nh;

NXShield    nxshield;
NXTTouch    touch;

const int led = 13;
boolean touch_status;
boolean last_status;

void motor_a1_speed(const std_msgs::UInt16& speed_msg){
  nxshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Forward, speed_msg.data);
}
ros::Subscriber<std_msgs::UInt16> motor_a1_speed_sub("motor_a1_speed", motor_a1_speed);

void motor_a1_brake(const std_msgs::Empty& brake_msg){
  nxshield.bank_a.motorStop(SH_Motor_1, SH_Next_Action_Brake);
}
ros::Subscriber<std_msgs::Empty> motor_a1_brake_sub("motor_a1_brake", motor_a1_brake);

std_msgs::Bool pushed_msg;
ros::Publisher button_pub("pushed", &pushed_msg);

void led_on(const std_msgs::Empty& led_on_msg){
  digitalWrite(led, HIGH);
}
ros::Subscriber<std_msgs::Empty> led_on_sub("led_on", &led_on);

void led_off(const std_msgs::Empty& led_off_msg){
  digitalWrite(led, LOW);
}
ros::Subscriber<std_msgs::Empty> led_off_sub("led_off", &led_off);



void setup(){
  pinMode(led, OUTPUT);  

  // ros node
  nh.initNode();
  nh.subscribe(motor_a1_speed_sub);
  nh.subscribe(motor_a1_brake_sub);
  nh.advertise(button_pub);
  nh.subscribe(led_on_sub);
  nh.subscribe(led_off_sub);
  
  // Initialize the protocol for NXShield
  nxshield.init( SH_HardwareI2C );
  
  // reset motors
  nxshield.bank_a.motorReset();  
  nxshield.bank_b.motorReset();
  
  // initialize the analog sensors
  touch.init( &nxshield, SH_BBS1 );
}

void loop(){
  nh.spinOnce();
  
  touch_status = touch.isPressed();
  
  if ( touch_status != last_status ) {
      pushed_msg.data = touch_status;
      button_pub.publish(&pushed_msg);
      last_status = touch_status;
  }
  
  delay(10);
}
