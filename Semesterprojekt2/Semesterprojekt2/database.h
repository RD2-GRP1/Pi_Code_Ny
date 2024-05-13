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
    int getMaxID();
    void insertRow();
    void setTime(int tid);
    //void insertSucces(bool opdaterS);

private:
    int mKnap1;
    int mKnap2;
    int mSucces;
    int mTid;
    int mID;
    QSqlDatabase db;
};

#endif // DATABASE_H
