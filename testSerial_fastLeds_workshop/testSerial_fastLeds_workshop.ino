#include <FastLED.h>

#define NUM_LEDS 75
#define NUM_CHANNELS 3
#define BUFFER_SIZE NUM_LEDS*NUM_CHANNELS

#define LED_PIN     7  //Pin13
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB ledsBuffer[NUM_LEDS];
unsigned char pixelBuffer[BUFFER_SIZE];

void setup() {
  
  delay(3000); // power-up safety delay
  Serial.begin(115200);

  
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(ledsBuffer, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(64); //Brightness
  memset(ledsBuffer, 200, NUM_LEDS*NUM_CHANNELS);
  FastLED.show();
  Serial.write(1);
}

void loop() {
  
  if(Serial.available()){
    if(Serial.readBytes(pixelBuffer, BUFFER_SIZE)){
      //This second copy is necessary to pass buffer (unsigned char) to tipo CRGB (uint8_t)
      memcpy ( ledsBuffer, pixelBuffer, NUM_LEDS*NUM_CHANNELS);
      FastLED.show();
      Serial.write(1);
      }
  }
}



