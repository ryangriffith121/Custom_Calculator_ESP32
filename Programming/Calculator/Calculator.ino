#include <TFT_eSPI.h>
#include <math.h>   
TFT_eSPI tft;

const uint8_t ROW_PINS[] = {26, 25, 33, 32, 21};
const uint8_t COL_PINS[] = {13, 22, 14, 27};

constexpr uint8_t NUM_ROWS = sizeof(ROW_PINS);
constexpr uint8_t NUM_COLS = sizeof(COL_PINS);

bool state[NUM_ROWS][NUM_COLS];
unsigned long lastChange[NUM_ROWS][NUM_COLS];


void setup() {
 tft.init();
 tft.setRotation(3);  

 Serial.begin(115200);
 for (uint8_t c = 0; c < NUM_COLS; c++) pinMode(COL_PINS[c], INPUT_PULLUP);
 for (uint8_t r = 0; r < NUM_ROWS; r++) pinMode(ROW_PINS[r], INPUT);
 Serial.println("Key tester ready");
}

void loop() {
 tft.startWrite();
 //tft.fillScreen(TFT_BLACK);
 tft.setTextColor(TFT_WHITE, TFT_BLUE);
 tft.drawString("Hello World", 20, 20, 4);

 tft.fillRect(10, 60, 100, 40, TFT_BLUE);           // x, y, width, height
 tft.drawRoundRect(130, 60, 100, 40, 8, TFT_GREEN); // outline, corner radius 8
 tft.fillCircle(300 + sin(millis()/2000)*100, 80, 20, TFT_RED);              // center x, y, radius
 tft.drawLine(0, 120, 479, 120, TFT_YELLOW); 
 tft.endWrite();
 for (uint8_t r = 0; r < NUM_ROWS; r++) {
   pinMode(ROW_PINS[r], OUTPUT);
   digitalWrite(ROW_PINS[r], LOW);
   delayMicroseconds(50);
   for (uint8_t c = 0; c < NUM_COLS; c++) {
     bool pressed = (digitalRead(COL_PINS[c]) == LOW);
     if (pressed != state[r][c] && millis() - lastChange[r][c] > 10) {
       state[r][c] = pressed;
       lastChange[r][c] = millis();
       Serial.printf("Row %u, Col %u %s\n", r, c, pressed ? "pressed" : "released");
       tft.setTextColor(TFT_GREEN, TFT_PURPLE);
       tft.fillScreen(TFT_BLACK);
       tft.drawString("Button Pressed", 200, 20, 4);
     }
   }
   pinMode(ROW_PINS[r], INPUT);
 }
}

// Drives every display pin HIGH so you can check each pad with a multimeter.
// const struct { uint8_t pin; const char* name; } PINS[] = {
  // {23, "MOSI (SDI)"},
  // {19, "MISO (SDO)"},
  // {18, "SCK"},
  // {5,  "CS"},
  // {2,  "DC/RS"},
  // {16, "RESET"},
  // {4,  "LED (backlight)"},
// };
// 
// void setup() {
  // Serial.begin(115200);
  // for (auto &p : PINS) {
    // pinMode(p.pin, OUTPUT);
    // digitalWrite(p.pin, HIGH);
    // Serial.printf("GPIO%u -> %s: HIGH\n", p.pin, p.name);
  // }
  // Serial.println("All pins held HIGH. Measure each pad against GND (expect ~3.3V).");
// }
// 
// void loop() {}
