// ASCIISevenSegment for Arduino
//
// Pedro Jose Pereira Vieito <pvieito@gmail.com>
// 
// The seven segments are connected in the pins 2 to 9. 
// More information here: http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
// 
// Released under the MIT License.
//
// Seven segment pins:
//
//      _ 2 (First pin)
//   7 |_| 3 (The middle segment is the pin 8)
//   6 |_| 4
//      5
//

byte sevenSegment[][7] = { { 1,1,1,1,1,1,0 },  // 0
                           { 0,1,1,0,0,0,0 },  // 1
                           { 1,1,0,1,1,0,1 },  // 2
                           { 1,1,1,1,0,0,1 },  // 3
                           { 0,1,1,0,0,1,1 },  // 4
                           { 1,0,1,1,0,1,1 },  // 5
                           { 1,0,1,1,1,1,1 },  // 6
                           { 1,1,1,0,0,0,0 },  // 7
                           { 1,1,1,1,1,1,1 },  // 8
                           { 1,1,1,0,0,1,1 },  // 9
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
                           { 0,0,0,0,0,0,1 },  // NULL
                           };
byte pin = 2; // First pin

void setup() {
  // Sets seven segment pins as OUTPUTs
  for (int i = pin; i < 9; i++) { 
    pinMode(i, OUTPUT);   
  }
  Serial.begin(9600);
}
    
void sevenSegWrite(byte digit) {
  byte outputDigit = 37; // Default NULL
  
  Serial.println(char(digit));
  
  if (digit > 47 && digit < 58) { // Numbers
    outputDigit = digit - '0';
  }
  else if (digit > 64 && digit < 91) { // Capital letter
    outputDigit = digit - 'A' + 10;
  }
  else if (digit > 96 && digit < 123) { // Low letters
    outputDigit = digit - 'a' + 10;
  }
  else if (digit == 32) { // Space
    outputDigit = 36;
  }
  
  for (byte i = 0; i < 7; ++i) {
    digitalWrite(pin + i, sevenSegment[outputDigit][i]);
  }
  delay(500);
}

void loop() {
    if (Serial.available()) {
      sevenSegWrite(Serial.read());
    }
}
