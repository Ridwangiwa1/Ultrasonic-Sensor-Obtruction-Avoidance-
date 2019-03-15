/*******
 * SUPER COMO TEENSY CODE
 ******/

 // Header files for ROS software 
#include <ros.h>
// sensor for specific data to stored 
#include <sensor_msgs/Range.h>

//#include <hardware_interface/encoders.h>
//#include <hardware_interface/ultrasonics.h>

/* Create 8 messages that are constatny identified 
 * NodeHandle to represent the adress of the Jetson where the Teensey would send dte to
   */
ros::NodeHandle nh;
sensor_msgs::Range ultrasonic1;
sensor_msgs::Range ultrasonic2;
sensor_msgs::Range ultrasonic3;
sensor_msgs::Range ultrasonic4;
sensor_msgs::Range ultrasonic5;
sensor_msgs::Range ultrasonic6;
sensor_msgs::Range ultrasonic7;
sensor_msgs::Range ultrasonic8;

/*pointing the ojects from The sensor objects 
 * and being listend to by charter 
 * they are all called ultrasonics therefore when called all the charters would be called.
 */
ros::Publisher chatter1("ultrasonics",&ultrasonic1);
ros::Publisher chatter2("ultrasonics",&ultrasonic2);
ros::Publisher chatter3("ultrasonics",&ultrasonic3);
ros::Publisher chatter4("ultrasonics",&ultrasonic4);
ros::Publisher chatter5("ultrasonics",&ultrasonic5);
ros::Publisher chatter6("ultrasonics",&ultrasonic6);
ros::Publisher chatter7("ultrasonics",&ultrasonic7);
ros::Publisher chatter8("ultrasonics",&ultrasonic8);

// Forward pins
int trigpin1 = 1;
int echopin1 = 0;
int trigpin2 = 3;
int echopin2 = 2;
int trigpin3 = 5;
int echopin3 = 4;
int trigpin4 = 7;
int echopin4 = 6;
// Back Camera
nt trigpin5 = 23;
int echopin5 = 22;
int trigpin6 = 21;
int echopin6 = 20;
int trigpin7 = 19;
int echopin7 = 18;
int trigpin8 = 17;
int echopin8 = 16;

volatile float maxFrontDistance = 15.00;
volatile float frontDuration1,frontDuration2,frontDuration3,frontDuration4,frontDistanceCm1,frontDistanceCm2,
				frontDistanceCm3,frontDistanceCm4, backDuration1,backDuration2,
				backDuration3,backDuration4, backDistanceCm1, backDistanceCm2, backDistanceCm3,backDistanceCm4;
volatile float maxbackDistance = 15;
void setup() {
  // serial
  Serial.begin(9600);
   /*initializing node for jeston
   * advertise chatter to Jetson
   */
  nh.initNode();
  nh.advertise(chatter1);
  nh.advertise(chatter2);
  nh.advertise(chatter3);
  nh.advertise(chatter4);
  nh.advertise(chatter5);
  nh.advertise(chatter6);
  nh.advertise(chatter7);
  nh.advertise(chatter8);

  pinMode(trigpin1, OUTPUT);
  pinMode(echopin1, INPUT);
  pinMode(trigpin2, OUTPUT);
  pinMode(echopin2, INPUT);
  pinMode(trigpin3, OUTPUT);
  pinMode(echopin3, INPUT);
  pinMode(trigpin4, OUTPUT);
  pinMode(echopin4, INPUT);
  pinMode(trigpin5, OUTPUT);
  pinMode(echopin5, INPUT);
  pinMode(trigpin6, OUTPUT);
  pinMode(echopin6, INPUT);
  pinMode(trigpin7, OUTPUT);
  pinMode(echopin7, INPUT);
  pinMode(trigpin8, OUTPUT);
  pinMode(echopin8, INPUT);
  Serial.begin(57600);
 
}
void loop() {
  // front distance check
  checkFrontDistance1();
  if (frontDistanceCm1 < maxFrontDistance) 
  {
    Serial.println("Too close");
    delay(20);
    //PUBLISH A STOP SIGNAL!!
    }
  }
  checkFrontDistance2();
  if (frontDistanceCm2 < maxFrontDistance) 
  {
    Serial.println("Too close");
    delay(20);
     //PUBLISH A STOP SIGNAL!!
  }
  checkFrontDistance3();
  if (frontDistanceCm3 < maxFrontDistance) 
  {
    Serial.println("Too close");
    delay(20);
    //PUBLISH A STOP SIGNAL!!
  }
  checkFrontDistance4();
  if (frontDistanceCm4 < maxFrontDistance) 
  {
    Serial.println("Too close");
    delay(20);
     //PUBLISH A STOP SIGNAL!!
  }
  
  // back distance check
  
  checkbacktDistance5();
  if (backDistanceCm1 < maxLeftDistance) {
    Serial.println("Left too close");
    delay(20);
   //PUBLISH A STOP SIGNAL!!
  }
  checkbacktDistance6();
  if (backDistanceCm2 < maxLeftDistance) {
    Serial.println("Left too close");
    delay(20);
   //PUBLISH A STOP SIGNAL!!
  }
  checkbacktDistance7();
  if (backDistanceCm2 < maxLeftDistance) {
    Serial.println("Left too close");
    delay(20);
   //PUBLISH A STOP SIGNAL!!
  }
  checkbacktDistance8();
  if (backDistanceCm3 < maxLeftDistance) {
    Serial.println("Left too close");
    delay(20);
   //PUBLISH A STOP SIGNAL!!
  }
  
void checkFrontDistance1() {
  digitalWrite( trigpin1, LOW);  // generate a clean pulse we put LOW 4us
  delayMicroseconds (4);
  delayMicroseconds(4);
  digitalWrite( trigpin1, HIGH);  //generate Trigger (shot) of 10us
  delayMicroseconds(10);
  digitalWrite(trigpin1, LOW);
  frontDuration1 = pulseIn(echopin1, HIGH);  //measure the time between pulses, in microseconds
  frontDistanceCm1 = frontDuration1 * 10 / 292 / 2;  //convert distance to cm
  Serial.print("Distance: ");
  Serial.print(frontDistanceCm1);
  Serial.println(" cm");
}
void checkFrontDistance2() {
  digitalWrite( trigpin2, LOW);  // generate a clean pulse we put LOW 4us
  delayMicroseconds (4);
  delayMicroseconds(4);
  digitalWrite(trigpin2, HIGH);  //generate Trigger (shot) of 10us
  delayMicroseconds(10);
  digitalWrite( trigpin2, LOW);
  frontDuration2 = pulseIn(echopin2, HIGH);  //measure the time between pulses, in microseconds
  frontDistanceCm2 = frontDuration * 10 / 292 / 2;  //convert distance to cm
  Serial.print("Distance: ");
  Serial.print(frontDistanceCm2);
  Serial.println(" cm");
}
void checkFrontDistance3() {
  digitalWrite( trigpin3, LOW);  // generate a clean pulse we put LOW 4us
  delayMicroseconds (4);
  delayMicroseconds(4);
  digitalWrite( trigpin3, HIGH);  //generate Trigger (shot) of 10us
  delayMicroseconds(10);
  digitalWrite( trigpin3, LOW);
  frontDuration3 = pulseIn(echopin3, HIGH);  //measure the time between pulses, in microseconds
  frontDistanceCm3 = frontDuration3 * 10 / 292 / 2;  //convert distance to cm
  Serial.print("Distance: ");
  Serial.print(frontDistanceCm3);
  Serial.println(" cm");
}
void checkFrontDistance4() {
  digitalWrite( trigpin4, LOW);  // generate a clean pulse we put LOW 4us
  delayMicroseconds (4);
  delayMicroseconds(4);
  digitalWrite( trigpin4, HIGH);  //generate Trigger (shot) of 10us
  delayMicroseconds(10);
  digitalWrite( trigpin4, LOW);
  frontDuration4 = pulseIn(echopin4, HIGH);  //measure the time between pulses, in microseconds
  frontDistanceCm4 = frontDuration4 * 10 / 292 / 2;  //convert distance to cm
  Serial.print("Distance: ");
  Serial.print(frontDistanceCm4);
  Serial.println(" cm");
}
void checkbacktDistance5() {
  digitalWrite(trigpin5, LOW);  //to generate a clean pulse we put LOW 4us
  delayMicroseconds (4);
  delayMicroseconds(4);
  digitalWrite(trigpin5, HIGH);  //generate Trigger (shot) of 10us
  delayMicroseconds(10);
  digitalWrite(trigpin5, LOW);
  backDuration1 = pulseIn(echopin5, HIGH);  //measure the time between pulses, in microseconds
  backDistanceCm1 = backDuration1 * 10 / 292 / 2;  //convert distance to  cm
  Serial.print("back distance: ");
  Serial.print(backDistanceCm1);
  Serial.println(" cm");
}
void checkbacktDistance6() {
  digitalWrite(trigpin6, LOW);  //to generate a clean pulse we put LOW 4us
  delayMicroseconds (4);
  delayMicroseconds(4);
  digitalWrite(trigpin6, HIGH);  //generate Trigger (shot) of 10us
  delayMicroseconds(10);
  digitalWrite(trigpin6, LOW);
  backDuration2 = pulseIn(echopin6, HIGH);  //measure the time between pulses, in microseconds
  backDistanceCm2 = backDuration2 * 10 / 292 / 2;  //convert distance to  cm
  Serial.print("back distance: ");
  Serial.print(backDistanceCm2);
  Serial.println(" cm");
}
void checkbacktDistance7() {
  digitalWrite(trigpin7, LOW);  //to generate a clean pulse we put LOW 4us
  delayMicroseconds (4);
  delayMicroseconds(4);
  digitalWrite(trigpin7, HIGH);  //generate Trigger (shot) of 10us
  delayMicroseconds(10);
  digitalWrite(trigpin7, LOW);
  backDuration3 = pulseIn(echopin7, HIGH);  //measure the time between pulses, in microseconds
  backDistanceCm3 = backDuration3 * 10 / 292 / 2;  //convert distance to  cm
  Serial.print("back distance: ");
  Serial.print(backDistanceCm3);
  Serial.println(" cm");
}
void checkbacktDistance8() {
  digitalWrite(trigpin8, LOW);  //to generate a clean pulse we put LOW 4us
  delayMicroseconds (4);
  delayMicroseconds(4);
  digitalWrite(trigpin8, HIGH);  //generate Trigger (shot) of 10us
  delayMicroseconds(10);
  digitalWrite(trigpin8, LOW);
  backDuration4 = pulseIn(echopin8, HIGH);  //measure the time between pulses, in microseconds
  backDistanceCm4 = backDuration4 * 10 / 292 / 2;  //convert distance to  cm
  Serial.print("back distance: ");
  Serial.print(backDistanceCm4);
  Serial.println(" cm");
  /*
 * Ultrsonic, rane holding float value = inches 
 * radiation_type to know what ultrasonic device its listening to
 */
    ultrasonic1.range = inches1;
    ultrasonic1.radiation_type = 1;
    ultrasonic2.range = inches2;
    ultrasonic2.radiation_type = 2;
    ultrasonic3.range = inches3;
    ultrasonic3.radiation_type = 3;
    ultrasonic4.range = inches4;
    ultrasonic4.radiation_type = 4;
    ultrasonic5.range = inches5;
    ultrasonic5.radiation_type = 5;
    ultrasonic6.range = inches6;
    ultrasonic6.radiation_type = 6;
    ultrasonic7.range = inches7;
    ultrasonic7.radiation_type = 7;
    ultrasonic8.range = inches8;
    ultrasonic8.radiation_type = 8;

    /*
     * cahtter.publish qould publish data t handle 
     * noneed to worry about seeting where to since it has een advertised to nh
     */
    chatter1.publish(&ultrasonic1);
    chatter2.publish(&ultrasonic2);
    chatter3.publish(&ultrasonic3);
    chatter4.publish(&ultrasonic4);
    chatter5.publish(&ultrasonic5);
    chatter6.publish(&ultrasonic6);
    chatter7.publish(&ultrasonic7);
    chatter8.publish(&ultrasonic8);
}
