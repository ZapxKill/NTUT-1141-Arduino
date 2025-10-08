const int pin[3] = {9,10,11};
int analogPin = A0;
int led = 0;
int brightness[3] = {0, 0, 0};
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<3;i++){
    pinMode(pin[i], OUTPUT);
  }
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  brightness[led] = map(analogRead(analogPin), 0, 1023, 0 ,255);
  if(digitalRead(2) == 0){
    delay(50);
    if(digitalRead(2) == 0){
      led++;
      if(led>=3){
        led = 0;
      }
      while(digitalRead(2)==0);
    }
  }
  analogWrite(pin[led], brightness[led]);
}
