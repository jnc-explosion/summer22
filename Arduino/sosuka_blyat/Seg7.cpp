#include <Arduino.h>
#include "Seg7.h"

Seg7::Seg7(int datpin, int clkpin, int opepin, bool disping, bool updown){
  byte digits[]={
    0b11111100, // 0
    0b11000000, // 1
    0b11011010, // 2
    0b11110010, // 3
    0b01100110, // 4
    0b10110110, // 5
    0b10111110, // 6
    0b11100100, // 7
    0b11111110, // 8
    0b11110110, // 9
  }
  pins[0] = datpin;
  pins[1] = clkpin;
  pins[2] = opepin;
  for(int i=0;i<3;i++){
    pinMode(pins[i],OUTPUT);
  }
  change(0,0);
  change(1,0);
  enable = disping;
  ud=updown;
}

void Seg7::change(int which,int disp){
  status[which] = disp;
}

void Seg7::display(bool enbl){
  enable = enbl;
}

virtual void Seg7::reflect(){
  digitalWrite(pins[1],0);
  digitalWrite(pins[2],enable);
  for(int nowdig=numdig-1;nowdig>=0;nowdig--){
    byte huhyuu = digits[status[nowdig]];
    for(byte mask=0b10000000;mask!=0;mask>>=1){
      digitalWrite(pins[1],0);
      digitalWrite(pins[0],(huhyuu&mask)^ud);
      digitalWrite(pins[1],1);
    }
  }
  digitalWrite(pins[1],0);
}
