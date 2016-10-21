#include "FastLED.h"

// Define type leds

#define NUM_LEDS 	75
#define LED_PIN     7 		// pin of Arduino
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB ledsArray[NUM_LEDS];

uint8_t hue = 0;

void setup() { 
	FastLED.addLeds<LED_TYPE, LED_PIN,COLOR_ORDER>(ledsArray, NUM_LEDS); 
}

void loop() { 
  hue += 1;
  
  FastLED.showColor(CHSV(hue, 255, 255)); 
  
  if(hue==255){
  	hue = 0;
  }
  
  delay(100);
}