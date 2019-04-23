int first = 2;
int second = 3;
int third = 4;
int fourth = 5;
int fifth = 6;
int sixth = 7;

int button = 12;

int pressed = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i=first; i<=sixth; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(button, INPUT);
  randomSeed(analogRead(0));
}

void setAllLEDS(int value){
 for (int i=first; i<=sixth; i++) {
  digitalWrite(i, value); 
 }
}

void showNumber(int number){
  digitalWrite(first, HIGH);
  if (number >= 2){
    digitalWrite(second, HIGH);
  }
  if (number >= 3){
    digitalWrite(third, HIGH);
  }
  if (number >= 4){
    digitalWrite(fourth, HIGH);
  }
  if (number >= 5){
    digitalWrite(fifth, HIGH);
  }
  if (number >= 6){
    digitalWrite(sixth, HIGH);
  }
  
}

int throwDice(){
  int randNumber = random(1,7);
  return randNumber;
}

void buildUpTension(){

  //left to right
  for (int i=first; i<=sixth; i++) {
    if (i!=first){
      digitalWrite(i-1,LOW);
    }
    digitalWrite(i, HIGH);
    delay(100);
  }

    for (int i=sixth; i>=first; i--) {
    if (i!=sixth){
      digitalWrite(i+1,LOW);
    }
    digitalWrite(i, HIGH);
    delay(100);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  //if button is pressed - throw the dice
  pressed = digitalRead(button);

  if (pressed == HIGH){
  //remove previous number
    setAllLEDS(LOW);
    buildUpTension();
    int thrownNumber = throwDice();
    showNumber(thrownNumber);
  }
}
