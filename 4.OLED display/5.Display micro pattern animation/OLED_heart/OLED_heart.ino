/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         OLED_heart
* @author       wusicaijuan
* @version      V1.0
* @date         2019.07.01
* @brief        OLED_heart
* @details
* @par History  
*
*/
#include "Arduino.h"
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#define OLED_RESET 11
Adafruit_SSD1306 display(OLED_RESET);
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH 16

const static unsigned char PROGMEM logo16_glcd_bmp[]=//Miniature icon love after taking the model
{
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00011110, B00111100,
  B00111111, B01111110,
  B00111111, B11111110,
  B00011111, B11111100,
  B00001111, B11111000,
  B00000111, B11110000,
  B00000011, B11100000,
  B00000001, B11000000,
  B00000000, B10000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000 
};

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

/**
* Function       setup
* @author        wusicaijuan
* @date          2019.07.01
* @brief         Initial configuration
* @param[in]     void
* @retval        void
* @par History   no
*/
void setup()
{
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  display.display(); 
  delay(2000);

  display.clearDisplay();
  display.drawBitmap(30, 16,  logo16_glcd_bmp, 16, 16, 1);
  display.display();

  display.invertDisplay(true);
  delay(1000); 
  display.invertDisplay(false);
  delay(1000); 

  testdrawbitmap(logo16_glcd_bmp, LOGO16_GLCD_HEIGHT, LOGO16_GLCD_WIDTH);
   //Display a miniature icon and ‘live’ mobile
}

/**
* Function       loop
* @author        Danny
* @date          2017.07.25
* @brief         main function
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop()      //Initialization has been completed, the main loop has no action
{
        
}

/**
* Function       testdrawbitmap
* @author        Danny
* @date          2017.07.25
* @brief         display heart 
* @param[in]     void
* @retval        void
* @par History   no
*/
void testdrawbitmap(const uint8_t *bitmap, uint8_t w, uint8_t h) 
{
  uint8_t icons[NUMFLAKES][3];
  srandom(666);     // whatever seed
 
  // initialize
  for (uint8_t f=0; f< NUMFLAKES; f++)
  {
    icons[f][XPOS] = random() % display.width();
    icons[f][YPOS] = 0;
    icons[f][DELTAY] = random() % 5 + 1;
    
    Serial.print("x: ");
    Serial.print(icons[f][XPOS], DEC);
    Serial.print(" y: ");
    Serial.print(icons[f][YPOS], DEC);
    Serial.print(" dy: ");
    Serial.println(icons[f][DELTAY], DEC);
  }

  while (1)
  {
    // draw each icon
    for (uint8_t f=0; f< NUMFLAKES; f++) 
    {
      display.drawBitmap(icons[f][XPOS], icons[f][YPOS], logo16_glcd_bmp, w, h, WHITE);
    }
    display.display();
    delay(200);
    
    // then erase it + move it
    for (uint8_t f=0; f< NUMFLAKES; f++)
    {
      display.drawBitmap(icons[f][XPOS], icons[f][YPOS],  logo16_glcd_bmp, w, h, BLACK);
      // move it
      icons[f][YPOS] += icons[f][DELTAY];
      // if its gone, reinit
      if (icons[f][YPOS] > display.height())
      {
  icons[f][XPOS] = random() % display.width();
  icons[f][YPOS] = 0;
  icons[f][DELTAY] = random() % 5 + 1;
      }
    }
   }
}


