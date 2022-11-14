#include "Culasu.h"
#include <Arduino.h>

Culasu::Culasu(){
  digitalWrite(13,0);
  nowbr=0;
}

void Culasu::inr(){
  nowbr++;
  if(nowbr&0b100000) toz();q
  return;
}

void Culasu::bright(){
  int mask=1;
  for(int i=9; i<=13; i++){
    digitalWrite(i,mask&nowbr);
    mask<<=1;
  }
  return;
}

void Culasu::toz() {
  nowbr=0;
  return;
}
