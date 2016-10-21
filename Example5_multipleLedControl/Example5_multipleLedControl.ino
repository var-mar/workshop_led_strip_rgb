// Define type leds

#define NUM_LEDS   75
#define LED_PIN     7     // pin of Arduino
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB ledsArray[NUM_LEDS];

void setup() { 
  FastLED.addLeds<LED_TYPE, LED_PIN>(ledsArray, NUM_LEDS); 
}

void loop() { 
  
    // we define all leds black
    for(int i=0;i<30;i++){
      ledsArray[i] = CRGB::Red;// CRGB(0,0,0);
    }
    
    for(int i=30;i<50;i++){
      ledsArray[i] = CRGB::Green;// CRGB(0,0,0);
    }

    for(int i=50;i<75;i++){
      ledsArray[i] = CRGB::Blue;// CRGB(0,0,0);
    }
    FastLED.show(); 
    delay(30); 
}