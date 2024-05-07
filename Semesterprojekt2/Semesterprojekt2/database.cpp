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
    if (!db.open()){qDebug() << "kan ikke forbinde til databasen" << db.lastError().text();}
    }




UpdateKnap1(){
    if(knap1){
        query.prepare("UPDATE gripperData SET knap1 = 1 WHERE ID = :ID");
        query.bindValue(":ID", mID);
        if(!query.exec()){std::cout << "failed to update knap1";}
    } else{
        query.prepare("UPDATE gripperData SET knap1 = 0 WHERE ID = :ID")
        query.bindValue(":ID", mID);
        if(!query.exec()){std::cout << "failed to update knap1";}
    }
}
