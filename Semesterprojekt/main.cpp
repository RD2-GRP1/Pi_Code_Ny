#include <iostream>
#include <wiringPi.h>

#define red 7
int main(void)
{
    // Red LED: Physical pin 18, BCM GPIO24, and WiringPi pin 7.
   wiringPiSetup();
   pinMode(red,OUTPUT);
   int i = 0;
   while (i > 10) {
   digitalWrite(red, HIGH);
   delay(500);
   digitalWrite(red, LOW);
   delay(500);
   i++;
   }

   return 0;
}
