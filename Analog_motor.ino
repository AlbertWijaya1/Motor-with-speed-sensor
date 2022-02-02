  int motor1pin1 = 2;
  int motor1pin2 = 3;
  
  int motor2pin1 = 4;
  int motor2pin2 = 5;
  
  
  int sensor_one = 11;
  int sensor_two = 6;
  unsigned long start_time_one = 0;
  unsigned long start_time_two = 0;
  unsigned long end_time_one = 0;
  unsigned long end_time_two = 0;
  int steps_one=0;
  int steps_two=0;
  float steps_old_one=0;
  float steps_old_two=0;
  float temp_one=0;
  float temp_two=0;
  float rps_one=0;
  float rps_two=0;
  float speeed=100;
void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);

  Serial.begin(9600);
  pinMode(sensor_one,INPUT_PULLUP);
  pinMode(sensor_two,INPUT_PULLUP);
 
}

void loop() {
  // put your main code here, to run repeatedly:   

  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(9, speeed); //ENA pin
  analogWrite(10, 255); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(motor1pin1, HIGH);//ENA
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);//ENB
  digitalWrite(motor2pin2, LOW);
  delay(1000);

 start_time_one=millis();
 start_time_two=millis();
 end_time_one=start_time_one+1000;
 end_time_two=start_time_two+1000;
 while(millis()<end_time_one)
 {
   if(digitalRead(sensor_one))
   {
    steps_one=steps_one+1; 
    while(digitalRead(sensor_one));
   }
     if(digitalRead(sensor_two))
   {
    steps_two=steps_two+1; 
    while(digitalRead(sensor_two));
   }

   
 }
    temp_one=steps_one-steps_old_one;
    steps_old_one=steps_one;
    rps_one=(temp_one/9);

    temp_two=steps_two-steps_old_two;
    steps_old_two=steps_two;
    rps_two=(temp_two/9);
    
    Serial.print(rps_one);
    Serial.print("   ");
    Serial.println(rps_two);
if(rps_one>rps_two){

  speeed=speeed-1;
}
else if(rps_one<rps_two){

  speeed=speeed+0.5;
}
//  digitalWrite(motor1pin1, LOW);
//  digitalWrite(motor1pin2, HIGH);

//  digitalWrite(motor2pin1, LOW);
//  digitalWrite(motor2pin2, HIGH);
//  delay(1000);
}
