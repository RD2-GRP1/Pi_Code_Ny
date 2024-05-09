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
    void updateKnap1(int opdaterK1);
    void updateKnap2(int opdaterK2);
    void updateSucces(int opdaterS);

private:
    int mKnap1;
    int mKnap2;
    int mSucces;
    int mTid;
    int mID;
    QSqlQuery query;
};

#endif // DATABASE_H
