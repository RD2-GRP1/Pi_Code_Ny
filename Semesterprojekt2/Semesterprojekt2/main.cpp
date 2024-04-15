#include <iostream>
#include "wiringPi.h"


int main()
{
    int red = 2;
    wiringPiSetupGpio();
    if(wiringPiSetup() == -1){exit;}
    pinMode(red, OUTPUT);
    int i = 0;
    while(i < 10){
        digitalWrite(red, HIGH);
        delay(500);
        digitalWrite(red, LOW);
        delay(500);
        ++i;
    }


    return 0;
}
