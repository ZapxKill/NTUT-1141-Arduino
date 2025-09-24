const int pin[5] = {2, 4, 6, 8, 10};
int j=0, add=1;;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<5;i++){
    pinMode(pin[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<=5;i+=1){
    digitalWrite(pin[i], 0);
  }
  digitalWrite(pin[j], 1);
  j+=add;
  if(j >= 5){
    add = -1;
  }
  if(j <= 0){
    add = 1;
  }
  delay(50);
}
