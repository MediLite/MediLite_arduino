#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

//Serial Number of the device to be broadcast
#define SERIALNO         6782563

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second
int colorIter = 0; 
// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 9;    // the number of the pushbutton pin

// Variables will change:
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  Serial.begin(9600);
  Serial.println(SERIALNO);
  pinMode(buttonPin, INPUT);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  // put your main code here, to run repeatedly:
    // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
          iterateColor();
      }
    }
  }

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
  Serial.println(SERIALNO);
}

//This shows the color of the LED 
void iterateColor(){
  Serial.println(SERIALNO);
  //Reset the iteration if reachng the end
  if(colorIter >=5) {colorIter = 0;}
  
  //White = Black for Card compatibility
  if(colorIter = 0){
    for(int i=0;i<NUMPIXELS;i++){
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(255,255,255)); // Moderately bright green color.
    }
   }
   //Red
  if(colorIter = 1){
    for(int i=0;i<NUMPIXELS;i++){
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(255,0,0)); // Moderately bright green color.
    }
   }
   //Yellow
  if(colorIter = 2){
    for(int i=0;i<NUMPIXELS;i++){
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(255,255,0)); // Moderately bright green color.
    }
   }
   //Green
   if(colorIter = 3){
    for(int i=0;i<NUMPIXELS;i++){
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(0,255,0)); // Moderately bright green color.
    }
   }
   //Blue (treated or not in need of treatment)
  if(colorIter = 4){
    for(int i=0;i<NUMPIXELS;i++){
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(0,0,255)); // Moderately bright green color.
    }
   }
   
   pixels.show(); // This sends the updated pixel color to the hardware.
   colorIter++;
   delay(delayval); // Delay for a period of time (in milliseconds).
  
}
