const int pin[3] = {9,10,11};
unsigned int t, lt, bt = 0;
int brightness = 0;
int a = -1;
byte pressed, led = 1;
bool breathing = false;


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
  t = millis();
  buttonRead();
  // put your main code here, to run repeatedly:
  if(breathing){
    if(t - lt > 1){
      brightness += a;
      lt = t;
    }
    a = (brightness >= 255) ? -1 : a;
    a = (brightness <= 0) ? 1 : a;
    setRGBLed(((led >> 2) & 1) * brightness, ((led >> 1) & 1) * brightness, (led & 1) * brightness);
  }
  else{
    if(t - lt > 1000){
      brightness = (brightness == 255)? 0 : 255;
      lt = t;
    }
    setRGBLed(((led >> 2) & 1) * brightness, ((led >> 1) & 1) * brightness, (led & 1) * brightness);
  }
  
}

void buttonRead(){
  if(pressed != 0 && digitalRead(2) == 1){
    if(pressed == 1 && t - bt > 50){
      Serial.println("Change Color");
      led++;
      led = (led >= 8) ? 1 : led;
      pressed = 2;
    }
    pressed = 0;
    Serial.println("released");
  }
  if(digitalRead(2) == 0 && pressed == 0){
    bt = t; 
    pressed = 1;
    Serial.println("pressed");
  }
  if(pressed == 1 && t - bt > 2000){
    if(digitalRead(2) == 0){
      Serial.println("Change Mode");
      breathing = !breathing;
    } 
    pressed = 2;
  }
}

void setRGBLed(char R, char G, char B){
  analogWrite(9, 255 - R);
  analogWrite(10, 255 - G);
  analogWrite(11, 255 - B);
}

