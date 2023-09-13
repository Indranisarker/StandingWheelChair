#include<Servo.h>
int chair_previous_state=0;

Servo servo_Leg;
Servo servo_Seat;


void setup() 
{
  servo_Leg.attach(12);
  servo_Seat.attach(13);
  // Switch 
  pinMode(8, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  int stand_flag = digitalRead(8);
  Serial.print(stand_flag);
  if (stand_flag==1 && chair_previous_state==0){
    // Leg rotate from 90 to 30
    int rotation_Leg = 90;
    // Seat rotate from 120 to 180
    int rotation_Seat = 120;
    for(int i = 0;i<60;i+=1){
      servo_Leg.write(rotation_Leg-i);
      delay(15);
      servo_Seat.write(rotation_Seat+i);
      delay(15);
    }
    chair_previous_state=stand_flag;
    Serial.println("Standing....");

  }
  else if (stand_flag==0 && chair_previous_state==1){
    // Leg rotate from 30 to 90
    int rotation_Leg = 30;
    // Seat rotate from 180 to 120
    int rotation_Seat = 180;
    for(int i = 0;i<60;i+=1){
      servo_Leg.write(rotation_Leg+i);
      delay(15);
      servo_Seat.write(rotation_Seat-i);
      delay(15);
    }
    chair_previous_state=stand_flag;
    Serial.println("Back to Normal....");


  }
  delay(2000);

    

}
