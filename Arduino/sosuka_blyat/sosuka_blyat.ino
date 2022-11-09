#include "GameCtl.cpp"
#include "Seg7.cpp"
#include "Seg7dot.cpp"
#include <MsTimer2.h>

GameCtl game(9315);

void setup() {
  attachInterrupt(0, game.swget, FALLING);
  attachInterrupt(1, game.swget, FALLING);
  attachInterrupt(4, game.confirm, FALLING);
}

void loop() {

}

