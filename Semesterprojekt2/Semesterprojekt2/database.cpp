#include "database.h"
#include <iostream>
#include "wiringPi.h"
#include <csignal>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <cstdlib>

database::database(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/pi/gripper.db");
    if (!db.open()) {
        qDebug() << "kan ikke forbinde til databasen" << db.lastError().text();
    } else {std::cout << "der er oprettet fobindelse til database" << std::endl;}
}

//Den tabel som vores program skal benytte
//"gripperData(ID INTEGER PRIMARY KEY AUTOINCREMENT, knap1 INTEGER, knap2 INTEGER, tid INTEGER, succes INTEGER)"
// query.prepare("INSERT into gripperData(knap1,knap2,tid,succes) VALUES (1,1,5,1)");


int database::getMaxID(){
    QSqlQuery query;
    query.prepare("SELECT MAX(ID) FROM gripperData;");
    if(query.next()){
        mID = query.value(0).toInt();
    }
    return mID;
}

void database::insertKnap1(bool opdaterK1){
QSqlQuery query;
    if(opdaterK1){
        query.prepare("INSERT into gripperData(knap1) VALUES (1) WHERE ID = :ID");
        mID = getMaxID();
        query.bindValue(":ID", mID);
        if(!query.exec()){std::cout << "failed to update mKnap1";}
        mKnap1 = 1;
    } else{
        query.prepare("INSERT into gripperData(knap1) VALUES (0) WHERE ID = :ID");
        mID = getMaxID();
        query.bindValue(":ID", mID);
        if(!query.exec()){std::cout << "failed to update mKnap1";}
        mKnap1 = 0;
    }
}

void database::insertKnap2(bool opdaterK2){
    QSqlQuery query;
    if(opdaterK2){
        query.prepare("INSERT into gripperData(knap2) VALUES (1)");
        if(!query.exec()){std::cout << "failed to update mKnap1";}
        mKnap2 = 1;
    } else{
        query.prepare("INSERT into gripperData(knap2) VALUES (0)");
        if(!query.exec()){std::cout << "failed to update mKnap1";}
        mKnap2 = 0;
    }

    if (mKnap2 && mKnap1){
        query.prepare("INSERT into gripperData(succes) VALUES (1)");
        if(!query.exec()){std::cout << "failed to update succes";}
    } else {
        query.prepare("INSERT into gripperData(succes) VALUES (0)");
        if(!query.exec()){std::cout << "failed to update succes";}
     }
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
