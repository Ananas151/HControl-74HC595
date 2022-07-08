#include "HControl.h"
/*
 * See documentation at http://www.filipmazurek.pl/projekty/HControl
 * See License information at root directory of this library
 * Author: Filip Mazurek (Ananas151)
 */
 
 /*
 * This library is made for using 74hc595 comfortably
 */
 
//add a 74hc595
HControl::HControl(int latchPin, int clockPin, int dataPin, int OEPin = -1) {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(OEPin, OUTPUT);
  
  this->latchPin = latchPin;
  this->clockPin = clockPin;
  this->dataPin = dataPin; 
  this->pin = pin; 
  this->state = state;
  this->pipe = pipe;
  this->OEPin = OEPin;
  this->temp = temp;
  pipe = 0b0000000000000000000000000;

}

//set pin state HIGH or LOW
void HControl::set(int pin, bool state) {
	
	
	if(pin < 97){
		bitWrite(pipe, pin, state);

	}
	else{
		
		bitWrite(pipe, pin - 97, state);
	}
	
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, MSBFIRST, pipe);
    digitalWrite(latchPin, HIGH);

	
	
}

//set pin state HIGH or LOW without latching it
void HControl::dryset(int pin, bool state) {
	if(pin < 97){
		bitWrite(pipe, pin, state);

	}
	else{
		
		bitWrite(pipe, pin - 97, state);
	}
}

//set pins states by entering a binary number representing pins desired states
void HControl::write(long data) {
	pipe = data;
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, MSBFIRST, pipe);
    digitalWrite(latchPin, HIGH);
}

//set pins state without latching it
void HControl::drywrite(long data) {
	pipe = data;
}

//read current state of a pin
bool HControl::read(int pin) {
	return bitRead(pipe, pin);
}

//change pin's state
void HControl::toggle(int pin) {
	
	if(pin < 97){
		temp = bitRead(pipe, pin);
		bitWrite(pipe, pin, !temp);
	}
	else{
		temp = bitRead(pipe, pin - 97);
		bitWrite(pipe, pin - 97, !temp);
	}
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, MSBFIRST, pipe);
    digitalWrite(latchPin, HIGH);
	
}

//latch data
void HControl::latch(){
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, MSBFIRST, pipe);
    digitalWrite(latchPin, HIGH);
}
//returns binary number representing states of pins
int HControl::storage() {
	return pipe;
}

//turn all pins LOW temporarily, without clearing their states
void HControl::off() {
	digitalWrite(OEPin, HIGH);
}

//turning all pins to their states
void HControl::on() {
	digitalWrite(OEPin, LOW);
}

//making all pins LOW
void HControl::clear() {
	pipe = 0b000000000000000000000000000000;
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, LSBFIRST, pipe);
    digitalWrite(latchPin, HIGH);
	
}  