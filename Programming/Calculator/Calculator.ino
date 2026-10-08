#include <TFT_eSPI.h>
TFT_eSPI tft;

const uint8_t ROW_PINS[] = {13, 14, 25, 26};
const uint8_t COL_PINS[] = {27, 32, 33, 21, 22};

constexpr uint8_t NUM_ROWS = sizeof(ROW_PINS);
constexpr uint8_t NUM_COLS = sizeof(COL_PINS);

bool state[NUM_ROWS][NUM_COLS];
unsigned long lastChange[NUM_ROWS][NUM_COLS];


void setup() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_RED);
  tft.setTextColor(TFT_WHITE, TFT_RED);
  tft.drawString("Hello", 20, 20, 4);
  Serial.begin(115200);
  for (uint8_t c = 0; c < NUM_COLS; c++) pinMode(COL_PINS[c], INPUT_PULLUP);
  for (uint8_t r = 0; r < NUM_ROWS; r++) pinMode(ROW_PINS[r], INPUT);
  Serial.println("Key tester ready");
}

void loop() {
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
      }
    }
    pinMode(ROW_PINS[r], INPUT);
  }
}
