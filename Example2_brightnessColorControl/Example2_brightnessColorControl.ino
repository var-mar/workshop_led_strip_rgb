#include "FastLED.h"

// Define type leds

#define NUM_LEDS 	75
#define LED_PIN     7 		// pin of Arduino
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB ledsArray[NUM_LEDS];

uint8_t brightness = 0;

void setup() { 
	FastLED.addLeds<LED_TYPE, LED_PIN,COLOR_ORDER>(ledsArray, NUM_LEDS); 
}

void loop() { 
  brightness += 1;
  
  FastLED.showColor(CRGB::White); 
  FastLED.setBrightness(  brightness );

  if(brightness==255){
  	brightness = 0;
  }
  
  delay(100);
}

