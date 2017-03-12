#ifndef NixieDriver_h
#define NixieDriver_h

#include "Arduino.h"

/**
 * Displays a given number on a set of Nixie tubes, mounted in serial
 * via shift registers (example 74hc595) and BCD to decimal converter (example 74hc595).
 *
 * See the README for further documentation.
 */
class NixieDriver {
  
  public:

    /**
     * NixieDriver constructor.
     *
     * @param latchPin
     *   The LATCH arduino pin number.
     * @param clockPin
     *   The CLOCK arduino pin number.
     * @param dataPin
     *   The DATA arduino pin number.
     * @param numberOfNixies
     *   The number of Nixies available.
     */
    NixieDriver(int latchPin, int clockPin, int dataPin, int numberOfNixies);

    /**
     * Displays the given value on the Nixies.
     *
     * @param value
     *   An integer number to be displayed.
     */
    void display(int number);
    
    /**
     * Clears the display, ie light of all Nixies.
     */
    void clear();
    
  private:
  
    /**
     * The LATCH arduino pin number.
     */
		uint8_t _latchPin;

    /**
     * The CLOCK arduino pin number.
     */
    uint8_t _clockPin;

    /**
     * The DATA arduino pin number.
     */
    uint8_t _dataPin;
    
    /**
     * The size of the word to display on Nixies.
     */
    uint8_t _sizeOfWord;
		
    /**
     * The number of Nixies available.
     */
    uint8_t _totalDisplaySize;

		/**
		 * Extracts the value of the given digit from a given number value.
     *
     * NOTE: If the digit requested is superior to the number of digits
     *       in the given value, 15 is returned, meaning no display.
     *
     * @param value
     *   The given value to extract digit from.
     * @param digit
     *   The digit to extract.
     *
     * @return int | 15
     *   The extracted digit value.
		 */
		int extractDigitValue(int value, int digit);

    /**
		 * Calculates the number of digits in a given integer value.
     *
     * @param number
     *   The given integer value.
     *
     * @return int
     *   The number of digits in the given number.
		 */
		int numberOfDigit(int number);
};

#endif