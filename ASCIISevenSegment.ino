// ASCIISevenSegment for Arduino
//
// Pedro Jose Pereira Vieito <pvieito@gmail.com>
// 
// The seven segments are connected in the pins 2 to 9. 
// More information here: http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
// 
// Released under the MIT License.

byte sevenSegment[][7] = { { 1,1,1,1,1,1,0 },  // = 0
                             { 0,1,1,0,0,0,0 },  // = 1
                             { 1,1,0,1,1,0,1 },  // = 2
                             { 1,1,1,1,0,0,1 },  // = 3
                             { 0,1,1,0,0,1,1 },  // = 4
                             { 1,0,1,1,0,1,1 },  // = 5
                             { 1,0,1,1,1,1,1 },  // = 6
                             { 1,1,1,0,0,0,0 },  // = 7
                             { 1,1,1,1,1,1,1 },  // = 8
                             { 1,1,1,0,0,1,1 },  // = 9
                             { 1,1,1,0,1,1,1 },  // A
                             { 1,1,1,1,1,1,1 },  // B
                             { 1,0,0,1,1,1,0 },  // C
                             { 1,1,1,1,1,1,0 },  // D
                             { 1,0,0,1,1,1,1 },  // E
                             { 1,0,0,0,1,1,1 },  // F
                             { 1,0,1,1,1,1,1 },  // G
                             { 0,1,1,0,1,1,1 },  // H
                             { 0,1,1,0,0,0,0 },  // I
                             { 0,1,1,1,0,0,0 },  // J
                             { 0,1,1,0,1,1,1 },  // K
                             { 0,0,0,1,1,1,0 },  // L
                             { 1,1,1,0,1,1,0 },  // M
                             { 1,1,1,0,1,1,0 },  // N
                             { 1,1,1,1,1,1,0 },  // O
                             { 1,1,0,0,1,1,1 },  // P
                             { 1,1,1,1,1,1,0 },  // Q
                             { 1,1,1,0,1,1,1 },  // R
                             { 1,0,1,1,0,1,1 },  // S
                             { 1,1,1,0,0,0,0 },  // T
                             { 0,1,1,1,1,1,0 },  // U
                             { 0,1,1,1,1,1,0 },  // V
                             { 0,1,1,1,1,1,1 },  // W
                             { 0,1,1,0,1,1,1 },  // X
                             { 0,1,0,0,1,1,1 },  // Y
                             { 1,1,0,1,1,0,1 },  // Z
                             { 0,0,0,0,0,0,0 },  // SPACE
                           };
float voltage;
int number;

void setup() {                
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}
    
void sevenSegWrite(byte digit) {
  Serial.println(char(digit));
  byte pin = 2;
  if (digit == 32) {
    digit = 36;
  }
  if (digit < 58 and digit > 47) {
    digit -= '0';
  }
  if (digit > 64 and digit < 91) {
    digit = digit - 'A' + 10;
  }
  if (digit > 96) {
    digit = digit - 'a' + 10;
  }
  for (byte segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(pin, sevenSegment[digit][segCount]);
    ++pin;
  }
}

void loop() {
    if (Serial.available()) {
      sevenSegWrite(Serial.read());
    }
    delay(500);
}
