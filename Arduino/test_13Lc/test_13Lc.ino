int value=1000;

void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);
}

void loop() {
  static bool brt=false;
  if(Serial.available()!=0) getval();
  delay(value);
  digitalWrite(13,brt);
  brt=!brt;
}

void getval(){
  value=0;
  while(Serial.available()!=0){
    value*=10;
    Serial.print((byte)Serial.peek()-'0');
    value+=(byte)((byte)Serial.read()-(byte)'0');
  }
  Serial.println();
  Serial.println(value);
}
