#include "database.h"
#include <iostream>
#include "wiringPi.h"
#include <csignal>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <cstdlib>


database::database(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/pi/gripper.db");
    db.open();
    if (!db.open()) {
        qDebug() << "kan ikke forbinde til databasen" << db.lastError().text();
    }
    std::cout << "der er oprettet fobindelse til database" << std::endl;
}

//Den tabel som vores program skal benytte
//"CREATE TABLE gripperData(ID INTEGER PRIMARY KEY AUTOINCREMENT, knap1 INTEGER, knap2 INTEGER, tid INTEGER, succes INTEGER)"


void database::updateKnap1(int opdaterK1){
    if(opdaterK1){
        query.prepare("UPDATE gripperData SET knap1 = 1 WHERE ID = :ID");
        query.bindValue(":ID", mID);
        if(!query.exec()){std::cout << "failed to update mKnap1";}
    } else{
        query.prepare("UPDATE gripperData SET knap1 = 0 WHERE ID = :ID");
        query.bindValue(":ID", mID);
        if(!query.exec()){std::cout << "failed to update mKnap1";}
    }
}

void database::updateKnap2(int opdaterK2){
    if(opdaterK2){
        query.prepare("UPDATE gripperData SET knap2 = 1 WHERE ID = :ID");
        query.bindValue(":ID", mID);
        if(!query.exec()){std::cout << "failed to update knap2";}
    } else{
        query.prepare("UPDATE gripperData SET knap2 = 0 WHERE ID = :ID");
        query.bindValue(":ID", mID);
        if(!query.exec()){std::cout << "failed to update knap2";}
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

void database::updateSucces(int opdaterS){
    if(opdaterS){
        query.prepare("UPDATE gripperData SET succes = 1 WHERE ID = :ID");
        query.bindValue(":ID", mID);
        if(!query.exec()){std::cout << "failed to update succes";}
    } else{
        query.prepare("UPDATE gripperData SET succes = 0 WHERE ID = :ID");
        query.bindValue(":ID", mID);
        if(!query.exec()){std::cout << "failed to update succes";}
    }
}

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
