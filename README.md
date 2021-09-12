RES ARRAY 4 RES 330 OHM 5SIP

1. I recommend adding a electrolytic capacitor across P1-1 to P1-6 for noisy power supplies.
2. When installing the pushbutton switchesm, that there is a trace connecting the two common poles.
3. When installing the LED's, the flat side of the LED goes towards the label.
4. It's easier to program the ATTiny44 via a breadboard than in circuit, but the board layout does add a header to make that easy. Just make sure to remove the speaker (which shares the MISO programming line) before trying to program in circuit.

Programming the ATTiny44:

Connect a Ardunio Uno to the ATTiny44:  
Arduino D13 -> Pin 9 on chip (P1-2 on board) SCLK <br />
Arduino D12 -> Pin 8 on chip (P1-3 on board) MISO <br />
Arduino D11 -> Pin 7 on chip (P1-4 on board) MOSI <br />
Arduino D10 -> Pin 4 on chip (P1-5 on board) RESET <br />
Arduino 5V  -> Pin 1 on chip (P1-1 on board) Vcc <br />
Arduino Gnd -> Pin 14 on chip (P1-5 on board) Gnd <br />

Then:
https://www.instructables.com/Program-an-ATtiny44458485-with-Arduino/

The code is Simon-says.ino in this repository.

Parts: <br />
U1: ATTiny44.  Digikey: ATTINY44-20PU <br />
RN1: RES ARRAY 4 RES 3.3K OHM 5SIP Digikey: 4605X-101-332LF <br />
RN2: RES ARRAY 4 RES 330 OHM 5SIP Digikey: 4605X-101-331LF <br />
Red, Blue, Green, Yellow LEDs <br />
4.7uF 25V Capacitor Digikey: 732-8624-1-ND <br />
Amber LED:C503B-ACN-CY0Z0252-030CT-ND <br />
Blue LED: C503B-BCN-CV0Z0461-ND <br />
Green LED: 2197-NTE30141-ND <br />
Red LED: C503B-RAN-CA0B0AA1-ND <br />
4 Switches: SWITCH TACTILE SPST-NO 0.05A 12V Digikey: PTS645SH50-2 LFS <br />
Speaker: Digikey 433-1212-ND
USB Connector: 1568-1194-ND
