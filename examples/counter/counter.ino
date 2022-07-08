//Add the library
#include <HControl.h>

/*
 * See documentation at http://www.filipmazurek.pl/projekty/HControl
 * See License information at root directory of this library
 * Author: Filip Mazurek (Ananas151)
 */

/**
 * A simple example of a binary counter
 * The program counts from 0 to 255 and shows it on 74hc595
 *
 * Feel free trying to make a bigger counter with daisychained 74hc595s
 */

/*
 * Letting library know which pins to use...
 * HControl HControl(SRCLK pin, RCLK pin, SER pin, OEPin);
 * OEPin is optional, use it if you want HControl.on(), and HControl.off()
 */
HControl HControl(5, 6, 4);

void setup()
{
	//nothings needed here
}

void loop() {
	//increase i < 256 if you're using more 74hc595s
  for(int i = 0; i < 256; i++){
	//States of pins in this library are represented by binary number
	//HControl.write(int) changes that number to the desired value 
    HControl.write(i);
    delay(1000);
  }
}