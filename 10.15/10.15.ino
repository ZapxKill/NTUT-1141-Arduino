int pin[3] = {9, 10, 11};
unsigned lastPressTime, moodDecreaseTime, bt, t= 0;
int mood, pressed = 0;
bool droppingMood = false;
const int nmood = 10;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<3;i++){
    pinmode(i, OUTPUT);
  }
  mood = nmood;
}

void loop() {
  t = millis();
  if(digitalRead(2) == 1){
    pressed = 0;
  }
  // put your main code here, to run repeatedly:
  if(digitalRead(2) == 0 &&  pressed == 0){
    bt = t; 
    pressed = 1;
  }
  if(pressed == 1 && t - bt > 50){
    
    lastPressTime = t;
    droppingMood = false;
    pressed = 2;
    mood++;
    if(mood > 20){
      mood = 20;
    }
  }
  if(t - lastPressTime > 5000){
    moodDecreaseTime = t;
    droppingMood = true;
  }
  if(droppingMood && t - moodDecreaseTime > 1000){
    moodDecreaseTime = t;
    mood--;
    if(mood < 0){
      mood = 0;
    }
  }
  
  float brightness = 255 / 10.0;
  if(nood >= nmood){
    analogWrite(9, 255);
    analogWrite(10, brightness * (mood - nmood));
    analogWrite(11, 255 - brightness * (mood - nmood));
  }
  else{
    analogWrite(9, 255 - brightness * (mood - nmood));
    analogWrite(10, brightness * (mood - nmood));
    analogWrite(11, 255);
  }
}
