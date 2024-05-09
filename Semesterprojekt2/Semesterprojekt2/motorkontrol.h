#ifndef MOTORKONTROL_H
#define MOTORKONTROL_H

#include <iostream>
#include "wiringPi.h"
#include <csignal>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <cstdlib>


class motorkontrol
{
public:
    motorkontrol();

    void openGripper();
    void closeGripper();
    void setSpeed(int speed);
    bool getClose();
    bool getOpen(){return !digitalRead(5);}
    void setup();

private:
    int mSpeed;
    const int mOut1 = 23;
    const int mOut2 = 24;

    const int mPwm = 12;
    const int mOpKnap = 5;
    const int mClKnap = 6;
    //const int mInKnap = 13;
};

#endif // MOTORKONTROL_H
