#ifndef MOTORKONTROL_H
#define MOTORKONTROL_H

#include <iostream>
#include "wiringPi.h"
#include <csignal>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <cstdlib>
#include <chrono>


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
    auto getTid(){return mTid;}
    int checkOpKnap();
    int checkClKnap();

private:
    int mSpeed;
    const int mOut1 = 5;
    const int mOut2 = 6;

    const int mPwm = 12;
    int mOpKnap = 23;
    int mClKnap = 24;
    //const int mInKnap = 13;
    int mTid;
};

#endif // MOTORKONTROL_H
