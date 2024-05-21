
#include "database.h"
#include <iostream>
#include "wiringPi.h"
#include <csignal>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <cstdlib>
#include <chrono>

database::database(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/pi/gripper.db");
    if (!db.open()) {
        qDebug() << "kan ikke forbinde til databasen" << db.lastError().text();
    } else {std::cout << "der er oprettet forbindelse til database" << std::endl;}
}


void database::insertRow(){
    QSqlQuery query;
    query.prepare("INSERT into gripperData(knap1, knap2, tid, succes) VALUES (:knap1, :knap2, :tid, :succes)");

    query.bindValue(":knap1", mKnap1);
    query.bindValue(":knap2", mKnap2);
    query.bindValue(":tid", mTid);
    query.bindValue(":succes", mSucces);

    if(!query.exec()){std::cout << "failed to insert row";}
}

void database::setKnap1(bool opdaterK1){
QSqlQuery query;
    if(opdaterK1){
        mKnap1 = 1;
    std::cout << "opdateret true knap1" << std::endl;
    } else{
        mKnap1 = 0;
    std::cout << "opdateret flase knap1" << std::endl;
    }
}

void database::setKnap2(bool opdaterK2){
    QSqlQuery query;
    if(opdaterK2) {
        mKnap2 = 1;
        std::cout << "opdtaret true knap2" << std::endl;
    } else{
        mKnap2 = 0;
        std::cout << "opdateret false knap2" << std::endl;
    }

    if (mKnap2 && mKnap1){
        mSucces = 1;
        std::cout << "opdateret true ved succes" << std::endl;
    } else {
        mSucces = 0;
        std::cout << "opdateret false ved succes" << std::endl;
     }
}


void database::setTime(int tid){
    mTid = tid;
   std::cout << "tiden er sat" << std::endl;
}




