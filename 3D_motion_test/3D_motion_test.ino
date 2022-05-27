#include <Wire.h>
#include<Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH 500
#define MAX_PULSE_WIDTH 2500
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50
#define hip_len 54
#define upperl_len 160
#define lowerl_len 150

uint8_t servonum = 0; //used for recording purposes
int hip = 0;
int thigh = 1;
int leg = 2;
int j, k;
String s, s1, s2, s3, s4;
double X, Y, Z; //coords Y=-219.32, Z=54
double X_rest, Y_rest=-220, Z_rest=54;
double q1, q2, q3;  //double for more accuracy, angles
double D;
double hip_ang, thigh_ang, leg_ang; //temporary fix
double x1=100, x2=-100, y2=-220, y3=-140, z1=94, z2=14, x_mid=50;
double dx=abs(x_mid-x1), dy=abs(y2-y3), dz=abs(z1-z2);
double dydx=dy/dx, dzdx=dz/dx;
double y_offset=x1*dydx;
int d_time = 3000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Start");
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  swing(X_rest, Y_rest, Z_rest);
  delay(d_time);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0)
  {    
    /*swing(x1, y2, Z_rest);
    delay(500);
    for(X=100; X>-100; X--)
    {
      Z=0.4*X+54;     
      swing(X, Y, Z);
    }

    delay(500);

    for(Y=-220; Y<=-140; Y++)
    {
      //Y=4*X+400-220;
      swing(X, Y, Z);
    }

    delay(500);

    for(X=-100; X<=50; X++)
    {
      Z=0.4*X+54;     
      swing(X, Y, Z);
    }

    delay(500);

    for(X=50; X<100; X++)
    {
      Y=-1.6*X+160-220;
      Z=0.4*X+54;
      swing(X, Y, Z);
    }*/

    forward();

}
