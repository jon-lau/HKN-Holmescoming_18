#include <FastLED.h>
#define LED_PIN     7
#define BUTTON1A    4
#define BUTTON1B    4
#define NUM_LEDS    60

#define BLUE 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define WHITE 4
CRGB leds[NUM_LEDS];
int GameOver = 1;
int B_Score = 0;
int R_Score = 0;
int B_Ready = 0;
int R_Ready = 0;
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}
void loop() {
  //  wait to start the game

  if (GameOver) {
    //reset score
    int B_Score = 0;
    int R_Score = 0;
    int B_Ready = 0;
    int R_Ready = 0;


    //turn off lights
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB:: Black;

    }
    FastLED.show();


    //wait for players to ready up
    while (1) {
      if (B_Ready && R_Ready){
        GameOver = 0;
        break;
      }

      //red team is ready
      if (digitalRead(BUTTON1A) == LOW && !R_Ready) {

        for (int i = 0; i < NUM_LEDS-1; i+=2) {
          leds[i] = CRGB:: Red;
          FastLED.show();
          delay(100);
        }
        R_Ready = 1;
      }
      //blue team is ready
      if (digitalRead(5) == LOW && !R_Ready) {

        for (int i = 1; i < NUM_LEDS-1; i+=2) {
          leds[i] = CRGB:: Blue;
          FastLED.show();
          delay(100);
        }
        B_Ready = 1;
      }
    }

  }



  //have leds cycle randomly
  int randvalue = random(5, 20);

  for (int j = 0; j < randvalue; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(random8(), 255, 255);
    }
    FastLED.show();
    delay(200);
  }

  //pick random color to show (numbers 0 - 4
  int color = random(0, 5);

  switch (color) {
    //if blue
    case 0:
      for (int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB:: Blue;
      break;
    //if red
    case 1:
      for (int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB:: Red;

      break;
    //if green
    case 2:
      for (int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB:: Green;
      break;
    //if yellow
    case 3:
      for (int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB:: Yellow;
      break;
    //if yellow
    case 4:
      for (int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB:: White;
      break;
  }

  FastLED.show();
  while (1) {
    if (digitalRead(BUTTON1A) == LOW) {
      B_Score++;
      break;
    }
  }
  delay(1000);

  if (B_Score > 2) GameOver = 1;

}
