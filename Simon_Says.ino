/*Simon Says game. Now with sound effects. 

Originaly made by Robert Spann
Code trimmed and sound effects added by digimike

Buttons are to be set on there designated pins without pull down resistors
and connected to ground rather then +5. 

Updated for circuit board on a business card by Peter Nichols (peter.nichols@itdiscovery.info)
for use on ATTiny44, removed tone library call so that ATTinyCore by Spence Konde could be used)
See https://github.com/SpenceKonde/ATTinyCore . Modified slightly to increase randomness and allow for 4 light.

*/
#define NOTE_C3  131
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_C5  523
#define NOTE_E5  659

int note[] = {NOTE_C4, NOTE_C4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5};
int duration[] = {100, 100, 100, 300, 100, 300};

boolean button[] = {1, 0, 2, 3}; 
//Inputs: SW-R (HW Pin 12), SW-G (HW Pin 13), SW-B (HW Pin 11), SW-Y (HW Pin 10) 

boolean ledpin[] = {7, 8, 9, 10};  // LED pins
//Outputs: Red (HW Pin 6), Green (HW Pin 5), Blue (HW Pin 3), Yellow (HW Pin 2)

int speakerpin = 5;
int turn = 0;  // turn counter
int buttonstate = 0;  // button state checker
int rdmseed = 0;
int randomArray[32]; //Intentionally long to store up to 100 inputs (doubtful anyone will get this far)
int inputArray[32];


void setup() 
{

  pinMode(speakerpin, OUTPUT);
  for(int x=0; x<4; x++)  // LED pins are outputs
  {
    pinMode(ledpin[x], OUTPUT);
    pinMode(button[x], INPUT);  // button pins are inputs
    digitalWrite(button[x], HIGH);  // enable internal pullup; buttons start in high position; logic reversed
  }
}
 
void loop() 
{   
  rdmseed++;
  if (rdmseed > 100)
  {
    rdmseed = 0;
  }
  for (int y=0; y<=31; y++)
  {
    digitalWrite(ledpin[0], HIGH);
    digitalWrite(ledpin[1], HIGH);
    digitalWrite(ledpin[2], HIGH);
    digitalWrite(ledpin[3], HIGH);
  
    for (int thisNote = 0; thisNote < 6; thisNote ++) {
     // play the next note:
     tone(speakerpin,note[thisNote],duration[thisNote]);
     delay(25);
    }
    
    digitalWrite(ledpin[0], LOW);
    digitalWrite(ledpin[1], LOW);
    digitalWrite(ledpin[2], LOW);
    digitalWrite(ledpin[3], LOW);
    delay(1000);
  
    for (int y=turn; y <= turn; y++)
    { //Limited by the turn variable
      randomArray[y] = random(0, 4); //Assigning a random number (0-3) to the randomArray[y], y being the turn count
      for (int x=0; x <= turn; x++)
      {      
        for(int y=0; y<4; y++)
        {
      
          if (randomArray[x] == 0 && y == 0) 
          {  //if statements to display the stored values in the array
            digitalWrite(ledpin[y], HIGH);
            tone(speakerpin,NOTE_G3, 100);
            delay(400);
            digitalWrite(ledpin[y], LOW);
            delay(100);
          }

          if (randomArray[x] == 1 && y == 1) 
          {
            digitalWrite(ledpin[y], HIGH);
            tone(speakerpin,NOTE_A3, 100);
            delay(400);
            digitalWrite(ledpin[y], LOW);
            delay(100);
          }
  
          if (randomArray[x] == 2 && y == 2) 
          {
            digitalWrite(ledpin[y], HIGH);
            tone(speakerpin,NOTE_B3, 100);
            delay(400);
            digitalWrite(ledpin[y], LOW);
            delay(100);
          }

          if (randomArray[x] == 3 && y == 3) 
          {
            digitalWrite(ledpin[y], HIGH);
            tone(speakerpin,NOTE_C4, 100);
            delay(400);
            digitalWrite(ledpin[y], LOW);
            delay(100);
          }
        }
      }
    }
    input();
  }
}
 
 
 
void input() { //Function for allowing user input and checking input against the generated array

  for (int x=0; x <= turn;)
  { //Statement controlled by turn count

    for(int y=0; y<4; y++)
    {
      
      buttonstate = digitalRead(button[y]);
    
      if (buttonstate == LOW && y == 0)
      { //Checking for button push
        randomSeed(rdmseed); 
        //Added to generate "more randomness" with the randomArray for the output function
        //Based on user first key input
        digitalWrite(ledpin[0], HIGH);
        tone(speakerpin,NOTE_G3, 100);
        delay(200);
        digitalWrite(ledpin[0], LOW);
        inputArray[x] = 0;
        delay(250);
        if (inputArray[x] != randomArray[x]) { //Checks value input by user and checks it against
          fail();                              //the value in the same spot on the generated array
        }                                      //The fail function is called if it does not match
        x++;
      }
       if (buttonstate == LOW && y == 1)
      {
        digitalWrite(ledpin[1], HIGH);
        tone(speakerpin,NOTE_A3, 100);
        delay(200);
        digitalWrite(ledpin[1], LOW);
        inputArray[x] = 1;
        delay(250);
        if (inputArray[x] != randomArray[x]) {
          fail();
        }
        x++;
      }

      if (buttonstate == LOW && y == 2)
      {
        digitalWrite(ledpin[2], HIGH);
        tone(speakerpin,NOTE_B3, 100);
        delay(200);
        digitalWrite(ledpin[2], LOW);
        inputArray[x] = 2;
        delay(250);
        if (inputArray[x] != randomArray[x]) {
          fail();
        }
        x++;
      }

      if (buttonstate == LOW && y == 3)
      {
        digitalWrite(ledpin[3], HIGH);
        tone(speakerpin,NOTE_C4, 100);
        delay(200);
        digitalWrite(ledpin[3], LOW);
        inputArray[x] = 3;
        delay(250);
        if (inputArray[x] != randomArray[x]) 
        {
          fail();
        }
        x++;
      }
    }
  }
  delay(500);
  turn++; //Increments the turn count, also the last action before starting the output function over again
}

void fail() { //Function used if the player fails to match the sequence
 
  for (int y=0; y<=2; y++)
  { //Flashes lights for failure
    
    digitalWrite(ledpin[0], HIGH);
    digitalWrite(ledpin[1], HIGH);
    digitalWrite(ledpin[2], HIGH);
    digitalWrite(ledpin[3], HIGH);
    tone(speakerpin,NOTE_G3, 300);
    delay(200);
    digitalWrite(ledpin[0], LOW);
    digitalWrite(ledpin[1], LOW);
    digitalWrite(ledpin[2], LOW);
    digitalWrite(ledpin[3], LOW);
    tone(speakerpin,NOTE_C3, 300);
    delay(200);
  }
  delay(500);
  turn = -1; //Resets turn value so the game starts over without need for a reset button
}
