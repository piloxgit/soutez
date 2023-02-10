#define bits 10
#define minNum 0
#define maxNum 1024
int ledBar[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void setup() {
  for (int i = 0; i < bits; i++) {
    pinMode(ledBar[i], OUTPUT);
    digitalWrite(ledBar[i], HIGH);
    delay(50);
  }
  delay(500);
  for (int i = 0; i < bits; i++) {
    digitalWrite(ledBar[i], LOW);
    delay(50);
  }
  Serial.begin(9600);
  Serial.println("Zadejte číslo v intervalu <0,1023>:  ");
}

void loop() {
  if (Serial.available()) {
    String decNum = Serial.readString();
    int decNumInt = decNum.toInt();
    if (decNumInt >= minNum && decNumInt < maxNum) {
      String binNum = String(decNumInt, BIN);
      int leng = binNum.length();
      for (int i = 0; i < bits - leng; i++) {
        binNum = "0" + binNum;
      }
      Serial.print(decNum);
      Serial.print(" = ");
      Serial.println(binNum);
      for (int i = 0; i < bits; i++) {
        if (binNum[i] == '1') {
          digitalWrite(ledBar[i], HIGH);
        }
        if (binNum[i] == '0') {
          digitalWrite(ledBar[i], LOW);
        }
      }
    }
    else {
      Serial.println("Zadali jste číslo mimo rozsah.");
      Serial.println("Zadejte číslo v intervalu <0,1023>:  ");
    }
  }
}
