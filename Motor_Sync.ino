#include <PID_v1.h>
#define PIN_INPUT 0
#define PIN_OUTPUT 3
//Define Variables we'll be connecting to
double Setpoint, Input, Output;
//Specify the links and initial tuning parameters
double Kp=3.125, Ki=2.5, Kd=0.125;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
#include <Wire.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display

#define enA 9
#define in1 13
#define in2 7
float per_sp, per_mv;
 // will store last time LED was updated

// constants won't change :
const long interval = 100;
void setup() {

 Input = per_mv;
 Setpoint = per_sp;
 //turn the PID on
 myPID.SetMode(AUTOMATIC);
 // Turn on the blacklight and print a message.

 Serial.begin(115200);
 pinMode(enA, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);

 // Set initial rotation direction
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
}
void loop() {

 per_sp = 100 * (digitalRead(11) / 1023.0);
 per_mv = 100 * (analogRead(A2) / 1023.0);
 per_mv = 100 * (per_mv/50.0);
 Setpoint = per_sp;
 Input = per_mv ;
 //myPID.Compute();
 analogWrite(9, (map(analogRead(A0),0,1023,0,255)));



 Serial.println(map(analogRead(A0),0,1023,0,255));
 delay(5);

}
