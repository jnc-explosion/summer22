#include <Arduino.h>
#include "DispCtl.h"
#include "Seg7.h"
#include "Seg7dot.h"

DispCtl::DispCtl(){
  for(int i=30;i<=42;i++){
    pinMode(i,OUTPUT);
  }
  Seg7 pseg=Seg7(36,37,38,false,false);
  Seg7dot gseg=Seg7dot(36,37,38,false,false);
  pseg.change(0,0);
  pseg.change(1,0);
  pseg.display(1);
  pseg.reflect();
  gseg.change(0,0);
  gseg.change(1,0);
  gseg.display(1);
  gseg.reflect();
}

void DispCtl::change(int type,int s1,int s2){
  if(type){
    pseg.
  }
}
