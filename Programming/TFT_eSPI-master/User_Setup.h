//#define ST7796_DRIVER
#define LOAD_GLCD   // Font 1, the small default font
#define LOAD_FONT2  // Font 2, small
#define LOAD_FONT4  // Font 4, medium
#define LOAD_FONT6  // Font 6, large, digits and a few symbols only
#define LOAD_FONT7  // Font 7, 7-segment style, digits only
#define LOAD_FONT8  // Font 8, very large, digits only
#define LOAD_GFXFF  // Adafruit GFX FreeFonts

#define ILI9488_DRIVER

#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS    5
#define TFT_DC    2
#define TFT_RST  16
#define TFT_BL    4

#define SPI_FREQUENCY       80000000
#define SPI_READ_FREQUENCY  80000000
#define TFT_BACKLIGHT_ON HIGH

//#ifndef ST7796_DRIVER
//#error "User_Setup.h not loaded"
//#endif

#ifndef ILI9488_DRIVER
#error "User_Setup.h not loaded"
#endif