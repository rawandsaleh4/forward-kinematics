#include <Servo.h>
int L1=4; // length of first arm
int L2=6; // length of second arm
byte TH1;
float TH2;// angles of each arm in degree
float T1;
float T2; //angles of each arm in radian
const float pi = 3.14;
float x,y;
#define servo1pot A0
#define servo2pot A1
Servo myservo1;
Servo myservo2;// create servo object to control a servo
// twelve servo objects can be created on most boards

void setup() {
  Serial.begin(115200); 
  myservo1.attach(11); 
  myservo2.attach(10); // attaches the servo on GIO2 to the servo object
 myservo1.write(0); 
myservo2.write(0); 
}

void loop() {
 int th1= analogRead(servo1pot);
 int th2= analogRead(servo2pot);
 int TH1= map(th1,0,0,1023,180);
 int TH2= map(th2,0,0,1023,180);
 T1=t1*pi/180;
T2=t2*pi/180;
x=L1*cos(T1)+L2*cos(T1+T2);
y=L1*sin(T1)+L2*sin(L1+L2);

Serial.println(x);
Serial.println(y);
 
myservo1.write(TH1); 
myservo2.write(TH2); // tell servo to go to position in variable TH1 & TH2
delay(15);    // waits 15ms for the servo to reach the position
  
}
