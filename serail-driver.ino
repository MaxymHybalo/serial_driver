#include "Mouse.h"
#include "Keyboard.h"

const char SIMPLE_CLICK =     'C';
const char RIGHT_PRESS =      'P';
const char RIGHT_RELEASE =    'R';

const char MOVE_X =           'X';
const char MOVE_Y =           'Y';

const char UN_X =             'Z';
const char UN_Y =             'U';

const char KEYBOARD =         'K';
const char RELEASE_KEYBOARD = 'Q';

const char L_SHIFT = 's';
const char L_ALT = 'a';
const char L_CTRL = 'c';
const char TAB = 't';

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
//      TODO check why it s writed
//      Serial.write('C');
      input = '0';
    }
    
    if (input == RIGHT_PRESS){
      Mouse.press(MOUSE_RIGHT); 
      input = '0';
    }
    
    if (input == RIGHT_RELEASE){
      Mouse.release(MOUSE_RIGHT); 
      input = '0';
    }

   if(input == 'Q') {
        Keyboard.releaseAll();
    }
    if (input == KEYBOARD){
//      Serial.write(input);
 
      if(Serial.available() > 0 && input == 'K') {
        char key = Serial.read();
        if(key == 'Q') {
          Keyboard.releaseAll();
        }
        if (key == 'D') {
          Keyboard.press(0XD9);
        }else if (key == 'U') {
          Keyboard.press(0XDA);
        } else if (key == 'E') {
          Keyboard.press(0xB0);
        } else if (key == 's') {
          Keyboard.press(KEY_LEFT_SHIFT);
        } else if (key == 'a') {
          Keyboard.press(KEY_LEFT_ALT);
        } else if (key == 'c') {
          Keyboard.press(KEY_LEFT_CTRL);
        } else if (key == 't') {
          Keyboard.press(KEY_TAB);
        } else {
          Keyboard.press(key);
        }
        input = '0';
      }
    } else {
      input = '0';
    }
  }
}

