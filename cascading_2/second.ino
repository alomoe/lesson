#include <SoftwareSerial.h>
SoftwareSerial mySerial(13, 12); // RX, TX

int pins[7]={8,7,6,5,4,3,2};

byte numbers[10] = { B11111100, B01100000, B11011010, B11110010, B01100110,
B10110110, B10111110, B11100000, B11111110, B11100110};

void setup() {
Serial.begin(9600);
while (!Serial) { }
Serial.println("Goodnight PC!");
mySerial.begin(9600);
mySerial.println("Hello, budy?");
}

void loop() {
 if (mySerial.available()){
  f=(mySerial.read()-'0');
    for(int i=0;i<7;i++){
    if(bitRead(numbers[f],7-i)==HIGH)
    digitalWrite(pins[i],HIGH);
    else 
    digitalWrite(pins[i],LOW);
  }
 }
}
