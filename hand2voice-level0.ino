#include <Wire.h>
#include <MPU6050.h>
#include <math.h> 
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
MPU6050 mpu;
int currentAngleX = 0; 
int storedAngleX = 0; 
bool isBent = false;   
bool isPartiallyBent = false;  // New flag for incomplete bending
int16_t accelX, accelY, accelZ;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("not connected");
    while (1);
  }
    Serial.begin(9600); // For debugging
  mySerial.begin(9600); // DFPlayer Mini baud rate
  
  if (!myDFPlayer.begin(mySerial)) { // Use softwareSerial to communicate
    Serial.println("DFPlayer initialization failed!");
    Serial.println("Please check wiring and reset the device.");
    while (true);
  }
  
  Serial.println("DFPlayer Mini online.");
}
void loop() {
  mpu.getAcceleration(&accelX, &accelY, &accelZ);
  currentAngleX = (int)(atan2(accelY, accelZ) * 180.0 / PI); 
  if (currentAngleX < -15) {  
    if (!isBent) {
      storedAngleX = currentAngleX;
      Serial.println(" bented, soterd angle: ");
      myDFPlayer.volume(30); // Set volume (0 to 30)
      myDFPlayer.play(2); // Play the first audio file
      Serial.println(storedAngleX);
      isBent = true;
    } else {
      if (currentAngleX == storedAngleX) {
        Serial.print("angle x ");
        Serial.println(storedAngleX);
      }
    }
  } else if (currentAngleX <5 && currentAngleX >= -15) { // New condition for incomplete bending
    if (!isPartiallyBent) {
      Serial.println("Bending incomplete");
       myDFPlayer.volume(30); // Set volume (0 to 30)
       myDFPlayer.play(1); // Play the first audio file
      isPartiallyBent = true;
    }
  } else {
    isBent = false;  
    isPartiallyBent = false; // Reset the flag when no bending is detected
  }
  Serial.print("X: ");
  Serial.println(currentAngleX);

  delay(500);  
}