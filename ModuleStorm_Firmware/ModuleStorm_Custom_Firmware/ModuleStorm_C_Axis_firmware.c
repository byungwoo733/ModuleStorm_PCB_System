// here is the code example again in C for a simple firmware for a 3 axis CNC machine using a custom controller board
#include <stdio.h>
#include <stdint.h>

#define NUM_AXES 3
#define X_AXIS 0
#define Y_AXIS 1
#define Z_AXIS 2

// define the number of steps per revolution for each axis:
const uint32_t stepsPerRevolution[NUM_AXES] = {200, 200, 200};

// define the maximum speed for each axis in steps per second:
const uint32_t maxSpeeds[NUM_AXES] = {60, 60, 60};

// define the current position for each axis in steps:
uint32_t currentPositions[NUM_AXES] = {0, 0, 0};

// define the target position for each axis in steps:
uint32_t targetPositions[NUM_AXES] = {0, 0, 0};

// function prototypes:
void moveAxisToPosition(uint8_t axis, uint32_t position);
void setAxisSpeed(uint8_t axis, uint32_t speed);
uint32_t getAxisPosition(uint8_t axis);

int main(void)
{
  // move the X axis to its maximum position:
  moveAxisToPosition(X_AXIS, stepsPerRevolution[X_AXIS]);
  // wait one second:
  delay(1000);
  // move the X axis back to its original position:
  moveAxisToPosition(X_AXIS, 0);
  // repeat the same steps for the Y and Z axes:
  moveAxisToPosition(Y_AXIS, stepsPerRevolution[Y_AXIS]);
  delay(1000);
  moveAxisToPosition(Y_AXIS, 0);
  moveAxisToPosition(Z_AXIS, stepsPerRevolution[Z_AXIS]);
  delay(1000);
  moveAxisToPosition(Z_AXIS, 0);
  return 0;
}

// function to move a specific axis to a target position:
void moveAxisToPosition(uint8_t axis, uint32_t position)
{
  // calculate the number of steps to move:
  int32_t steps = position - currentPositions[axis];
  // move the axis by the appropriate number of steps:
  setAxisPosition(axis, currentPositions[axis] + steps);
}

// function to set the speed of a specific axis:
void setAxisSpeed(uint8_t axis, uint32_t speed)
{
  // limit the speed to the maximum allowed value:
  if (speed > maxSpeeds[axis])
  {
    speed = maxSpeeds[axis];
  }
  // set the speed of the axis using hardware-specific functions:
  // (implementation left as an exercise for the reader)
}

// function to get the current position of a specific axis:
uint32_t getAxisPosition(uint8_t axis)
{
  // get the current position of the axis using hardware-specific functions:
  // (implementation left as an exercise for the reader)
  return currentPositions[axis];
}



/*
moveAxisToPosition(X_AXIS, 0);
// repeat the same steps for the Y and Z axes:
moveAxisToPosition(Y_AXIS, stepsPerRevolution[Y_AXIS]);
delay(1000);
moveAxisToPosition(Y_AXIS, 0);
moveAxisToPosition(Z_AXIS, stepsPerRevolution[Z_AXIS]);
delay(1000);
moveAxisToPosition(Z_AXIS, 0);
return 0;
}

// function to move a specific axis to a target position:
void moveAxisToPosition(uint8_t axis, uint32_t position)
{
// calculate the number of steps to move:
int32_t steps = position - currentPositions[axis];
// move the axis by the appropriate number of steps:
setAxisPosition(axis, currentPositions[axis] + steps);
}

// function to set the speed of a specific axis:
void setAxisSpeed(uint8_t axis, uint32_t speed)
{
// limit the speed to the maximum allowed value:
if (speed > maxSpeeds[axis])
{
speed = maxSpeeds[axis];
}
// set the speed of the axis using hardware-specific functions:
// (implementation left as an exercise for the reader)
}

// function to get the current position of a specific axis:
uint32_t getAxisPosition(uint8_t axis)
{
// get the current position of the axis using hardware-specific functions:
// (implementation left as an exercise for the reader)
return currentPositions[axis];
}