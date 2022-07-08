//Add the library
#include <HControl.h>

/*
 * See documentation at http://www.filipmazurek.pl/projekty/HControl
 * See License information at root directory of this library
 * Author: Filip Mazurek (Ananas151)
 */

/**
 * A simple example of toggling pins HIGH or LOW on 74hc595 via serial
 *
 * Write number from 0 to 7 (if using one 74hc595) in Serial Monitor to change state of desired pin
 * Feel free trying to use more than one 74hc595
 */
 
 
/*
 * Letting library know which pins to use...
 * HControl HControl(SRCLK pin, RCLK pin, SER pin, OEPin);
 * OEPin is optional, use it if you want HControl.on(), and HControl.off()
 */
HControl HControl(5, 6, 4);

int pin;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    pin = Serial.parseInt();
    
    //HControl.toggle(int) toggles current state of a pin
    //i.e. if the pin c is HIGH and you use HControl.toggle(c), then pin c will be set LOW
    HControl.toggle(pin);

    //Visual representation in Serial Monitor:
    Serial.println("Pins, and their states:");
	// change i < 8 to more, if you are using daisychained 74hc595
    for (int i = 0; i < 8; i++) {
      Serial.print("|");
      Serial.print(HControl.read(i));
      //HControl.read(int) reads state of a particular pin
    }
    Serial.println("|");
    
    Serial.print("Binary representation: ");
    Serial.println(HControl.storage(), BIN);
	
	/*
     *HControl.storage() is simialar to HControl.read(int), but instead of checking
     *just one pin, it returns binary number telling what pins are on
     *i.e. if pins a, b and d are HIGH, then HControl.storage() will return 00001011
     ***Use "BIN" in Serial.println() to print it as binary number**
	 */
  }
}