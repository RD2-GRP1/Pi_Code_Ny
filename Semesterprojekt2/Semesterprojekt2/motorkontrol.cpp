#include "motorkontrol.h"

motorkontrol::motorkontrol()
{
    wiringPiSetupGpio();

    mSpeed = 0;

    pinMode(mOut1, OUTPUT);
    pinMode(mOut2, OUTPUT);
    pinMode(mPwm, OUTPUT);
    pinMode(mOpKnap, INPUT);
    pinMode(mClKnap, INPUT);
    pinMode(mInKnap, INPUT);

    digitalWrite(mOut1,LOW);
    digitalWrite(mOut2,LOW);
    digitalWrite(mPwm,LOW);
    digitalWrite(mOpKnap, LOW);
    digitalWrite(mClKnap, LOW);
    digitalWrite(mInKnap, LOW);
}

void motorkontrol::openGripper() {
    if (digitalRead(mClKnap) && digitalRead(mInKnap)) {
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
void motorkontrol::closeGripper() {
    if (digitalRead(mOpKnap) && digitalRead(mInKnap)) {
        digitalWrite(mOut1,LOW);
        digitalWrite(mOut2,LOW);


        pinMode (mPwm, PWM_OUTPUT);
        pwmSetMode(PWM_MODE_MS);
        pwmSetClock (3840);
        pwmSetRange (mSpeed);

        delay (10);
        while(!digitalRead(mClKnap)) {
            digitalWrite(mOut2,HIGH);
            pwmWrite (mPwm, mSpeed/2);
        }
        digitalWrite(mOut2,LOW);
        pwmWrite (mPwm, 0);
        digitalWrite(mPwm,LOW);
    }
}
void motorkontrol::setSpeed(int speed) {
    mSpeed = speed;
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
