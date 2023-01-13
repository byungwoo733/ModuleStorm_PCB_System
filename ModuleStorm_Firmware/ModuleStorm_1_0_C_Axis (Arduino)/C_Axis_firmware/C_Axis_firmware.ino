/*C Axis Firmware for ModuleStorm PCB System 1.0 Version*/
#include <Stepper.h>

const int stepsPerRevolution = 200;  // number of steps per revolution for each axis

// initialize the stepper objects for each axis:
Stepper xAxis(stepsPerRevolution, 8, 9, 10, 11);
Stepper yAxis(stepsPerRevolution, 12, 13, 14, 15);
Stepper zAxis(stepsPerRevolution, 16, 17, 18, 19);

void setup() {
  // set the motor speed for each axis in steps per second:
  xAxis.setSpeed(60);
  yAxis.setSpeed(60);
  zAxis.setSpeed(60);
}

void loop() {
  // move the motors to the desired positions:
  xAxis.step(100);
  yAxis.step(100);
  zAxis.step(100);
  delay(1000);  // wait one second

  // move the motors back to their original positions:
  xAxis.step(-100);
  yAxis.step(-100);
  zAxis.step(-100);
  delay(1000);  // wait one second
}