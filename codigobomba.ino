int ESTADO = 0;
int TEMPO = 35;
int fioverde = 9;
int fioverm = 11;
int fioamar = 12;
int buzzer = 5;

void setup() {
  pinMode(fioverde, INPUT);
  pinMode(fioverm, INPUT);
  pinMode(fioamar, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  Serial.print("START");
}

void loop() {

  while (ESTADO == 0 || ESTADO == 1 || ESTADO == 2) {
    temporizador();
    
    if (TEMPO >= 25) {
      apitotempo();
    } else {
      apitorapido();
    }

    if (digitalRead(fioamar) && digitalRead(fioverm) && digitalRead(fioverde)) {
      ESTADO = 0;
    } else if (digitalRead(fioamar) && digitalRead(fioverm) && !digitalRead(fioverde)) {
      ESTADO = 1;
    } else if (!digitalRead(fioamar) && digitalRead(fioverm) && !digitalRead(fioverde)) {
      ESTADO = 2;
    } else if (!digitalRead(fioamar) && !digitalRead(fioverm) && !digitalRead(fioverde)) {
      ESTADO = 3;
    } else if (TEMPO < 1) {
      ESTADO = 4;
    } else {
      ESTADO = 4;
    }
  }

  if (ESTADO == 3) {
    tone(buzzer, 3300);
    delay(50);
    noTone(buzzer);
    delay(250);
    tone(buzzer, 3300);
    delay(50);
    noTone(buzzer);
    Serial.println("ganhou :)");
    delay(10000);
  }

  if (ESTADO == 4) {
    TEMPO = 0;
    boom();
    Serial.println("perdeu :(");
  }
}

void apitotempo() {
  tone(buzzer, 2300);
  delay(50);
  noTone(buzzer);
  delay(500);
}

void apitorapido() {
  tone(buzzer, 3300);
  delay(50);
  noTone(buzzer);
}

void temporizador() {
  TEMPO = TEMPO - 1;
  Serial.println(TEMPO);
  delay(1000);
}

void boom() {
  tone(buzzer, 443);
  delay(500);
  noTone(buzzer);
}