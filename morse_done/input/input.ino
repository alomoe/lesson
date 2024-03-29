#define DATA_PIN 2
#define DATA_LEVEL LOW
#define SPACE_LEVEL HIGH
#define DATA false
#define SPACE true
#define DASH_DURATION 3
#define DOT_DURATION 1
#define DURATION 7
#define TU 100

long start_data, start_space;
long duration[100];
bool color[100];
int index = 0;
int previous = SPACE_LEVEL;
String CODES[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
char LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
int NLETTERS = 27;
String code;

void setup() {
  Serial.begin(9600);
  pinMode(DATA_PIN, INPUT);
}

void loop() {
  fill_arays();
  decode_letter();
}

void decode_letter(){
      for(int j = 0; j<index; j++){
        if(duration[j] == DASH_DURATION && color[j] == DATA){
          code+="-";
        }
        if(duration[j] == DOT_DURATION && color[j] == DATA){
          code+=".";
        }
        if(duration[j] == DASH_DURATION && color[j] == SPACE){
          for(int iletter=0; iletter<NLETTERS; iletter++){
            if (code==CODES[iletter]){
              Serial.print(LETTERS[iletter]);
            }
          }   
        }
        if(duration[j] > DASH_DURATION && color[j] == SPACE){
          Serial.print(" ");  
        }
      }
}

void fill_arays() {
  int current = digitalRead(DATA_PIN);
  if (current == DATA_LEVEL && previous == SPACE_LEVEL){
    start_data = millis();
    duration[index] = int((millis() - start_space + 0.5 * TU) / TU);
    color[index]=DATA;
    index++;
  }
  if (current == SPACE_LEVEL && previous == DATA_LEVEL){
    start_space = millis();
    duration[index] = int((millis() - start_data + 0.5 * TU) / TU);
    color[index]=SPACE;
    index++;
  }
  previous = current; 
}
