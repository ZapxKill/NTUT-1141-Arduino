const int pin[3] = {9,10,11};
int led = 0;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<5;i++){
    pinMode(pin[i], OUTPUT);
  }
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2) == 0){
    delay(50);
    if(digitalRead(2) == 0){
      led++;
      led = (led == 8) ? 0 : led;
      Serial.println(led);
      while(digitalRead(2) == 0);
    }
  }
  digitalWrite(9, led & 1);
  digitalWrite(10, (led >> 1) & 1);
  digitalWrite(11, (led >> 2) & 1);
}
