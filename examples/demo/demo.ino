//Add the library
#include <HControl.h>

/*
 * See documentation at http://www.filipmazurek.pl/projekty/HControl
 * See License information at root directory of this library
 * Author: Filip Mazurek (Ananas151)
 */

/**
 * A demo making different patterns with LEDs connected to 74hc595
 */

/*
 * Letting library know which pins to use...
 * HControl HControl(SRCLK pin, RCLK pin, SER pin, OEPin);
 */
HControl HControl(5, 6, 4);

void setup()
{
}

void loop() {
  //walking point
  for(int i = 0; i < 4; i++){
    for(int i = 0; i < 8; i++){
      HControl.set(i, HIGH);
      HControl.set(i - 1, LOW);
      delay(80);
    }
    HControl.set(7, LOW);
  }
  //loading bar
  for(int k = 8; k >= 0; k--){
    for(int i = 0; i <= k; i++){
      HControl.set(i, HIGH);
      HControl.set(i - 1, LOW);
      delay(100);
    }
  }
  //inverse loading bar
  for(int k = 0; k < 8; k++){
    for(int i = 8; i >= k; i--){
      HControl.set(i, HIGH);
      HControl.set(i + 1, LOW);
      delay(100);
    }
  }
}