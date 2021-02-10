#include <Servo.h>

/* Declaring RGB PINS */
#define RGB_RedPin 3
#define RGB_GreenPin 5
#define RGB_BluePin 6

/* Declaring Servo PIN */
#define servoPin 9

/* Declaring Servo */
Servo CubotServo;
int servoPos = 0;

/************
  FUNCTIONS
*************/

/* This function takes 3 parameters that decide the RGB values */
void rgbVal(int R, int G, int B)
{
  analogWrite(RGB_RedPin, R);
  analogWrite(RGB_GreenPin, G);
  analogWrite(RGB_BluePin, B);
}

/* This function generates number from 0 to 255*/
int rgbColRand()
{
  int x = random(0, 266);
  return x;
}

/* This function rotates the servo to 180 degree */
void servoRotation()
{
  for (pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees in steps of 1 degree
  { 
    myservo.write(pos);             // tell servo to go to position in variable 'pos'
    rgbVal(rgbColRand(), rgbColRand(), rgbColRand());              
    delay(15);                      // waits 15ms for the servo to reach the position
  }   

  for (pos = 180; pos >= 0; pos -= 1) // goes from 180 degrees to 0 degrees
  {  
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    rgbVal(rgbColRand(), rgbColRand(), rgbColRand()); 
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

/**************************
  END OF HELPER FUNCTIONS
***************************/


void setup() 
{
    // start recieving bluetooth communication
  Serial.begin(9600);

  randomSeed(analogRead(0)); // seed random numbers for rgbColRand()

  CubotServo.attach(servoPin);

  pinMode(RGB_RedPin, OUTPUT);
  pinMode(RGB_GreenPin, OUTPUT);
  pinMode(RGB_BluePin, OUTPUT);
}

void loop() 
{
  servoRotation();
  delay(2000);
}