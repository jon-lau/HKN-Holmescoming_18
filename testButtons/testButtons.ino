#include <FastLED.h>
#define LED_PIN 7
#define RED1    2
#define GREEN1   0
#define YELLOW1 1
#define RED2   3
#define GREEN2   5
#define YELLOW2 4
#define NUM_LEDS    60

#define BLUE 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define WHITE 4
CRGB leds[NUM_LEDS];
int GameOver = 1;
int One_Score = 0;
int Two_Score = 0;
int B_Ready = 0;
int R_Ready = 0;
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    Serial.begin(9600);
}
void loop() {
  //  wait to start the game
  if (GameOver) {
    //reset score
    One_Score = 0;
    Two_Score = 0;
    B_Ready = 0;
    R_Ready = 0;


    //turn off lights
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB:: Black;

    }
    FastLED.show();


    //wait for players to ready up
    while (1) {
      //        Serial.println(digitalRead(3));


      if (B_Ready && R_Ready) {
        GameOver = 0;
        break;
      }

      //red team is ready
      if (digitalRead(RED1) == LOW) {

        for (int i = 0; i < NUM_LEDS - 1; i += 2) {
          leds[i] = CRGB:: Blue;
          FastLED.show();
          delay(50);
        }
        R_Ready = 1;
      }
      //blue team is ready
      if (digitalRead(RED2) == LOW) {

        for (int i = 1; i < NUM_LEDS - 1; i += 2) {
          leds[i] = CRGB:: White;
          FastLED.show();
          delay(50);
        }
        B_Ready = 1;
      }
    }

  }



  //have leds cycle randomly
  int randvalue = random(5, 40);

  for (int j = 0; j < randvalue; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(random8(), 255, 255);
    }
    FastLED.show();
    delay(200);
  }

  //pick random color to show (numbers 0 - 4
  int color = random(0, 3);

  switch (color) {
    //if red
    case 0:
      for (int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB:: Red;
      break;
    //if green
    case 1:
      for (int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB:: Green;
      break;
    //if yellow
    case 2:
      for (int i = 0; i < NUM_LEDS; i++) leds[i] = CHSV(21, 255, 255);
      break;
  }

  FastLED.show();
  while (1) {
    if (color == 0) {
      if (digitalRead(RED1) == LOW) {
        One_Score++;
        for (int i = 0; i < NUM_LEDS - 1; i++) {
          leds[i] = CRGB:: Blue;
        }
        FastLED.show();
        delay(100);
        break;
      }
      else if (digitalRead(RED2) == LOW) {
        for (int i = 0; i < NUM_LEDS - 1; i++) {
          leds[i] = CRGB:: White;
        }
        FastLED.show();
        delay(100);
        Two_Score++;
        break;
      }
    }
    else if (color == 1) {
      if (digitalRead(GREEN1) == LOW) {
        One_Score++;
        for (int i = 0; i < NUM_LEDS - 1; i++) {
          leds[i] = CRGB:: Blue;
        }
        FastLED.show();
        delay(100);
        break;
      }
      else if (digitalRead(GREEN2) == LOW) {
        Two_Score++;
        for (int i = 0; i < NUM_LEDS - 1; i++) {
          leds[i] = CRGB:: White;
        }
        FastLED.show();
        delay(100);
        break;
      }
    }
    else if (color == 2) {
      if (digitalRead(YELLOW1) == LOW) {
        One_Score++;
        for (int i = 0; i < NUM_LEDS - 1; i++) {
          leds[i] = CRGB:: Blue;
        }
        FastLED.show();
        delay(100);
        break;
      }
      else if (digitalRead(YELLOW2) == LOW) {
        Two_Score++;
        for (int i = 0; i < NUM_LEDS - 1; i++) {
          leds[i] = CRGB:: White;
        }
        FastLED.show();
        delay(100);
        break;
      }
    }


  }
  delay(1000);

  if (One_Score > 2 || Two_Score > 2) GameOver = 1;

}
