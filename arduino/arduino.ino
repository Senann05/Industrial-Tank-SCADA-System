const int trigPin = 9;
const int echoPin = 10;
const int greenLED = 2;
const int yellowLED = 3;
const int redLED = 4;
const int buzzerPin = 5;

const float tankHeight = 16.0;

bool isMuted = false;
bool areLedsOff = false;

void setup() {
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim(); 

    if (command == "MUTE_TOGGLE") {
      isMuted = !isMuted; 
    } 

    else if (command == "LED_TOGGLE") {
      areLedsOff = !areLedsOff;
    }

  }

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;


  float level = tankHeight - distance; 

  if(level < 0) level = 0;
  if(level > tankHeight) level = tankHeight;

  int percentage = (level / tankHeight) * 100;

  Serial.print(percentage);
  Serial.println("%");

  int currentRed = LOW;
  int currentYellow = LOW;
  int currentGreen = LOW;
  int currentBuzzerPWM = 0;

  if (percentage > 80) {
    currentRed = HIGH;
    currentBuzzerPWM = 255;
  } 

  else if (percentage < 15) {
    currentRed = HIGH;
    currentBuzzerPWM = 50;
  } 

  else if (percentage >= 35 && percentage <= 65) {
    currentGreen = HIGH;
    currentBuzzerPWM = 0;
  } 

  else {
    currentYellow = HIGH;
    currentBuzzerPWM = 30;
  }

  if (areLedsOff) {
    currentRed = LOW;
    currentYellow = LOW;
    currentGreen = LOW;
  }

  if (isMuted) {
    currentBuzzerPWM = 0;
  }

  digitalWrite(redLED, currentRed);
  digitalWrite(yellowLED, currentYellow);
  digitalWrite(greenLED, currentGreen);
  analogWrite(buzzerPin, currentBuzzerPWM);
  
  delay(200); 
}