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
    //pinMode(mInKnap, INPUT);

    digitalWrite(mOut1,LOW);
    digitalWrite(mOut2,LOW);
    digitalWrite(mPwm,LOW);
    digitalWrite(mOpKnap, LOW);
    digitalWrite(mClKnap, LOW);
   // digitalWrite(mInKnap, LOW);
}


void motorkontrol::openGripper() {
    digitalWrite(mOut1,HIGH);
    digitalWrite(mOut2,LOW);



    pinMode (mPwm, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock (3840);
    pwmSetRange (2500);
    std::cout << mSpeed << std::endl;
    pwmWrite (mPwm, mSpeed);
    while(1){
        delay(5000);
        if(1){ //!digitalRead(mOpKnap)
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
    //std::cout << mSpeed << std::endl;
    delay(1000);
    auto start = std::chrono::high_resolution_clock::now();
    auto deadline = start + std::chrono::seconds(15);
    pwmWrite (mPwm, mSpeed);
    int var = 0;
    while(1){

        std::cin >> var;


        /*!digitalRead(mClKnap)*/
        if(var){
            delay(50);
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


void motorkontrol::setup() {
    if(!digitalRead(mOpKnap)) {
        digitalWrite(mOut1,LOW);
        digitalWrite(mOut2,LOW);

        pinMode (mPwm, PWM_OUTPUT);
        pwmSetMode(PWM_MODE_MS);
        pwmSetClock (3840);
        pwmSetRange (mSpeed);

        delay (10);
        while(!digitalRead(mOpKnap)) {
            digitalWrite(mOut1,HIGH);
            pwmWrite (mPwm, mSpeed/2);
        }
        digitalWrite(mOut1,LOW);
        pwmWrite (mPwm, 0);
        digitalWrite(mPwm,LOW);
    }
}


void motorkontrol::setSpeed(int speed){
    mSpeed = speed;
}

bool motorkontrol::getClose(){
    bool in1 = !digitalRead(6);
    std::cout << in1 << std::endl;
    return in1;
}
