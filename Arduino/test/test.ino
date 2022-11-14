#include "Culasu.h"
#include <MsTimer2.h>

Culasu cls = Culasu();

void setup() {
  for(int i=9; i<=13; i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  hikaru();
  delay(100);
}

void hikaru(){
  cls.inr();
  cls.bright();
}
