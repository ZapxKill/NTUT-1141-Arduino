const int pin[3] = {9,10,11};
unsigned int blinkTimer = 0;
unsigned int previousBlinkTime = 0;
int blinkDelay = 1000;
int led = 0;
int d = 1;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<3;i++){
    pinMode(pin[i], OUTPUT);
  }
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  blinkTimer = millis();
  blinkDelay = analogRead(A0);
  if(digitalRead(2) == 0){
    delay(50);
    if(digitalRead(2) == 0){
      d *= -1;
      Serial.println(d);
      while(digitalRead(2)==0);
    }
  }
  if(blinkTimer > previousBlinkTime + blinkDelay){
    for(int i=0;i<3;i++){
      digitalWrite(pin[i], 1);
    }
    if(led >= 3){
      for(int i=0;i<3;i++){
        digitalWrite(pin[i], 0);
      }
      led=0;
    }
    else if(led < 0){
      for(int i=0;i<3;i++){
        digitalWrite(pin[i], 0);
      }
      led = 2;
    }
    else{
      digitalWrite(pin[led], 0);
      led+=d;
    }
    Serial.println(led);
    previousBlinkTime = blinkTimer;
  }
}
