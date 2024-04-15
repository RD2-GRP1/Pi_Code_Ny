#include <iostream>
#include "wiringPi.h"
#include <csignal>

 bool RUNNING = 1;
void myhandler(int s){
    RUNNING = false;
}

int main()
{

    // controll a diode using buttons
    /*
    wiringPiSetupGpio();

    int in1 = 23;
    int in2 = 24;

    int out1 = 16;
    int out2 = 20;

    if(wiringPiSetup() == -1){exit;}
    std::cout << "setting pins" << std::endl;
    pinMode(in1, INPUT);
    pinMode(in2, INPUT);
    pinMode(out1, OUTPUT);
    pinMode(out2, OUTPUT);

    while(1)
        if(!(digitalRead(in1) || digitalRead(in2))) {
            digitalWrite(out1,HIGH);
        } else {
            digitalWrite(out1,LOW);
        }
*/



    //std::signal(SIGINT, myhandler);

    wiringPiSetupGpio();
    int in1 = 23;
    int in2 = 24;
    int pwm = 12;


    std::cout << "setting pins" << std::endl;
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(pwm, OUTPUT);

    //digitalWrite(in1,LOW);
    //digitalWrite(in2,LOW);
    digitalWrite(pwm,LOW);


    pinMode (pwm, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock (3840);
    pwmSetRange (200);

    delay (10);
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);



    while(1){
        pwmWrite (pwm, 100);
        delay(10000);
        break;
    }

    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(pwm,LOW);


/*
        // LEDPIN is wiringPi Pin #1 or GPIO #18
        // we choose this pin since it supports PWM as
        // PWM is not supported by any other GPIO pins.
        const int LEDPIN = 26;

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
        pwmSetRange (5000);  // range is 2500 counts to give us half second.

        delay (10);   // delay a moment to let hardware settings settle.



        int x;
        std::cin >> x;
            std::cout << x << std::endl;
            delay(50);
            // range for the value written is 0 to 1024.
        for(int i = 0; i<5000; ++i) {
            std::cout << i << std::endl;
            delay(25);
            pwmWrite (LEDPIN, i);  // set the Duty Cycle for this range.
            // delay 10 seconds to watch the LED flash due to the PWM hardware.
        }


        // cleanup the environment. set each pin to low
        // and set the mode to INPUT. These steps make sure
        // the equipment is safe to manipulate and prevents
        // possible short and equipment damage from energized pin.
        pinMode(LEDPIN, INPUT);
        digitalWrite (LEDPIN, LOW);

*/
    return 0;

}
