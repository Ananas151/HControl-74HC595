#ifndef HControl_H
#define HControl_H
#include <Arduino.h>

/*
 * See documentation at http://www.filipmazurek.pl/projekty/HControl
 * See License information at root directory of this library
 * Author: Filip Mazurek (Ananas151)
 */
 
 /*
 * This library is made for using 74hc595 comfortably
 */

class HControl{
  
  private:
    int latchPin;
	int clockPin;
	int dataPin;
	long data;
	long pipe;
	bool state;
	int pin;
	int OEPin;
	bool temp;
    
  public:
    HControl(int latchPin, int clockPin, int dataPin, int OEPin = -1);
	void write(long data);
	void drywrite(long data);
	void latch();
	void off();
	void on();
	void set(int pin, bool state);
	void dryset(int pin, bool state);
	void toggle(int pin);
	void clear();
	
	int storage();
	
	bool read(int pin);

};
#endif