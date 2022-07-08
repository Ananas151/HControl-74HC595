//Add the library
#include <HControl.h>

/*
 * See documentation at http://www.filipmazurek.pl/projekty/HControl
 * See License information at root directory of this library
 * Author: Filip Mazurek (Ananas151)
 */

/**
 * A simple example of using the OEPin
 */

/*
 * Letting library know which pins to use...
 * HControl HControl(SRCLK pin, RCLK pin, SER pin, OEPin);
 * In this example OEPin is used
 */
HControl HControl(5, 6, 4, 7);

void setup()
{
	//We set some pins HIGH
	HControl.set(0, HIGH);
	HControl.set(1, HIGH);
	HControl.set(3, HIGH);
	HControl.set(4, HIGH);
	HControl.set(6, HIGH);
	HControl.set(7, HIGH);
}

void loop() {
	HControl.off(); //disables all pins
	delay(1000);
	HControl.on();	//does the oposite of off()
	delay(1000);	
}