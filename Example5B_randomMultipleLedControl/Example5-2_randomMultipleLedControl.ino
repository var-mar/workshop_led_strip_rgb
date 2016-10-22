#include "FastLED.h"

// Define type leds

#define NUM_LEDS   75
#define LED_PIN     7     // pin of Arduino
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB ledsArray[NUM_LEDS];

void setup() { 
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(ledsArray, NUM_LEDS); 
}

void loop() { 
  
  	CRGB color1 = CRGB(random(255),random(255),random(255));
    // we define all leds black
    for(int i=0;i<30;i++){
      ledsArray[i] = color1;
    }
    
    CRGB color2 = CRGB(random(255),random(255),random(255));
    for(int i=30;i<50;i++){
      ledsArray[i] = color2;
    }

	CRGB color3 = CRGB(random(255),random(255),random(255));
    for(int i=50;i<75;i++){
      ledsArray[i] = color3;
    }
    FastLED.show(); 
    delay(5000); 
}