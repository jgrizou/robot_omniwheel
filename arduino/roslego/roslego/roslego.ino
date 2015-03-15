#include "Arduino.h"

// debug only slow down everything
//#include <SoftwareSerial.h>
//SoftwareSerial debugSerial(11, 10); // RX, TX

//NXSHIELD
#include <Wire.h>
#include <NXShield.h>
#include <NXTTouch.h>

NXShield    nxshield;
NXTTouch    touch_1;
NXTTouch    touch_2;

//ROS
#include <ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Int32.h>
#include <roslego/motor_action.h>
#include <roslego/ahrs.h>

ros::NodeHandle  nh;

/* variable */
int loop_delay = 200;

boolean last_1_status;
boolean last_2_status;

int last_motor_1_position;
int last_motor_2_position;
int last_motor_3_position;
int last_motor_4_position;

int last_battery_voltage;

//IMU
int s;
int e;
char charBuf[10];  
String strBuf = "";
String inputAHRS = ""; // a string to hold incoming data


/* ROS subscriber & callback */
void set_loop_delay(const std_msgs::UInt16& loop_delay_msg){
  loop_delay = loop_delay_msg.data;
}
ros::Subscriber<std_msgs::UInt16> set_loop_delay_sub("set_loop_delay", set_loop_delay);


void force_all_publish(const std_msgs::Empty& msg){
  last_1_status = !touch_1.isPressed();
  last_2_status = !touch_2.isPressed();

  last_motor_1_position = last_motor_1_position + 1;
  last_motor_2_position = last_motor_2_position + 1;
  last_motor_3_position = last_motor_3_position + 1;
  last_motor_4_position = last_motor_4_position + 1;
  
  last_battery_voltage = last_battery_voltage + 1;
}
ros::Subscriber<std_msgs::Empty> force_all_publish_sub("force_all_publish", force_all_publish);


void motor_action(const roslego::motor_action& action_msg){
  int motor_id = action_msg.motor_id;
  int option = action_msg.option;
  int value = action_msg.value;
  int speed = action_msg.speed;
  boolean direction = action_msg.direction;
  
  //motor nb on bank
  SH_Motor motor;
  if (motor_id % 2){
    motor = SH_Motor_1;
  }else{
    motor = SH_Motor_2;
  }
  //direction
  SH_Direction dir;
  if (direction == true){
    dir = SH_Direction_Forward;
  }else{
    dir = SH_Direction_Reverse;
  }
  
  if (option == 1){ // Degree
    long degrees = (long) value;
    if (motor_id <= 2){
      nxshield.bank_a.motorRunDegrees(motor, dir, speed, degrees, SH_Completion_Dont_Wait, SH_Next_Action_Brake);
    }else{
      nxshield.bank_b.motorRunDegrees(motor, dir, speed, degrees, SH_Completion_Dont_Wait, SH_Next_Action_Brake);
    }
  }else if (option == 2){ // Rotation
    long rotations = (long) value;
    if (motor_id <= 2){
      nxshield.bank_a.motorRunRotations(motor, dir, speed, rotations, SH_Completion_Dont_Wait, SH_Next_Action_Brake);
    }else{
      nxshield.bank_b.motorRunRotations(motor, dir, speed, rotations, SH_Completion_Dont_Wait, SH_Next_Action_Brake);
    }
  }else if (option == 3){ // Seconds
    int duration = value;
    if (motor_id <= 2){
      nxshield.bank_a.motorRunSeconds(motor, dir, speed, duration, SH_Completion_Dont_Wait, SH_Next_Action_Brake);
    }else{
      nxshield.bank_b.motorRunSeconds(motor, dir, speed, duration, SH_Completion_Dont_Wait, SH_Next_Action_Brake);
    }
  }else if (option == 4){ // Tachometer
    long tachometer = (long) value;
    if (motor_id <= 2){
      nxshield.bank_a.motorRunTachometer(motor, dir, speed, tachometer, SH_Move_Absolute, SH_Completion_Dont_Wait, SH_Next_Action_Brake);
    }else{
      nxshield.bank_b.motorRunTachometer(motor, dir, speed, tachometer, SH_Move_Absolute, SH_Completion_Dont_Wait, SH_Next_Action_Brake);
    }
  }else if (option == 5){ // Unlimited
    if (motor_id <= 2){
      nxshield.bank_a.motorRunUnlimited(motor, dir, speed);
    }else{
      nxshield.bank_b.motorRunUnlimited(motor, dir, speed);
    }
  }else if (option == 6){ // Stop
    if (motor_id <= 2){
      nxshield.bank_a.motorStop(motor, SH_Next_Action_Brake);
    }else{
      nxshield.bank_b.motorStop(motor, SH_Next_Action_Brake);
    }
  }
}
ros::Subscriber<roslego::motor_action> motor_action_sub("motor_action", motor_action);

/* ROS publisher */
std_msgs::Int32 motor_1_position;
ros::Publisher motor_1_position_pub("motor_1_position", &motor_1_position);

std_msgs::Int32 motor_2_position;
ros::Publisher motor_2_position_pub("motor_2_position", &motor_2_position);

std_msgs::Int32 motor_3_position;
ros::Publisher motor_3_position_pub("motor_3_position", &motor_3_position);

std_msgs::Int32 motor_4_position;
ros::Publisher motor_4_position_pub("motor_4_position", &motor_4_position);

std_msgs::UInt16 battery_voltage;
ros::Publisher battery_voltage_pub("battery_voltage", &battery_voltage);

std_msgs::Bool button_1_state;
ros::Publisher button_1_pub("button_1_state", &button_1_state);

std_msgs::Bool button_2_state;
ros::Publisher button_2_pub("button_2_state", &button_2_state);

std_msgs::Empty end_publishing;
ros::Publisher end_publishing_pub("end_publishing", &end_publishing);

roslego::ahrs ahrs_value;
ros::Publisher ahrs_value_pub("ahrs_value", &ahrs_value);

void setup(){
  delay(3000); //be sure IMU is started
  
  // Initialize the protocol for NXShield
  nxshield.init( SH_HardwareI2C );
  nxshield.ledSetRGB(8,0,0); 
  
    /* NXSHIELD init*/
  // reset motors
  nxshield.bank_a.motorReset();  
  nxshield.bank_b.motorReset();
  // initialize the analog sensors and last_values
  touch_1.init( &nxshield, SH_BAS1 );
  last_2_status = touch_1.isPressed();
  
  touch_2.init( &nxshield, SH_BBS1 );
  last_2_status = touch_2.isPressed();
  
  last_motor_1_position = nxshield.bank_a.motorGetEncoderPosition(SH_Motor_1);
  last_motor_2_position = nxshield.bank_a.motorGetEncoderPosition(SH_Motor_2);
  last_motor_3_position = nxshield.bank_b.motorGetEncoderPosition(SH_Motor_1);
  last_motor_4_position = nxshield.bank_b.motorGetEncoderPosition(SH_Motor_2);
  
  last_battery_voltage = nxshield.bank_a.nxshieldGetBatteryVoltage();
  
  ahrs_value.yaw = 0.0;
  ahrs_value.pitch = 0.0;
  ahrs_value.roll = 0.0;
  
  /* Port config */
  
  /* ROS config */
  nh.initNode();
  //advertise publisher
  nh.advertise(motor_1_position_pub);
  nh.advertise(motor_2_position_pub);
  nh.advertise(motor_3_position_pub);
  nh.advertise(motor_4_position_pub);
  nh.advertise(battery_voltage_pub);
  nh.advertise(button_1_pub);
  nh.advertise(button_2_pub);
  nh.advertise(end_publishing_pub);
  nh.advertise(ahrs_value_pub);
  //subscribe
  nh.subscribe(motor_action_sub);
  nh.subscribe(set_loop_delay_sub);
  nh.subscribe(force_all_publish_sub);
  
  /* IMU */
  Serial1.begin(57600);
  // Set Razor output parameters
  Serial1.write("#o0"); //- (default) DISABLE continuous streaming output. Also see #f below.
  //"#o1" - ENABLE continuous streaming output.
  //Serial1.write("#ob"); // - Output angles in BINARY format (yaw/pitch/roll as binary float, so one output frame is 3x4 = 12 bytes long).
  Serial1.write("#ot");  // (default) - Output angles in TEXT format (Output frames have form like "#YPR=-142.28,-5.38,33.52", followed by carriage return and line feed [\r\n]).
  Serial1.write("#oe0");   // Disable error message output
  Serial1.flush();
  inputAHRS.reserve(200);
  

  //debugSerial.begin(9600); // for debug only
  //debugSerial.println ("Running"); // for debug only
  // waiting for go button press
  //nxshield.waitForButtonPress(BTN_GO);
  nxshield.ledSetRGB(0,8,0); 
}

unsigned long start_time;
unsigned long end_time;
boolean end_loop;

void loop(){
  Serial1.write("#f");
  
  start_time = millis();
  end_loop = false;
  
  motor_1_position.data = nxshield.bank_a.motorGetEncoderPosition(SH_Motor_1);
  if (motor_1_position.data != last_motor_1_position){
    last_motor_1_position = motor_1_position.data; 
    motor_1_position_pub.publish(&motor_1_position);
  }
  
  motor_2_position.data = nxshield.bank_a.motorGetEncoderPosition(SH_Motor_2);
  if (motor_2_position.data != last_motor_2_position){
    last_motor_2_position = motor_2_position.data; 
    motor_1_position_pub.publish(&motor_2_position);
  }
 
  motor_3_position.data = nxshield.bank_b.motorGetEncoderPosition(SH_Motor_1);
  if (motor_3_position.data != last_motor_3_position){
    last_motor_3_position = motor_3_position.data; 
    motor_3_position_pub.publish(&motor_3_position);
  }
 
  motor_4_position.data = nxshield.bank_b.motorGetEncoderPosition(SH_Motor_2);
  if (motor_4_position.data != last_motor_4_position){
    last_motor_4_position = motor_4_position.data; 
    motor_4_position_pub.publish(&motor_4_position);
  }
  
  battery_voltage.data = nxshield.bank_a.nxshieldGetBatteryVoltage();
  if (battery_voltage.data != last_battery_voltage){
    last_battery_voltage = battery_voltage.data;
    battery_voltage_pub.publish(&battery_voltage);
  }
  
  button_1_state.data = touch_1.isPressed();
  if (button_1_state.data != last_1_status) {
    last_1_status = button_1_state.data;
    button_1_pub.publish(&button_1_state);
  }
  
  button_2_state.data = touch_2.isPressed();
  if (button_2_state.data != last_2_status) {
    last_2_status = button_2_state.data;
    button_2_pub.publish(&button_2_state);
  }
  
  ahrs_value_pub.publish(&ahrs_value);
  
  end_publishing_pub.publish(&end_publishing);
  
  while (end_loop == false){
    delay(1);
    nh.spinOnce();
    end_time = millis();
    if ((end_time - start_time) > loop_delay){
      end_loop = true;
    }
  }
}

void serialEvent1() {
  while (Serial1.available()) {
    // get the new byte:
    char inChar = (char)Serial1.read(); 
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      //yaw
      s = inputAHRS.indexOf("=") + 1;
      e = inputAHRS.indexOf(",");
      strBuf = inputAHRS.substring(s,e);
      strBuf.toCharArray(charBuf, 10);
      ahrs_value.yaw = atof(charBuf);
      //pitch
      s = e + 1;;
      e = inputAHRS.indexOf(",", s);
      strBuf = inputAHRS.substring(s,e);
      strBuf.toCharArray(charBuf, 10);
      ahrs_value.pitch = atof(charBuf);
      //roll
      s = e + 1;;
      e = inputAHRS.length();
      strBuf = inputAHRS.substring(s,e);
      strBuf.toCharArray(charBuf, 10);
      ahrs_value.roll = atof(charBuf);
      
      inputAHRS = "";
    
    }
    else{
      // add it to the inputString:
      inputAHRS += inChar;
    }
  }    
}

