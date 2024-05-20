#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include "wiringPi.h"
#include <csignal>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <cstdlib>

class database
{
public:
    database();
    void setKnap1(bool opdaterK1);
    void setKnap2(bool opdaterK2);
    void insertRow();
    void setTime(int tid);


private:
    int mKnap1;
    int mKnap2;
    int mSucces;
    int mTid;
};

#endif // DATABASE_H
