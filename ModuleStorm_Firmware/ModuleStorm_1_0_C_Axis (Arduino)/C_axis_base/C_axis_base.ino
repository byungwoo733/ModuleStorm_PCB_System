/* C_Axis  is Small Software for Custom CNC & Custom Arduino Controller */

#include <stdio.h>
#include <Stepper.h>
#include <SPI.h>
#include <Ethernet.h>
#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>

const int chipSelect = 10;
SoftwareSerial portOne(10, 11); // RX, TX

SoftwareSerial portTwo(8, 9); // RX, TX

void setup() {
    
    // Serial Communication for SD Card Port
    Serial.begin(9600);
    while (!Serial) {
      ;
    }
    
    portOne.begin(9600);
    
    portTWo.begin(9600);
  }
    
    
void loop() 
  {
    if (portOne.available())
      Serial.write(portOne.read());
    if (Serial.available())
      portOne.write(Serial.read());
       
      
      Serial.println("First C-Axis Start!");
  }
    // Second port
    portTwo.listen();
    
    // Software Serial Port
    PortTwo.begin(9600);
    mySerial.println("C-Axis, Ready?");
    
    if (portTwo.available())
      Serial.write(porTwo.read());
    if (Serial.available())
      portTwo.write(Serial.read()); 
    
    while (portTwo.available() > 0) {

    char inByte = portTwo.read();

    Serial.write(inByte);
    
    Serial.println();
  }
