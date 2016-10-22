#include "FastLED.h"

// Define type leds

#define NUM_LEDS 	75
#define LED_PIN     7 		// pin of Arduino
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB ledsArray[NUM_LEDS];

uint8_t brightness = 0;
int sensorPin = 0;
int val;

void setup() { 
	FastLED.addLeds<LED_TYPE, LED_PIN,COLOR_ORDER>(ledsArray, NUM_LEDS); 
	pinMode(sensorPin, OUTPUT);
	Serial.begin(9600);
}

void loop() { 
  
  val = analogRead(sensorPin);
  val = map(val, 0, 1023,0,255); 
  Serial.println(val);
  
  FastLED.showColor(CRGB::White); 
  FastLED.setBrightness( val );
  
  delay(100);
}

