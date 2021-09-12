RES ARRAY 4 RES 330 OHM 5SIP

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

Then:
https://www.instructables.com/Program-an-ATtiny44458485-with-Arduino/

The code is Simon-says.ino in this repository.

Parts: 
U1: ATTiny44.  Digikey: ATTINY44-20PU 
RN1: RES ARRAY 4 RES 3.3K OHM 5SIP Digikey: 4605X-101-332LF
RN2: RES ARRAY 4 RES 330 OHM 5SIP Digikey: 4605X-101-331LF
Red, Blue, Green, Yellow LEDs
4.7uF 25V Capacitor Digikey: 732-8624-1-ND
Amber LED:C503B-ACN-CY0Z0252-030CT-ND
Blue LED: C503B-BCN-CV0Z0461-ND
Green LED: 2197-NTE30141-ND
Red LED: C503B-RAN-CA0B0AA1-ND
4 Switches: SWITCH TACTILE SPST-NO 0.05A 12V Digikey: PTS645SH50-2 LFS
