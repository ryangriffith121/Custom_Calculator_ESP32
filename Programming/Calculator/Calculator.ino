#include <TFT_eSPI.h>
TFT_eSPI tft;

void setup() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_RED);
  tft.setTextColor(TFT_WHITE, TFT_RED);
  tft.drawString("Hello", 20, 20, 4);
}

void loop() {}