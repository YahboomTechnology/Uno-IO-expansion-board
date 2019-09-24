/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         OLED_drawcircle
* @author       wusicaijuan
* @version      V1.0
* @date         2019.07.01
* @brief        OLED_drawcircle
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

#define LOGO16_GLCD_HEIGHT 32
#define LOGO16_GLCD_WIDTH 128

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
* @par History   NO
*/
void setup()
{
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  display.display(); 
  delay(2000);
  display.clearDisplay();
  
  testdrawcircle();
  delay(2000);
  display.clearDisplay();

  testfillrect();
  delay(2000);
  display.clearDisplay();

  testdrawtriangle();
  delay(2000);
  display.clearDisplay();

  testfilltriangle();
  delay(2000);
  display.clearDisplay();

  testdrawroundrect();
  delay(2000);
  display.clearDisplay();

  testfillroundrect();
  delay(2000);
  display.clearDisplay();

  testdrawrect();
  delay(2000);
  display.clearDisplay();
}

/**
* Function       loop
* @author        Danny
* @date          2017.07.25
* @brief         Main 
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop()      //Initialization has been completed, the main loop has no action
{
        
}

void testdrawcircle(void) 
{
  for (int16_t i=0; i<display.height(); i+=2) 
  {
    display.drawCircle(display.width()/2, display.height()/2, i, WHITE);
    display.display();
  }
}

void testfillrect(void)
{
  uint8_t color = 1;
  for (int16_t i=0; i<display.height()/2; i+=3) 
  {
    // alternate colors
    display.fillRect(i, i, display.width()-i*2, display.height()-i*2, color%2);
    display.display();
    color++;
  }
}

void testdrawtriangle(void) 
{
  for (int16_t i=0; i<min(display.width(),display.height())/2; i+=5) 
  {
    display.drawTriangle(display.width()/2, display.height()/2-i,
                     display.width()/2-i, display.height()/2+i,
                     display.width()/2+i, display.height()/2+i, WHITE);
    display.display();
  }
}

void testfilltriangle(void)
{
  uint8_t color = WHITE;
  for (int16_t i=min(display.width(),display.height())/2; i>0; i-=5)
  {
    display.fillTriangle(display.width()/2, display.height()/2-i,
                     display.width()/2-i, display.height()/2+i,
                     display.width()/2+i, display.height()/2+i, WHITE);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    display.display();
  }
}

void testdrawroundrect(void) 
{
  for (int16_t i=0; i<display.height()/2-2; i+=2)
  {
    display.drawRoundRect(i, i, display.width()-2*i, display.height()-2*i, display.height()/4, WHITE);
    display.display();
  }
}

void testfillroundrect(void) 
{
  uint8_t color = WHITE;
  for (int16_t i=0; i<display.height()/2-2; i+=2) 
  {
    display.fillRoundRect(i, i, display.width()-2*i, display.height()-2*i, display.height()/4, color);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    display.display();
  }
}
   
void testdrawrect(void) 
{
  for (int16_t i=0; i<display.height()/2; i+=2)
  {
    display.drawRect(i, i, display.width()-2*i, display.height()-2*i, WHITE);
    display.display();
  }
}



