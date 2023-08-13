#include<Servo.h>

Servo EYE_right;
Servo EYE_left;
Servo EYE_blink;


const int sound_sensor_right = A2; 
const int sound_sensor_left = A3; 
const int threshold=200;
int Blink_time = 700;
int Rotate_time = 3000;

void setup() {
  pinMode(sound_sensor_right, INPUT); //Setting the pin to input for reading data
  pinMode(sound_sensor_left, INPUT);
  
  EYE_right.attach(3);
  EYE_left.attach(4);
  EYE_blink.attach(5);
}

void loop()
{
    EYE_Blink_loop();
    EYE_Right_loop();
    EYE_Left_loop();
}

void EYE_Blink_loop()
  {
    int sound_right=analogRead(sound_sensor_right);
    int sound_left=analogRead(sound_sensor_left);
    
    delay(Rotate_time);
    
    if (sound_right<=threshold) {
      
       if (sound_left<=threshold){
          
          EYE_blink.write(90); 
          delay(Blink_time);
          EYE_blink.write(0);
       }
    }
    else{
      EYE_blink.write(0);
      delay(Blink_time);
}
  }

void EYE_Right_loop()
  {
    int sound_right=analogRead(sound_sensor_right);
    
    if (sound_right>=threshold) {
      
          EYE_right.write(90); 
          delay(Rotate_time);
      
    }
    else{
      EYE_right.write(0);
      delay(Rotate_time);
}
  }
  
 void EYE_Left_loop()
  {
    int sound_left=analogRead(sound_sensor_left);
    
    if (sound_left>=threshold) {
      
          EYE_left.write(0); 
          delay(Rotate_time);
      
    }
    else{
      EYE_left.write(90);
      delay(Rotate_time);
}
  }

  //servo eye part complete
//arduino talking will be soon added
