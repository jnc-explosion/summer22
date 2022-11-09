#include <Arduino.h>
#include <MsTimer2.h>
#include "GameCtl.h"
#include "Seg7.h"
#include "Seg7dot.h"

GameCtl::GameCtl(int seed){
  Seg7dot pseg(6,7,8,2,0,true);
  Seg7 gseg(9,10,11,2,0,false);
  pinMode(2,INPUT_PULLUP);  // -+- [interrupts]
  pinMode(3,INPUT_PULLUP);  // -+
  pinMode(19,INPUT_PULLUP); // -+
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  sosumap={0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0}
  cycling=false;
  value[0]=seed%10;
  value[1]=(seed+analogRead(1))%10;
  sub=randomise(seed)%2;
  sosuka=issosu();
  time=99;
  points=0;
}

GameCtl::chanval(){
  value[0]=randomise(9);
  value[1]=randomise(9)%value[0];
}

GameCtl::chandisp(){
  gseg.change(0,value[0]);
  pseg.change(1,value[1]);
  gseg.reflect();
  pseg.reflect();
}

GameCtl::cycle(){
  cycling=true;
  gseg.display(true);
  chanval();
  chandisp();
  MsTimer2::set(100, reloadTime);
  MsTimer2::start();
  while(time<0){
    if(!cycling){
      MsTimer2::stop();
      exact();
      time=99;
      gseg.display(false);
      delay(4000);
      return;
    }
  }
  over();
}

GameCtl::reloadTime(){
  time--;
  gseg.change(0,time%10);
  gseg.reflect();
  return;
}

GameCtl::over(){
  gseg.display(false);
  pseg.change(0,points/10);
  pseg.change(1,points%10);
  gseg.reflect();
  pseg.reflect();
  while(1){
    static bool ketsu=true;
    pseg.display(ketsu);
    ketsu=~ketsu;
    delay(1000);
  }
}

GameCtl::swget(){
  if(!cycling) return;
  swstate=(digitalRead(2)==1);
  return;
}

GameCtl::confirm(){
  cycling=false;
}

int randomise(int limit){
  if(limit>value[0]) randomSeed(analogRead(0));
  return random(0, limit);
}

bool issosu(){
  int ans=value[0];
  if(sub){
    ans-=value[1];
  }else{
    ans+=value[1];
  }
  return sosumap[ans];
}

GameCtl::swcut(){
  digitalWrite(4,0);
  digitalWrite(5,0);
}

GameCtl::swchange(){
  digitalWrite(4+(int)swstate, 1);
  digitalWrite(5-(int)swstate, 0);
}

GameCtl::exact(){
  if(sosuka&&swstate){
    points++;
    return;
  }else{
    over();
  }
}
