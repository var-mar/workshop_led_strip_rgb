// Define type leds

#define NUM_LEDS   75
#define LED_PIN     7     // pin of Arduino
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB ledsArray[NUM_LEDS];

const int buttonPin = 2;
int buttonState = 0;         // variable for reading the pushbutton status

void setup() { 
  FastLED.addLeds<LED_TYPE, LED_PIN>(ledsArray, NUM_LEDS);
  pinMode(buttonPin, INPUT); 
}

void loop() { 
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);
    
    
    // check if the pushbutton is pressed.
    // if it is, the buttonState is HIGH:
    if (buttonState == HIGH) {
    // turn LED strip red:
      FastLED.showColor(CRGB::Red);
    } 
    else{
      for(int i=0;i<30;i++){
        ledsArray[i] = CRGB::Red;// CRGB(0,0,0);
      }
    
      for(int i=30;i<50;i++){
        ledsArray[i] = CRGB::Green;// CRGB(0,0,0);
      }

      for(int i=50;i<75;i++){
        ledsArray[i] = CRGB::Blue;// CRGB(0,0,0);
      }
    }
    FastLED.show(); 
    delay(30); 
}