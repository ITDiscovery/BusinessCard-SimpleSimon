# BusinessCard-SimpleSimon
Simple Simon memory game circuit and code via ATTiny44 

Assembly Notes:

1. I recommend adding a electrolytic capacitor across P1-1 to P1-6 for noisy power supplies.
2. When installing the pushbutton switchesm, that there is a trace connecting the two common poles.
3. When installing the LED's, the flat side of the LED goes towards the label.
4. It's easier to program the ATTiny44 via a breadboard than in circuit, but the board layout does add a header to make that easy. Just make sure to remove the speaker (which shares the MISO programming line) before trying to program in circuit.

Programming the ATTiny44:

Connect a Ardunio Uno to the ATTiny44:  
Arduino D13 -> Pin 9 on chip (P1-2 on board) SCLK
Arduino D12 -> Pin 8 on chip (P1-3 on board) MISO
Arduino D11 -> Pin 7 on chip (P1-4 on board) MOSI
Arduino D10 -> Pin 4 on chip (P1-5 on board) RESET
Arduino 5V  -> Pin 1 on chip (P1-1 on board) Vcc
Arduino Gnd -> Pin 14 on chip (P1-5 on board) Gnd

Follow these instructions: https://www.instructables.com/Program-an-ATtiny44458485-with-Arduino/

The code is SimpleSimon.ino in this repository.
