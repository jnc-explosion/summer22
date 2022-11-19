#define LIMIT_TIME

#include <Arduino.h>
#include <MsTimer2.h>
#include "GameCtl.h"
#include "DispCtl.h"

DispCtl dctl=DispCtl();

GameCtl::GameCtl(int seed){
  pinMode(2,INPUT_PULLUP);  // -+- [interrupts]
  pinMode(3,INPUT_PULLUP);  // -+
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  sosumap={0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0}
  cycling=false;
  value[0]=seed%10;
  value[1]=(seed+analogRead(1))%10;
  sub=randomise(seed)%2;
  sosuka=issosu();
  time=LIMIT_TIME;
  points=0;
}

void GameCtl::change(){
  value[0]=randomise(9);
  value[1]=randomise(9)%value[0];
}

void GameCtl::cycle(){
  cycling=true;
  change();
  dctr.change(1,value[0],value[1]);
  MsTimer2::set(100, reloadTime);
  MsTimer2::start();
  while(time<0){
    if(!cycling){
      MsTimer2::stop();
      exact();
      time=LIMIT_TIME;
      delay(4000);
      return;
    }
  }
  over();
}

void GameCtl::reloadTime(){
  time--;
  gseg.change(0,time%10);
  gseg.reflect();
  return;
}

void GameCtl::over(){
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

void GameCtl::swget(){
  if(!cycling) return;
  swstate=(digitalRead(2)==1);
  return;
}

void GameCtl::confirm(){
  cycling=false;
}

int GameCtl::randomise(int limit){
  if(limit>value[0]) randomSeed(analogRead(0));
  return random(0, limit);
}

bool GameCtl::issosu(){
  int ans=value[0];
  if(sub){
    ans-=value[1];
  }else{
    ans+=value[1];
  }
  return sosumap[ans];
}

void GameCtl::exact(){
  if(sosuka&&swstate){
    points++;
    return;
  }else{
    over();
  }
}
