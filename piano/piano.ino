int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 7;
int G = 8;
int H = 9;

void setup() {
  Serial.begin(115200);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  pinMode(E, INPUT);
  pinMode(F, INPUT);
  pinMode(G, INPUT);
  pinMode(H, INPUT);
}

void loop() {
  if (digitalRead(A)) {
    Serial.println("0");
    delay(100);
  } else if (digitalRead(B)) {
    Serial.println("1");
    delay(100);
  } else if (digitalRead(C)) {
    Serial.println("2");
    delay(100);
  } else if (digitalRead(D)) {
    Serial.println("3");
    delay(100);
  } else if (digitalRead(E)) {
    Serial.println("4");
    delay(100);
  } else if (digitalRead(F)) {
    Serial.println("5");
    delay(100);
  } else if (digitalRead(G)) {
    Serial.println("6");
    delay(100);
  } else if (digitalRead(H)) {
    Serial.println("7");
    delay(100);
  } else {
    delay(100);
  }
}
