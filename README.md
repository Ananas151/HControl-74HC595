# HControl for 74HC595
HControl allows for convenient control over 74HC595 (shift register). Allows you to make basic operations with the 74HC595. The library supports daisychaining multiple 74HC595.
## Basic way to connect 74HC595 
First lets connect VCC and GND:
 - Pin 16 (VCC) and pin 10 (SRCLR) to 5V
 - Pin 8 (GND) and pin 13 (OE) to GND 

The three communication pins:
 - Pin 11 (SRCLK) of the shift register to pin 6 on the Arduino
 - Pin 12 (RCLK) of the shift register to pin 5 on the Arduino
 - Pin 14 (SER) of the shift register to pin 4 on the Arduino  
 
Ofcourse you can connect anything you want to output pins, but first time I recomend to try it with LEDs to see how it works. Remember to connect LEDs through atleast 220Ω resistors.

Connections should look like on the picture below.
![74hc595-pinout](https://user-images.githubusercontent.com/67464321/178084054-9737d190-4795-4c69-9c45-b3040b1ab97b.JPG)
## Daisychaining multiple 74HC595
There is no limit to the number of connected 74HC595s in series. You can connect a whole bunch. The connection is basicly the same as for one IC. Every next 74HC595 you have to connect pin 14 (SER) to pin 9 (Q<sub>H</sub>') of the previous 74HC595.

For two ICs it should look something like on the picture below.
![74hc595-pinout-daisy](https://user-images.githubusercontent.com/67464321/178084356-1af22328-1ba0-45a4-a7e0-fdc088d07d44.JPG)
There are really no changes in code needed for multiple 74HC595s. Pins of the next 74HC595 add to the previous so i.e. for the second 74HC595 the pins will start from 8, 9, 10, 11, 12, ... 
## Functions
### HControl HControl(int latchPin, int clockPin, int dataPin, int OEPin)
You have to add this to code, to let the library know which pins you are using for 74HC595. OEPin is optional, leave it out if you dont use it.
### set(int pin, bool state)
Sets pin to a desired state (HIGH or LOW)
### toggle(int pin)
Toggles pin state (changes HIGH to LOW or LOW to HIGH)
### clear()
Sets all pins to LOW
### storage()
States of all pins is represented by a binary number (here called pipe), where every 1 means that the pin's state is HIGH. Storage() returns that number. For example if pin 1, 4 and 7 are on then the storage() will return 01001001.
### write(long data)
Sets pipe to the desired value
### read(int pin)
Returns state of a specific pin.
### drywrite(long data)
Sets pipe to the desired value, without latching it into the shift register
### dryset(int pin, bool state)
Sets pin to a desired state (HIGH or LOW), without latching it into the shift register
### latch()
Latches/enters the states into the shift register if they weren't already
### off()
Disables all pins, requires using OE pin.
### on()
Enables all pins, requires using OE pin.

For more details go to my website http://www.filipmazurek.pl/projekty/HControl



