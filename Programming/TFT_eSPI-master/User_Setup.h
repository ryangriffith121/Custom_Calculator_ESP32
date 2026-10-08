#define ST7796_DRIVER

#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS    5
#define TFT_DC    2
#define TFT_RST  16
#define TFT_BL    4

#define SPI_FREQUENCY 10000000
#define TFT_BACKLIGHT_ON HIGH

#ifndef ST7796_DRIVER
#error "User_Setup.h not loaded"
#endif