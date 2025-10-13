const int pin[3] = {9,10,11};
unsigned int t, lt, bt = 0;

int brightness = 0;
int a = -1;
byte pressed, led = 0;
byte d = 0;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<3;i++){
    pinMode(pin[i], OUTPUT);
  }
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  t = millis();
  // put your main code here, to run repeatedly:
  if(pressed != 0 && digitalRead(2) == 1){
    if(pressed == 1 && t - bt > 50){
      Serial.println("Change Color");
      led++;
      led = (led >= 8) ? 0 : led;
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
      Serial.println("Change Frequency");
      d = (d == 0) ? 1 : 0;
    } 
    pressed = 2;
  }
  if(t - lt > d){
    brightness += a;
  }
  lt = t;
  a = (brightness >= 255) ? a=-1 : a;
  a = (brightness <= 0) ? a=1 : a;
  for(int i=0;i<3;i++){
    if((led >> i) & 1 == 1){
      analogWrite(pin[i], brightness);
    }
    else{
      digitalWrite(pin[i], 1);
    }
  }
}
