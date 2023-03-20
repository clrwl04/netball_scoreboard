/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-library
 *
 * This example:
 *   + uses debounce for multiple buttons.
 *   + reads state of multiple buttons
 *   + detects the pressed and released events of multiple buttons
 */
#include <ezButton.h>
// include the library for MAX72XX
#include "LedControl.h"

//  CLK=11, CS=10, DIN=12, GND=GND, VCC=     
LedControl lc=LedControl(12,11,10,2);
/* we always wait a bit between updates of the display */
unsigned long delaytime=250;// v75

const int BUTTON_NUM = 5;

const int BUTTON_1_PIN = 2;
const int BUTTON_2_PIN = 3;
const int BUTTON_3_PIN = 4;
const int BUTTON_4_PIN = 5;

const int BUTTON_5_PIN = A0 ;


ezButton buttonArray[] = {
	ezButton(BUTTON_1_PIN), 
	ezButton(BUTTON_2_PIN), 
	ezButton(BUTTON_3_PIN), 
	ezButton(BUTTON_4_PIN),
  ezButton(BUTTON_5_PIN)
};

// Team Manor
int man = 0;
int manq = 0; // quater score
// Start digit for Man score display position 
int scoreboardposman = 6;
// Other Team
int opo = 0;
int opoq = 0; // quater score
// Start digit for Opo score display position 
int scoreboardposopo = 3;

//Define game quarter scores
int qtr = 1;
int qtrpos = 0;
int q1pos = 4;
int q1bord = 1;
int q2pos = 0;
int q2bord = 1;
int q3pos = 4;
int q3bord = 2;
int q4pos = 0;
int q4bord = 2;

void setup() {
  Serial.begin(9600);
  /*
  The MAX72XX is in power-saving mode on startup,
  we have to do a wakeup call
  */
  lc.shutdown(0,false);
  lc.shutdown(1,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,1);
  lc.setIntensity(1,1);
  /* and clear the display */
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  // Start Up Flashy :)
  writeArduinoOn7Segment();

  for(byte i = 0; i < BUTTON_NUM; i++){
		buttonArray[i].setDebounceTime(50); // set debounce time to 50 milliseconds
  }

// Set score display to zero both teams
  scoreboard((man), scoreboardposman);
  scoreboard((opo), scoreboardposopo);
  // set the quater display
  qtrboard((qtr), qtrpos, 0, 0);
}

void writeArduinoOn7Segment() {
  lc.setChar(0,7,'a',false);
  delay(delaytime);
  lc.setRow(0,6,0x05);
  delay(delaytime);
  lc.setChar(0,5,'d',false);
  delay(delaytime);
  lc.setRow(0,4,0x1c);
  delay(delaytime);
  lc.setRow(0,3,B00010000);
  delay(delaytime);
  lc.setRow(0,2,0x15);
  delay(delaytime);
  lc.setRow(0,1,0x1D);
  //delay(delaytime);
  //lc.setRow(0,0,B10000000);
  //delay(delaytime);
  //lc.setDigit(0,0,4,true);
  delay(500);
  lc.setIntensity(0,12);
  delay(500);
  lc.setIntensity(0,1);
  delay(500);
  lc.setIntensity(0,12);
  delay(500);
  lc.setIntensity(0,1);
  delay(500);
  lc.setIntensity(0,12);
  delay(500);
  lc.setIntensity(0,1);
  delay(00);
  lc.clearDisplay(0);
  delay(delaytime);
}

void scoreboard(int score, int manOrOpo) {
  // Needs to be passed
  // Score 
  // Display Position
  Serial.print(" Scoreboard: ");
  Serial.println(score);
  char ones = score % 10;
  char tens = score / 10;
  lc.setDigit(0,manOrOpo,ones,false);
  lc.setDigit(0,(manOrOpo + 1),tens,false);
}

void qtrboard(int qtr, int qtrpos, int manq, int opoq) {
  Serial.print(" Current Quater is: ");
  Serial.println(qtr);
  lc.setDigit(0,qtrpos,qtr,false);  //set the qtr counter
  char mones = manq % 10;
  char mtens = manq / 10;
  char qones = opoq % 10;
  char qtens = opoq / 10;
  if(qtr == 2) {
    lc.setDigit(q1bord,(q1pos + 2),mones,true);
    lc.setDigit(q1bord,(q1pos + 3),mtens,false);
    lc.setDigit(q1bord,(q1pos),qones,false);
    lc.setDigit(q1bord,(q1pos + 1),qtens,false);
  }
  if(qtr == 3) {
    lc.setDigit(q1bord,(q2pos + 2),mones,true);
    lc.setDigit(q1bord,(q2pos + 3),mtens,false);
    lc.setDigit(q1bord,(q2pos),qones,false);
    lc.setDigit(q1bord,(q2pos + 1),qtens,false);
  }
  /*
  if(qtr == 4) {
    lc.setDigit(q2bord,(q3pos + 2),mones,true);
    lc.setDigit(q2bord,(q3pos + 3),mtens,false);
    lc.setDigit(q2bord,(q3pos),qones,false);
    lc.setDigit(q2bord,(q3pos + 1),qtens,false);
  }
  if(qtr == 5) {
    lc.setDigit(q2bord,(q4pos + 2),mones,true);
    lc.setDigit(q2bord,(q4pos + 3),mtens,false);
    lc.setDigit(q2bord,(q4pos),qones,false);
    lc.setDigit(q2bord,(q4pos + 1),qtens,false);
  }
  */
}

void loop() {
  for(byte i = 0; i < BUTTON_NUM; i++)
		buttonArray[i].loop(); // MUST call the loop() function first

	//for(byte i = 0; i < BUTTON_NUM; i++) {
		//if(buttonArray[i].isPressed()) {
		//	Serial.print("The button ");
		//	Serial.print(i + 1);
		//	Serial.println(" is pressed");
		//}

    if(buttonArray[0].isPressed()) {
      //man++;
      Serial.print(" Butt 1 pressed ");
      Serial.println(man);
      man++;
      manq++;
      Serial.print(" Updated ");
      Serial.println(man);
      scoreboard(man, scoreboardposman);
      Serial.print(" Butt 1 score ");
      Serial.println(man);
    }
    if(buttonArray[1].isPressed()) {
      //man--;
      Serial.print(" Butt 2 pressed ");
      Serial.println(man);
      if(man == 0) { return;
      }
      man--;
      manq--;
      Serial.print(" Updated ");
      Serial.println(man);
      scoreboard(man, scoreboardposman);
      Serial.print(" Butt 2 score ");
      Serial.println(man);
    }
    if(buttonArray[2].isPressed()) {
      //opo++;
      Serial.print(" Butt 3 pressed ");
      Serial.println(opo);
      opo++;
      opoq++;
      Serial.print(" Updated ");
      Serial.println(opo);
      scoreboard(opo, scoreboardposopo);
       Serial.print(" Butt 3 score ");
      Serial.println(opo);
    }
    if(buttonArray[3].isPressed()) {
      //opo--;
      Serial.print(" Butt 4 pressed ");
      Serial.println(opo);
      if(opo == 0) { return;
      }
      opo--;
      opoq--;
      Serial.print(" Updated ");
      Serial.println(opo);
      scoreboard(opo, scoreboardposopo);
      Serial.print(" Butt 4 score ");
      Serial.println(opo);
    }  
    if(buttonArray[4].isPressed()) {
      //Next qtr
      Serial.print(" Butt 5 pressed ");
      Serial.println(qtr);
      qtr++;
      if(qtr > 4) {qtr = 1;
      }
      qtrboard(qtr, qtrpos, manq, opoq);
      Serial.print(" Butt 5 qtr is ");
      Serial.println(qtr);
      manq = 0;
      opoq = 0;
    }

		//if(buttonArray[i].isReleased()) {
		//	Serial.print("The button ");
		//	Serial.print(i + 1);
		//	Serial.println(" is released");
		//}
	//}
}
