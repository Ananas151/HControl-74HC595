//Add the library
#include <HControl.h>

/*
 * See documentation at http://www.filipmazurek.pl/projekty/HControl
 * See License information at root directory of this library
 * Author: Filip Mazurek (Ananas151)
 */

/**
 * A simple example showing how to turn pins of 74hc595 HIGH or LOW
 * It's basicly a more complex "blink" example
 *
 * Remember that first pin of 74hc595 is represented here by 0 not 1
 */

/*
 * Letting library know which pins to use...
 * HControl HControl(SRCLK pin, RCLK pin, SER pin, OEPin);
 * OEPin is optional, use it if you want HControl.on(), and HControl.off()
 */
HControl HControl(5,6,4);

int counter = 0;

void setup() 
{
  //----------------------------------
  //Setting different pins on and off
  //----------------------------------
  
  //You can call pins by numbers
  HControl.set(1, HIGH);
  //or lowercase letters
  HControl.set('c', HIGH);

  //0 - a
  //1 - b
  //2 - c ...

  HControl.set(4, HIGH);
  HControl.set(5, HIGH);


  
  
}

void loop() {
  //If you have connected LEDs to each pin of 74hc595 you should see that 
  //every second pin is HIGH and then after a second all pins change their state
  HControl.set(2, HIGH);
  HControl.set(4, HIGH);
  HControl.set(6, HIGH);
  HControl.set(8, HIGH);
  
  HControl.set(1, LOW);
  HControl.set(3, LOW);
  HControl.set(5, LOW);
  HControl.set(7, LOW);
  
  delay(1000); //change
  
  HControl.set(1, HIGH);
  HControl.set(3, HIGH);
  HControl.set(5, HIGH);
  HControl.set(7, HIGH);

  HControl.set(2, LOW);
  HControl.set(4, LOW);
  HControl.set(6, LOW);
  HControl.set(8, LOW);

  delay(1000);
  }