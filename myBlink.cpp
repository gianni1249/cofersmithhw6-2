/** Simple On-board LED flashing program - written by Derek Molloy
*    simple OOP  struture for the Exploring BeagleBone book
*
    This program uses all four LEDS and can be executed in three ways:
*         makeLEDs on
*         makeLEDs off
*         makeLEDs flash  (flash at time delay intervals)
*         makeLEDs status (get the trigger status)
*
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and 
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2014
* ISBN 9781118935125. Please see the file README.md in the repository root 
* directory for copyright and GNU GPLv3 license information.            */


#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "derek_LED.h"
using namespace std;

int main(int argc, char* argv[]){
   if(argc>4){
        cout << "Usage is makeLEDs <command>" << endl;
        cout << "   command is one of: on, off, flash, blink or status" << endl;
        cout << " e.g. makeLEDs flash" << endl;
   }
   cout << "Starting the makeLEDs program" << endl;
   string cmd(argv[1]);
   int count=stoi(argv[3]);
   int led=stoi(argv[2]);
   LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };
   
      if(cmd=="on")leds[led].turnOn();
      else if(cmd=="off")leds[led].turnOff();
      else if(cmd=="flash")leds[led].flash("100"); //default is "50"
      else if(cmd=="status")leds[led].outputState();
      else if(cmd=="blink")leds[led].blink(count);
      else{ cout << "Invalid command!" << endl; }
  
   cout << "Finished the makeLEDs program" << endl;
   return 0;
}
