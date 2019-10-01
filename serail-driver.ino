#include "Mouse.h"
#include "Keyboard.h"

const char SIMPLE_CLICK =   'C';
const char RIGHT_PRESS =    'P';
const char RIGHT_RELEASE =  'R';

const char MOVE_X =         'X';
const char MOVE_Y =         'Y';

const char UN_X =           'Z';
const char UN_Y =           'U';

const char KEYBOARD =       'K';

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

    switch(input) {
        case MOVE_X:
            Mouse.move(dMove, 0, 0);
            break;
        case MOVE_Y:
            Mouse.move(0, dMove, 0);
            break;
        case UN_X:
            Mouse.move(-dMove, 0, 0);
            break;
        case UN_Y:
            Mouse.move(0, -dMove, 0);
            break;
        case SIMPLE_CLICK:
            Mouse.click();
            break;
        case RIGHT_PRESS:
            Mouse.press(MOUSE_RIGHT);
            break;
        case RIGHT_RELEASE:
            Mouse.release(MOUSE_RIGHT);
            break;

    }
//     if(input == MOVE_X){
//       Mouse.move(dMove, 0, 0);
//       input = '0';
//     }
//     if(input == MOVE_Y){
//       Mouse.move(0, dMove, 0);
//       input = '0';
//     }
//    if(input == UN_X){
//       Mouse.move(-dMove, 0, 0);
//       input = '0';
//     }
//     if(input == UN_Y){
//       Mouse.move(0, -dMove, 0);
//       input = '0';
//     }
//     if(input == SIMPLE_CLICK){
//       Mouse.click();
//       input = '0';
//     }
    
//     if (input == RIGHT_PRESS){
//       Mouse.press(MOUSE_RIGHT); 
//       input = '0';
//     }
    
//     if (input == RIGHT_RELEASE){
//       Mouse.release(MOUSE_RIGHT); 
//       input = '0';
//     }
    if (input == KEYBOARD){
      Serial.write(input);
      if(Serial.available() > 0 && input == 'K') { // why serial check at avaliable 
        char key = Serial.read();
        if (key == 'D') {
          Keyboard.press(0XD9);
          Keyboard.releaseAll();
        }else if (key == 'U') {
          Keyboard.press(0XDA);
          Keyboard.releaseAll();
        } else if (key == 'E') {
          Keyboard.press(0xB0);
          Keyboard.releaseAll();
        } else {
          Keyboard.print(key);
        }
      }
    }
    input = '0';
  }
}

