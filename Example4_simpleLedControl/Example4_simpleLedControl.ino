
#include "FastLED.h"

// Define type leds

#define NUM_LEDS 	75
#define LED_PIN     7 		// pin of Arduino
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB ledsArray[NUM_LEDS];

int ledIdWhite = 0;

void setup() { 
	FastLED.addLeds<LED_TYPE, LED_PIN,COLOR_ORDER>(ledsArray, NUM_LEDS); 
}

void loop() { 
	
  	// we define all leds black
  	for(int i=0;i<NUM_LEDS;i++){
  		ledsArray[ledIdWhite] = CRGB(0,0,0);//CRGB::Black; 
  	}
  	
  	// we define one white led travelling his position
  	ledIdWhite += 1;
  	
  	ledsArray[ledIdWhite] = CRGB(255,255,255);//CRGB::White; 
  	
  	if(ledIdWhite==NUM_LEDS){
  		ledIdWhite = 0;
  	}
  	
  	// ones we modified the leds array we send to leds stripe
  	FastLED.show(); 
  	
  	delay(30); 
}


        
         
  
  
  
