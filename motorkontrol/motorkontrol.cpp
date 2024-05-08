#include "motorkontrol.h"

motorkontrol::motorkontrol()
{
    mSpeed = 0;
}

void motorkontrol::openGripper() {
    if (digitalRead(mClKnap)) {
        digitalWrite(mOut1,LOW);
        digitalWrite(mOut2,LOW);


        pinMode (mPwm, PWM_OUTPUT);
        pwmSetMode(PWM_MODE_MS);
        pwmSetClock (3840);
        pwmSetRange (mSpeed);

        delay (10);
        while(!digitalRead(mOpKnap)) {
            digitalWrite(mOut1,HIGH);
            pwmWrite (mPwm, mSpeed/2)
        }
        digitalWrite(mOut1,LOW);
        pwmWrite (mPwm, 0)
        digitalWrite(mPwm,LOW);
    }
}
void motorkontrol::closeGripper() {
    if (digitalRead(mOpKnap)) {
        digitalWrite(mOut1,LOW);
        digitalWrite(mOut2,LOW);


        pinMode (mPwm, PWM_OUTPUT);
        pwmSetMode(PWM_MODE_MS);
        pwmSetClock (3840);
        pwmSetRange (mSpeed);

        delay (10);
        while(!digitalRead(mClKnap)) {
            digitalWrite(mOut2,HIGH);
            pwmWrite (mPwm, mSpeed/2)
        }
        digitalWrite(mOut2,LOW);
        pwmWrite (mPwm, 0)
        digitalWrite(mPwm,LOW);
    }
}
void motorkontrol::setSpeed(speed) {
    mSpeed = speed;
}
