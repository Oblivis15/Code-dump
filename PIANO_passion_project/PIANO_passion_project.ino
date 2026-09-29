#include <Keypad.h>

const byte ROWS = 8; 
const byte COLS = 6; 

// 8x6 Matrix mapped with unique single char keys
char keyMap[ROWS][COLS] = {
  // Columns: A0,   A1,   A2,   A3,   A4,   A5
  /* D2 */  {' ',  '2',  '1',  '7',  ' ',  'c'}, 
  /* D3 */  {' ',  ' ',  'b',  ' ',  'g',  'l'}, 
  /* D4 */  {' ',  ' ',  'a',  '6',  ' ',  ' '}, 
  /* D5 */  {' ',  ' ',  ' ',  ' ',  'f',  'k'}, 
  /* D6 */  {'4',  ' ',  '9',  '5',  'e',  'j'}, 
  /* D7 */  {' ',  ' ',  ' ',  ' ',  ' ',  ' '}, 
  /* D8 */  {'3',  ' ',  '8',  'h',  'd',  'i'}, 
  /* D9 */  {' ',  ' ',  ' ',  ' ',  ' ',  ' '}
};

byte rowPins[ROWS] = {2, 3, 4, 5, 6, 7, 8, 9}; 
byte colPins[COLS] = {A0, A1, A2, A3, A4, A5}; 

Keypad customPiano = Keypad(makeKeymap(keyMap), rowPins, colPins, ROWS, COLS);

const int BUZZER_PIN = 11; // Signal pin out to Piezo / Speaker

int getTone(char keyID) {
  switch (keyID) {
    // Octave 3 (Lowest Keys: Left side of keyboard)
    case '1': return 131;  // C3 (First C)
    case '2': return 147;  // D3
    case '3': return 165;  // E3
    case '4': return 175;  // F3

    // Octave 4 (Mid-Low Keys)
    case '5': return 262;  // C4 (Middle C)
    case '6': return 294;  // D4
    case '7': return 330;  // E4
    case '8': return 349;  // F4
    case '9': return 392;  // G4
    case 'a': return 440;  // A4
    case 'b': return 494;  // B4

    // Octave 5 (Mid-High Keys)
    case 'c': return 523;  // C5
    case 'd': return 587;  // D5
    case 'e': return 659;  // E5
    case 'f': return 698;  // F5
    case 'g': return 784;  // G5
    case 'h': return 880;  // A5

    // Octave 6 (Highest Keys: Right side of keyboard)
    case 'i': return 698;  // F5
    case 'j': return 784;  // G5
    case 'k': return 880;  // A5
    case 'l': return 988;  // B5
    default:  return 0;
  }
}

unsigned long lastKeyPress = 0;
const int DEBOUNCE_DELAY = 100; // Ignores duplicate contact bounces within 100ms

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("=== BIGFUN BF-430A1 CUSTOM PIANO READY ===");
}

void loop() {
  char key = customPiano.getKey();

  if (key != NO_KEY && (millis() - lastKeyPress > DEBOUNCE_DELAY)) {
    lastKeyPress = millis();
    int frequency = getTone(key);

    if (frequency > 0) {
      Serial.print("Pressed Key Char [");
      Serial.print(key);
      Serial.print("] -> Playing Frequency: ");
      Serial.print(frequency);
      Serial.println(" Hz");
      
      tone(BUZZER_PIN, frequency, 160); // Play note for 160ms
    }
  }
}