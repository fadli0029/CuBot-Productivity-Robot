#include "ServoEasing.h"

#define sadMood 1
#define happyMoodV1 2
#define happyMoodV2 3
#define happyMoodV3 4
#define stayStill 0

/* Declaring RGB PINS */
#define RGB_RedPin 3
#define RGB_GreenPin 5
#define RGB_BluePin 6

/* Declaring Servo and Speaker PINS */
#define servoPin 9
#define tonePin 7

/*Global Variables*/
ServoEasing CubotServo;
int pos = 0;
int state = 0;

/************
  FUNCTIONS
*************/

void servoInit(int rotation, int returnPos, int speed_dps)
{
  CubotServo.easeTo(rotation, speed_dps);
  CubotServo.easeTo(returnPos, speed_dps);  
}

/* This function takes 3 parameters that decide the RGB values*/
void rgbVal(int R, int G, int B)
{
  analogWrite(RGB_RedPin, R);
  analogWrite(RGB_GreenPin, G);
  analogWrite(RGB_BluePin, B);
}

int rgbColRand()
{
  int x = random(0, 266);
  return x;
}

void botResponse() {

  if(Serial.available() > 0)
  { // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
  }

  CubotServo.write(0);
 
 if (state == sadMood || state == 5 || state == 6 || state == 7 || state == 8 || state == 9 || state == 10) 
 {
    servoInit(180, 0, 360); // tells the servo to rotate 180, return to 0, in the speed of 360 degree per second
    rgbVal(rgbColRand(), rgbColRand(), rgbColRand());
    R2_D2_alarm_beep();             
    delay(15);  // waits 15ms for the servo to reach the position 
    
    state = 0; // re-initialize state to 0, then read the bluetooth signal again
 }
 else if (state == happyMoodV1) 
 {
    servoInit(180, 0, 360); // tells the servo to rotate 180, return to 0, in the speed of 360 degree per second
    rgbVal(rgbColRand(), rgbColRand(), rgbColRand());
    R2_D2_talking_to_himeself();             
    delay(15);  // waits 15ms for the servo to reach the position 
    
    state = 0; // re-initialize state to 0, then read the bluetooth signal again
 } 
 
 else if (state == happyMoodV2) 
 {
    servoInit(180, 0, 270); // tells the servo to rotate 180, return to 0, in the speed of 360 degree per second
    rgbVal(rgbColRand(), rgbColRand(), rgbColRand());
    R2_D2_beep();             
    delay(15);  // waits 15ms for the servo to reach the position 
    
    state = 0; // re-initialize state to 0, then read the bluetooth signal again
 } 
 
 else if (state == happyMoodV3) 
 {
    servoInit(180, 0, 270); // tells the servo to rotate 180, return to 0, in the speed of 360 degree per second
    rgbVal(rgbColRand(), rgbColRand(), rgbColRand());
    R2_D2_talking_to_himeself();             
    delay(15);  // waits 15ms for the servo to reach the position 
    
    state = 0; // re-initialize state to 0, then read the bluetooth signal again
 }
 
 else if (state == stayStill) 
 {
    // This is the state of CuBot most of the time, coz we don't want to annoy user lol
    rgbVal(rgbColRand(), rgbColRand(), rgbColRand());
    state = 0; // re-initialize state to 0, then read the bluetooth signal again
 } 
}



Servo myservo;

// Credit:
// Midi to Arduino Converter
//     - Andy Tran (extramaster), 2015
// https://www.extramaster.net/tools/midiToArduino/
//
// Process:
// Midi -> Midi tracks -> Note mappings -> Frequency
//
// CC0

void R2_D2_beep() {  //plays sounds like R2_D2 beeping

    tone(tonePin, 1396, 34.8837209302);
    delay(38.7596899225);
    tone(tonePin, 1479, 17.4418604651);
    delay(19.3798449612);
    delay(9.68992248062);
    delay(19.3798449612);
    delay(48.4496124031);
    delay(9.68992248062);
    tone(tonePin, 1567, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 1318, 17.4418604651);
    delay(19.3798449612);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 1244, 26.1627906977);
    delay(29.0697674419);
    tone(tonePin, 1567, 17.4418604651);
    delay(19.3798449612);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 2093, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 1975, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 2217, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 2637, 8.72093023256);
    delay(9.68992248062);
    delay(38.7596899225);
    delay(19.3798449612);
    delay(19.3798449612);
    tone(tonePin, 1975, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 1760, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 1661, 8.72093023256);
    delay(9.68992248062);
    delay(145.348837209);
    tone(tonePin, 2217, 26.1627906977);
    delay(29.0697674419);
    delay(29.0697674419);
    tone(tonePin, 1108, 26.1627906977);
    delay(29.0697674419);
    delay(38.7596899225);
    tone(tonePin, 2093, 17.4418604651);
    delay(19.3798449612);
    delay(19.3798449612);
    tone(tonePin, 2489, 17.4418604651);
    delay(19.3798449612);
    delay(67.8294573643);
    delay(29.0697674419);
    delay(29.0697674419);
    delay(38.7596899225);
    delay(9.68992248062);
    tone(tonePin, 2093, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 3135, 17.4418604651);
    delay(19.3798449612);
    tone(tonePin, 2489, 8.72093023256);
    delay(9.68992248062);

}

void R2_D2_alarm_beep() {  //Plays sounds like R2_D2

    tone(tonePin, 87, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 220, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 293, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 415, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 43, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 554, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 146, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 349, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 391, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 220, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 1479, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 415, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 65, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 43, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 622, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 554, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 41, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 369, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 1760, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 1046, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 293, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 369, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 1174, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 233, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 1567, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 1760, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 2217, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 277, 17.4418604651);
    delay(19.3798449612);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 220, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 1567, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 207, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 1174, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 466, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 277, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 1975, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 659, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 493, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(19.3798449612);
    tone(tonePin, 440, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 783, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 293, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 349, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 987, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 233, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 349, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 1567, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 1567, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 1864, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 2217, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 932, 17.4418604651);
    delay(19.3798449612);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 987, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 391, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 493, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 329, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 523, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 932, 8.72093023256);
    delay(9.68992248062);
    delay(19.3798449612);
    tone(tonePin, 329, 8.72093023256);
    delay(9.68992248062);
    delay(19.3798449612);
    tone(tonePin, 466, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 1108, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 349, 17.4418604651);
    delay(19.3798449612);
    delay(9.68992248062);
    tone(tonePin, 349, 26.1627906977);
    delay(29.0697674419);
    tone(tonePin, 493, 8.72093023256);
    delay(9.68992248062);
}

void R2_D2_talking_to_himeself() {  //Plays sounds like R2D2

    tone(tonePin, 1396, 17.4418604651);
    delay(19.3798449612);
    tone(tonePin, 277, 8.72093023256);
    delay(9.68992248062);
    delay(19.3798449612);
    tone(tonePin, 493, 26.1627906977);
    delay(29.0697674419);
    tone(tonePin, 1046, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 622, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 523, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 659, 17.4418604651);
    delay(19.3798449612);
    tone(tonePin, 277, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 1108, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(19.3798449612);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 220, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 523, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 174, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 2959, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 440, 17.4418604651);
    delay(19.3798449612);
    tone(tonePin, 523, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 184, 8.72093023256);
    delay(9.68992248062);
    delay(29.0697674419);
    delay(19.3798449612);
    tone(tonePin, 311, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 739, 61.0465116279);
    delay(67.8294573643);
    delay(9.68992248062);
    delay(19.3798449612);
    tone(tonePin, 2959, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 164, 26.1627906977);
    delay(29.0697674419);
    delay(77.519379845);
    tone(tonePin, 36, 17.4418604651);
    delay(19.3798449612);
    delay(58.1395348837);
    tone(tonePin, 349, 17.4418604651);
    delay(19.3798449612);
    delay(38.7596899225);
    tone(tonePin, 440, 26.1627906977);
    delay(29.0697674419);
    delay(19.3798449612);
    delay(9.68992248062);
    tone(tonePin, 174, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 61, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 34, 17.4418604651);
    delay(19.3798449612);
    delay(203.488372093);
    tone(tonePin, 41, 26.1627906977);
    delay(29.0697674419);
    delay(38.7596899225);
    tone(tonePin, 38, 17.4418604651);
    delay(19.3798449612);
    delay(58.1395348837);
    tone(tonePin, 29, 17.4418604651);
    delay(19.3798449612);
    delay(19.3798449612);
    tone(tonePin, 233, 26.1627906977);
    delay(29.0697674419);
    delay(29.0697674419);
    tone(tonePin, 65, 17.4418604651);
    delay(19.3798449612);
    delay(9.68992248062);
    tone(tonePin, 38, 17.4418604651);
    delay(19.3798449612);
    delay(38.7596899225);
    tone(tonePin, 58, 17.4418604651);
    delay(19.3798449612);
    delay(19.3798449612);
    tone(tonePin, 46, 34.8837209302);
    delay(38.7596899225);
    delay(58.1395348837);
    delay(9.68992248062);
    tone(tonePin, 30, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 311, 8.72093023256);
    delay(9.68992248062);
    delay(38.7596899225);
    tone(tonePin, 554, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 41, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(9.68992248062);
    tone(tonePin, 329, 17.4418604651);
    delay(19.3798449612);
    tone(tonePin, 349, 17.4418604651);
    delay(19.3798449612);
    delay(19.3798449612);
    tone(tonePin, 1396, 8.72093023256);
    delay(9.68992248062);
    delay(9.68992248062);
    delay(19.3798449612);
    tone(tonePin, 36, 17.4418604651);
    delay(19.3798449612);
    tone(tonePin, 38, 17.4418604651);
    delay(19.3798449612);
    tone(tonePin, 369, 8.72093023256);
    delay(9.68992248062);
    tone(tonePin, 587, 17.4418604651);
    delay(19.3798449612);
    delay(19.3798449612);
    tone(tonePin, 34, 17.4418604651);
    delay(19.3798449612);
    tone(tonePin, 41, 17.4418604651);
    delay(19.3798449612);
    delay(116.279069767);
    tone(tonePin, 36, 17.4418604651);
    delay(19.3798449612);

}




void setup() {
  // set pinMode of LEDs
  pinMode(RGB_RedPin, OUTPUT);
  pinMode(RGB_GreenPin, OUTPUT);
  pinMode(RGB_BluePin, OUTPUT);

  randomSeed(analogRead(0));

  // attach servo
  CubotServo.attach(servoPin);

  // start recieving bluetooth communication
  Serial.begin(9600);

}

void loop() {

//  if(Serial.available() > 0)
//  { // Checks whether data is comming from the serial port
//    state = Serial.read(); // Reads the data from the serial port
//  }

  botResponse();

  delay(2000);
  
}
