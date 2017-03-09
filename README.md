# Nixie Driver

This driver allows you to display a number on a serie of nixie tubes corrected via shift registers (ex. 74HC595N) and controlled throught BCD to decimal converters (ex. K155ID1).
The display is thus made transparent using the method:
```sh
NixieDriver nixies = NixieDriver(latchPin, clockPin, dataPIn, NUMBER_OF_NIXIES);
nixies.display(2017);
```

# Usage

1. Connect your shift registers in serial to your arduino
    + example: https://www.arduino.cc/en/Tutorial/ShiftOut
2. Connect your BCD-decimal converters to your shift registers. 0,1,2,3 pins from shift registers goes to A,B,C,D pins of the BCD. 4,5,6,7 to A,B,C,D of the next one and so on. 
    + example: https://i.stack.imgur.com/imeuM.png

NOTE: first bytes are for lower decimal nixie tube. The more you add registers and BCD, the bigger the number you will be able to display.
