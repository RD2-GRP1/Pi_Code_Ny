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

//Den tabel som vores program benytter
//"CREATE TABLE gripperData(ID INTEGER PRIMARY KEY AUTOINCREMENT, knap1 INTEGER, knap2 INTEGER, tid INTEGER, succes INTEGER)"
// query.prepare("INSERT into gripperData(knap1,knap2,tid,succes) VALUES (1,1,5,1)");

/*
int database::getMaxID(){
    QSqlQuery query;
    query.prepare("SELECT MAX(ID) FROM gripperData;");
    if(query.next()){
        mID = query.value(0).toInt();
    }
    return mID;
}*/

void database::insertRow(){
    QSqlQuery query;
    query.prepare("INSERT into gripperData(knap1, knap2, tid, succes) VALUES (:knap1, :knap2, :tid, :succes)");

    query.bindValue(":ID", 0);
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

    //husk at kør setKnap1 først
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




/* (uden parameter eksempel
void database::updateKnap2(){
    if(digitalRead(mKnap2)){
        query.prepare("UPDATE gripperData SET knap2 = 1 WHERE ID = :ID");
        query.bindValue(":ID", mID);
        if(!query.exec()){std::cout << "failed to update knap2";}
    } else{
        query.prepare("UPDATE gripperData SET knap2 = 0 WHERE ID = :ID");
        query.bindValue(":ID", mID);
        if(!query.exec()){std::cout << "failed to update knap2";}
    }
} */


/*
void database::insertSucces(bool opdaterS){
    QSqlQuery query;
    if(opdaterS){
        query.prepare("INSERT into gripperData(succes) VALUES (1)");
        if(!query.exec()){std::cout << "failed to update succes";}
    } else{
        query.prepare("INSERT into gripperData(succes) VALUES (0)");
        if(!query.exec()){std::cout << "failed to update succes";}
    }
} */

/* Not finished
updateTime(){
//member variable knap1ToKnap2TImer
    while(totalTime < 20sekunder){
        if(knap1){start knap1ToLnap2Timer;
            if(knap2){
                stop kanp1ToKnap2Timer;
            }

        }
    }
} */
