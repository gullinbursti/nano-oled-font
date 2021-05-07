
#include <Adafruit_SSD1306.h>

#include "FiraCode-Bold8pt7b.h"
#include "ProggySquare8pt7b.h"

//#define SCREEN_64_H 1


#define SCREEN_WIDTH 128
#if defined(SCREEN_64_H)
  #define SCREEN_HEIGHT 64
#else
  #define SCREEN_HEIGHT 32
#endif

#define OLED_RESET     4
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



void setup() {
  Serial.begin(115200);
  Serial.println(F("-:- SOF setup() -:-"));  

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
  
  } else {
    display.clearDisplay();
    display.display();

#   if defined(SCREEN_64_H)
      display.drawLine(0, 16,  display.width() - 1, 16, SSD1306_WHITE);
      display.drawLine(4, 17,  display.width() - 8, 17, SSD1306_WHITE);
#   else
      display.drawLine(0, 13,  display.width() - 1, 13, SSD1306_WHITE);
      display.drawLine(4, 14,  display.width() - 8, 14, SSD1306_WHITE);
#   endif
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
  
    display.setFont(&FiraCode_Bold8pt7b);
#   if defined(SCREEN_64_H)
      display.setCursor(10, 15);
#   else
      display.setCursor(10, 10);
#   endif
    display.println(F("LAN Devices"));
  
    display.setFont(&ProggySquare8pt7b);
#   if defined(SCREEN_64_H)
      display.setCursor(42, 40);
#   else
      display.setCursor(42, 28);
#   endif
    display.println(F("3 Total"));
    
    display.display();
  }

  Serial.println("\\\\=- EOF setup() -=//");
}

void loop() {
  while (true) { }
}
