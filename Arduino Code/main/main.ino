#include <Servo.h>

#define ledPin 'integer'
#define servoPin 'integer'
#define speakerPin 'integer'



int state = 0; //variable to hold the state of the serial

Servo myservo;

// swivel the servo n times between min_pos and max_pos, with wait_time delay(>=15),n times
void swivel(Servo* myservo,int min_pos, int max_pos,int wait_time){
  myservo->write(min_pos);
  delay(wait_time);
  myservo->write(max_pos);
  delay(wait_time);
}

void setup() {
  // set pinMode of LEDs
  pinMode(ledPin, OUTPUT);
  digitialWrite(ledPin, LOW);

  // attach servo
  myservo.attach(servoPin)

  // start recieving bluetooth communication
  Serial.begin(9600);

}

void loop() {

  if(Serial.available() > 0)
  { // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
  }

  doLedThing(state);
  
  doSpeakerThing(state);
  doMotorThing(state);
  
  // how long should we delay before the robot changes its state?
  delay('time to delay');
}
