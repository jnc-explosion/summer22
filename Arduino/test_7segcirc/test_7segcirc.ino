#define A_CLK 38
#define A_OE 37
#define A_DAT 39
#define B_CLK 35
#define B_OE 34
#define B_DAT 36

void setup() {
  for(int i=34;i<=39;i++){
    pinMode(i,OUTPUT);
  }
  digitalWrite(A_OE,1);
  digitalWrite(B_OE,1);
  digitalWrite(A_CLK,0);
  digitalWrite(B_CLK,0);
  for(int i=0;i<16;i++){
    digitalWrite(A_CLK,0);
    digitalWrite(A_DAT,0);
    digitalWrite(A_CLK,1);
  }
  for(int i=0;i<16;i++){
    digitalWrite(B_CLK,0);
    digitalWrite(B_DAT,1);
    digitalWrite(B_CLK,1);
  }
}

void loop() {
  
}
