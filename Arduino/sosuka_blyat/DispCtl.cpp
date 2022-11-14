#include <Arduino.h>
#include "DispCtl.h"
#include "Seg7.h"
#include "Seg7dot.h"

DispCtl::DispCtl(){
  for(int i=30;i<=42;i++){
    pinMode(i,OUTPUT);
  }
}