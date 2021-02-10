#define ledPin 'integer'
#define servoPin 'integer'
#define speakerPin 'integer'



int state = 0; //variable to hold the state of the serial

Servo myservo

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

  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 }

  doLedThing(state); 
  doSpeakerThing(state);
  doMotorThing(state);

  // how long should we delay before the robot changes its state?
  delay('time to delay');
}
