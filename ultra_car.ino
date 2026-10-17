
#include <DFRobotDFPlayerMini.h>
#include <SD.h>
#include <BluetoothSerial.h>

// Define pins
#define trig 12
#define echo 14
#define motor 16

// Variables
long dur;
float S;
File loc1File;

// Objects
BluetoothSerial SerialBT;
SoftwareSerial mySerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Initializing...");

  // Initialize DFPlayer Mini
  if (!myDFPlayer.begin(mySerial)) { // Use software Serial to communicate
    Serial.println("DFPlayer initialization failed!");
    Serial.println("Please check wiring and reset the device.");
    while (true);
  }
  Serial.println("DFPlayer Mini online.");
  myDFPlayer.volume(30); // Set default volume (0 to 30)

  // Initialize Bluetooth
  SerialBT.begin("ESP32_BT");
  Serial.println("Bluetooth Started. Waiting for connection...");

  // Initialize SD card
  if (!SD.begin(5)) { // Assuming chipSelect is GPIO 5
    Serial.println("SD Card initialization failed!");
    return;
  }
  Serial.println("SD Card initialized.");

  // Create /loc1.csv if it doesn't exist
  if (!SD.exists("/loc1.csv")) {
    loc1File = SD.open("/loc1.csv", FILE_WRITE);
    if (loc1File) {
      Serial.println("/loc1.csv created.");
      loc1File.close();
    } else {
      Serial.println("Error creating /loc1.csv");
    }
  } else {
    Serial.println("/loc1.csv already exists.");
  }

  // Pin modes
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(motor, OUTPUT);
  digitalWrite(motor, LOW); // Ensure motor is off initially
}

void ultra() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  dur = pulseIn(echo, HIGH);
  S = (dur / 2) * 0.0343;

  if (S < 20) {
    digitalWrite(motor, HIGH);
    delay(7000);
    digitalWrite(motor, LOW);
    Serial.println("Motor activated.");
    data(); // Call data function (assumed to be defined elsewhere)
  } else {
    digitalWrite(motor, LOW);
  }
}

void loop() {
  ss(); // Call ss function (assumed to be defined elsewhere)
  ultra();
}