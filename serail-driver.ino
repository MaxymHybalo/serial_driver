#include "Mouse.h"
#include "Keyboard.h"

const char SIMPLE_CLICK = 'C';

const char MOVE_X = 'X';
const char MOVE_Y = 'Y';

const char UN_X = 'Z';
const char UN_Y = 'U';

const char KEYBOARD = 'K';

char input = '0';

int dMove = 2;

void setup(){
  Serial.begin(9600);
  Mouse.begin();
  Keyboard.begin();
}

void loop(){
  if(Serial.available() > 0){
    if(input == '0'){
      input = Serial.read();
    }
    if(input == MOVE_X){
      Mouse.move(dMove, 0, 0);
      input = '0';
    }
    if(input == MOVE_Y){
      Mouse.move(0, dMove, 0);
      input = '0';
    }
   if(input == UN_X){
      Mouse.move(-dMove, 0, 0);
      input = '0';
    }
    if(input == UN_Y){
      Mouse.move(0, -dMove, 0);
      input = '0';
    }
    if(input == SIMPLE_CLICK){
      Mouse.click();
      Serial.write('C');
      input = '0';
    } 
    if (input == KEYBOARD){
      Serial.write(input);
      if(Serial.available() > 0 && input == 'K') {
        char key = Serial.read();  
        Serial.write(key);
        Keyboard.print(key);
        input = '0';
      }
    } else {
      input = '0';
    }
  }
}




