#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo;
SoftwareSerial hc06(2, 3);

void setup() {
  // bt init
  Serial.begin(9600);
  hc06.begin(9600);

  // servi motor init
  myservo.attach(9); 
}

void loop() {
  if (hc06.available()) 
  {
    char cmd = hc06.read();

    Serial.write(cmd);
    
    if(cmd == 'U')
      myservo.write(180);
    else if(cmd == 'D')
      myservo.write(90);
  }
}
