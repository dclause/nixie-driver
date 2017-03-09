#include "NixieDriver.h"

// Sets the pins used for communication with the shift register.
#define LATCH_PIN 3
#define CLOCK_PIN 4
#define DATA_PIN 2

// Total number of Nixies on device.
#define SIZE 4

// The displayed value.
int currentDisplay;

// The Nixie Driver.
NixieDriver nixies = NixieDriver(LATCH_PIN, CLOCK_PIN, DATA_PIN, SIZE);

void setup() {
  // Initilize current display.
  currentDisplay = 0;
}

void loop() {
  nixies.display(currentDisplay);
  currentDisplay++;
  delay(100);
}