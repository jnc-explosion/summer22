#include <Arduino.h>
#include "Seg7.h"
#include "Seg7dot.h"

void Seg7dot::reflect() override{
  digitalWrite(pins[1],0);
  digitalWrite(pins[2],enable);
  for(int nowdig=numdig-1;nowdig>=0;nowdig--){
    byte huhyuu = digits[status[nowdig]];
    if(nowdig==0) huhyuu++;
    for(byte mask=0b10000000;mask!=0;mask>>=1){
      digitalWrite(pins[0],(huhyuu&mask)^ud);
      digitalWrite(pins[1],1);
      digitalWrite(pins[1],0);
    }
  }
}
