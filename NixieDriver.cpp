#include "Arduino.h"
#include "NixieDriver.h"

/**
 * { @inheritdoc }
 */
NixieDriver::NixieDriver(int latchPin, int clockPin, int dataPin, int numberOfNixies) {
  _latchPin = latchPin;
  _clockPin = clockPin;
  _dataPin = dataPin;
  _totalDisplaySize = numberOfNixies;
  
  // Sets pins in OUTPUT mode.
  pinMode(_latchPin, OUTPUT);
  pinMode(_dataPin, OUTPUT);
  pinMode(_clockPin, OUTPUT);
}

/**
 * { @inheritdoc }
 */
int NixieDriver::extractDigitValue(int value, int digit) {
  if (digit <= _sizeOfWord) {
    return int(value/(pow(10,digit-1))) - int(value/(pow(10,digit)))*10;
  } else {
    return 15;
  }
}

/**
 * { @inheritdoc }
 */
int NixieDriver::numberOfDigit(int number) {
  return floor( log10( number ) ) + 1;
}

/**
 * { @inheritdoc }
 */
void NixieDriver::display(int number) {
  int valueDisplayed = 0;

  // Computes the size of the word to display.
  _sizeOfWord = numberOfDigit(number);
  
  // Start sending.
  digitalWrite(_latchPin, LOW);
  
  // Loop on all Nixies to set a value.
  for (int i = _totalDisplaySize; i > 0; i--) {
    int digit = extractDigitValue(number, i);
    if (i%2) {
      valueDisplayed += digit;
      shiftOut(_dataPin, _clockPin, MSBFIRST, valueDisplayed);
      valueDisplayed = 0;
    } else {
      digit = digit << 4;
      valueDisplayed += digit;
    }
  }

  // End sending.
  digitalWrite(_latchPin, HIGH);
}

/**
 * { @inheritdoc }
 */
void NixieDriver::clear() {
  // Start sending.
  digitalWrite(_latchPin, LOW);
  // Loop on all Nixies to set a value.
  for (int i = _totalDisplaySize; i >= 0; i = i-2) {
    shiftOut(_dataPin, _clockPin, MSBFIRST, 255);
  }
  // End sending.
  digitalWrite(_latchPin, HIGH);
}