#include <Servo.h>
#include <Pixy2.h>

Servo myServo1;
Servo myServo2;
Pixy2 pixy;

int pix;

const int trigPin = 9;  //defining pin numbers for ultrasonic sensor
const int echoPin = 3; 

long duration;  //defining variables to be used in code
int distance;

void setup() {
  myServo1.attach(5); //attaches Servo 1 to Pin 5
  myServo2.attach(6); //attaches Servo 2 to Pin 6
  
  myServo1.write(120); //starting positions for both servos
  myServo2.write(20);

  pinMode(trigPin, OUTPUT);   //sets pin modes for the Ultrasonic sensor
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  Serial.print("Starting...\n");
  pixy.init();   //initializes PIXY cam
  
}

void loop() {
  int dist = ultrasonicReadings(); //gets data from the ultrasonicReadings function
  int pix = pixyReadings();      //gets data from the pixyReadings function
  //myServo1.write(45);
  //myServo2.write(120);

  if (dist <=120 and pix == 2){  //if sensor reads this distance and PIXY gets BLUE 
    myServo1.write(180); 
    delayMicroseconds(600);//servo will be activated
     
  }
  if (dist <=120 and pix == 1){    //PIXY reads RED
    myServo2.write(120);
    delayMicroseconds(600);

    }

}


int ultrasonicReadings(){
  digitalWrite(trigPin, LOW);   // Clears the trigPin
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);  //Sets the trigPin on HIGH state for 10 micro seconds
  duration = pulseIn(echoPin, HIGH);
  //Serial.println("Duration:");
  //Serial.print(duration);
  distance = duration*0.034/2; // Calculates the distance
  Serial.println("Distance:");
  Serial.println(distance);

  return distance;
    
}

int pixyReadings(){
  int i;
  int x = pixy.ccc.blocks[i].m_signature;
  pixy.ccc.getBlocks();
  if (pixy.ccc.numBlocks){
    Serial.print("Detected");
    Serial.println(pixy.ccc.numBlocks);
    Serial.println(pixy.ccc.blocks[i].m_signature);
    /**for (i=0; i<pixy.ccc.numBlocks; i++)
    {
      Serial.print(pixy.ccc.blocks[i].m_signature);
      //Serial.print("  block ");
      //Serial.print(i.);
      //Serial.print(i);
      
  }
  */
  return x;
}
}
