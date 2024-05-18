#ifndef UR5_H
#define UR5_H
#include <QObject>
#include <QtNetwork>
#include <QTcpSocket>
#include <QDebug>
#include <QTcpServer>
#include <iostream>
#include "wiringPi.h"


class UR5 : public QObject {
    Q_OBJECT

public:
    explicit UR5(QObject *parent = nullptr);

public slots:
    void newConnection();

private:
    QTcpServer *server;

};

#endif // UR5_H

