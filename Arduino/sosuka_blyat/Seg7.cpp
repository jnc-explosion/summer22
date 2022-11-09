#include "Seg7.h"

Seg7::Seg7(int datpin, int clkpin, int opepin, int numof, int &dispval[], bool disping){
  pins={datpin, clkpin, opepin};
  for(int i=0;i<3;i++){
    pinMode(pins[i],OUTPUT);
  }
  numdig = numof;
  status = new int[numof];
  status = dispval;
  enable = disping;
}

Seg7::change(int which,int disp){
  if(numdig <= which) return;
  status[which] = disp;
}

Seg7::display(bool enbl){
  enable = enbl;
}

Seg7::reflect(){
  digitalWrite(pins[1],0);
  digitalWrite(pins[2],enable);
  for(int nowdig=numdig-1;nowdig>=0;nowdig--){
    byte huhyuu = digits[status[nowdig]];
    for(byte mask=0b10000000;mask!=0;mask>>=1){
      digitalWrite(pins[0],huhyuu&mask);
      digitalWrite(pins[1],1);
      digitalWrite(pins[1],0);
    }
  }
}
