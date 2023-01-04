int C1 = 2;
int D = 3;
int E = 4;
int F = 5;
int G = 6;
int A = 7;
int B = 8;
int C2 = 9;

void setup() {
  Serial.begin(115200);
  pinMode(C1, INPUT);
  pinMode(D, INPUT);
  pinMode(E, INPUT);
  pinMode(F, INPUT);
  pinMode(G, INPUT);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C2, INPUT);
}

void loop() {
  if (digitalRead(C1)) {
    Serial.println("1");
    delay(100);
  } else if (digitalRead(D)) {
    Serial.println("2");
    delay(100);
  } else if (digitalRead(E)) {
    Serial.println("3");
    delay(100);
  } else if (digitalRead(F)) {
    Serial.println("4");
    delay(100);
  } else if (digitalRead(G)) {
    Serial.println("5");
    delay(100);
  } else if (digitalRead(A)) {
    Serial.println("6");
    delay(100);
  } else if (digitalRead(B)) {
    Serial.println("7");
    delay(100);
  } else if (digitalRead(C2)) {
    Serial.println("8");
    delay(100);
  } else {
    delay(100);
  }
}


