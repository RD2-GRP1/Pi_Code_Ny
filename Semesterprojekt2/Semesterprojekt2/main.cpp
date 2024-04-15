#include <iostream>
#include "wiringPi.h"


int main()
{
    /*int red = 2;
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
    }*/

        // LEDPIN is wiringPi Pin #1 or GPIO #18
        // we choose this pin since it supports PWM as
        // PWM is not supported by any other GPIO pins.
        const int LEDPIN = 1;

        if (wiringPiSetup() == -1) {
            printf ("Setup wiringPi Failed!\n");
            return -1;
        }

        //printf ("Reminder: this program must be run with sudo. Delay 5 seconds.\n");
        //delay (5000);
        //printf ("   starting now.\n");
        pinMode (LEDPIN, PWM_OUTPUT);
        // set the PWM mode to Mark Space
        pwmSetMode(PWM_MODE_MS);
        // set the clock divisor to reduce the 19.2 Mhz clock
        // to something slower, 5 Khz.
        // Range of pwmSetClock() is 2 to 4095.
        pwmSetClock (3840);  // 19.2 Mhz divided by 3840 is 5 Khz.

        // set the PWM range which is the value for the range counter
        // which is decremented at the modified clock frequency.
        // in this case we are decrementing the range counter 5,000
        // times per second since the clock at 19.2 Mhz is being
        // divided by 3840 to give us 5 Khz.
        pwmSetRange (2500);  // range is 2500 counts to give us half second.

        delay (10);   // delay a moment to let hardware settings settle.




        while(1) {
            // range for the value written is 0 to 1024.
            pwmWrite (LEDPIN, 0);  // set the Duty Cycle for this range.
            // delay 10 seconds to watch the LED flash due to the PWM hardware.
        }


        // cleanup the environment. set each pin to low
        // and set the mode to INPUT. These steps make sure
        // the equipment is safe to manipulate and prevents
        // possible short and equipment damage from energized pin.
        pinMode(LEDPIN, INPUT);
        digitalWrite (LEDPIN, LOW);


    return 0;
}
