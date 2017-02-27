#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

int RedPin = 3; // choose the pin for the LED
int GrnPin = 2;   // choose the input pin (for a pushbutton)
int Redval = 0;     // variable for reading the pin status
int Grnval = 0;
int roboState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(RedPin, INPUT);
  pinMode(GrnPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(3),setToStop, FALLING);
  matrix.begin(0x70);
  matrix.drawPixel(7, 7, LED_YELLOW);
  matrix.writeDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  Grnval = digitalRead(GrnPin);
  Redval = digitalRead(RedPin);
  if((Grnval == LOW) & (Redval == HIGH)){
    roboState = 1;
  }
 if(roboState == 1){  
    WriteLocation(1,3,2);
    delay(500);

    WriteLocation(6,0,1);
    delay(500);

    WriteLocation(0,2,0);
    delay(500);

    WriteLocation(4,2,0);
    delay(500);

    WriteLocation(5,1,2);
        delay(500);

    WriteLocation(1,5,1);
    delay(500);
    matrix.clear();
    delay(500);
  }//else if((Grnval == LOW) & (Redval == HIGH)){
//      matrix.drawCircle(3,3, 3, LED_YELLOW);
//      matrix.fillCircle(3,3, 3, LED_YELLOW);
//      matrix.writeDisplay();
//      delay(1000);
//      matrix.clear();
      //skipped: delay(100);
//  }
}
void WriteLocation(int xLoc, int yLoc, int type){
  if (type == 1){
    //Type 1 is to say that there is a tunnel under there
    matrix.drawPixel(xLoc, yLoc, LED_RED);    
  }else if(type == 2){
    //Type 2 is to say that there is a dead end there
    matrix.drawPixel(xLoc, yLoc, LED_YELLOW);
  }else{
    matrix.drawPixel(xLoc, yLoc, LED_GREEN);
  }
  matrix.writeDisplay();
}
void setToStop(){
  roboState = 0;
  matrix.clear();
  matrix.drawCircle(3,3, 3, LED_YELLOW);
 
}

