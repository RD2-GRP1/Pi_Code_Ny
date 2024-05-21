#include "motorkontrol.h"
#include <iostream>


motorkontrol::motorkontrol()
{
    wiringPiSetupGpio();

    mSpeed = 0;

    pinMode(mOut1, OUTPUT);
    pinMode(mOut2, OUTPUT);
    pinMode(mPwm, OUTPUT);
    pinMode(mOpKnap, INPUT);
    pinMode(mClKnap, INPUT);

    digitalWrite(mOut1,LOW);
    digitalWrite(mOut2,LOW);
    digitalWrite(mPwm,LOW);
    digitalWrite(mOpKnap, LOW);
    digitalWrite(mClKnap, LOW);
}


void motorkontrol::openGripper() {
    delay(4000);
    digitalWrite(mOut1,HIGH);
    digitalWrite(mOut2,LOW);

    pinMode (mPwm, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock (3840);
    pwmSetRange (2500);
    delay(10);
    pwmWrite (mPwm, mSpeed);

    while(1){
        std::cout << "Closed: " << std::endl;
        if(digitalRead(mOpKnap)){
            pwmWrite (mPwm, 0);
            digitalWrite(mOut1,LOW);
            return;
        }
        delay(50);
    }

}

void motorkontrol::closeGripper() {
    digitalWrite(mOut1,LOW);
    digitalWrite(mOut2,HIGH);


    pinMode (mPwm, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock (3840);
    pwmSetRange (2500);
    delay(1000);
    auto start = std::chrono::high_resolution_clock::now();
    auto deadline = start + std::chrono::seconds(8);
    pwmWrite (mPwm, mSpeed);

    while(1){
        std::cout << "Open: " << std::endl;
        if(digitalRead(mClKnap)){
            delay(2000);
            pwmWrite (mPwm, 0);
            digitalWrite(mOut2,LOW);
            auto stop = std::chrono::high_resolution_clock::now();
           if (deadline<=stop) {
               mTid = std::chrono::duration_cast<std::chrono::milliseconds>(deadline-start).count();
            } else {
               mTid = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start).count();
            }
            return;
        }
        delay(50);
    }
}


void motorkontrol::setSpeed(int speed){
    mSpeed = speed;
}


int motorkontrol::checkClKnap() {
    std::cout << "Check Closed: " << std::endl;
    return digitalRead(mClKnap);
}

int motorkontrol::checkOpKnap() {
    std::cout << "Check Open: " << std::endl;
    return digitalRead(mOpKnap);
}
