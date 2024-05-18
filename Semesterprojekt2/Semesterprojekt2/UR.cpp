#include "UR.h"

UR::UR()
{

}

void UR::connectToServer() {
    socket->connectToHost("192.168.1.54", 29999); // Change IP address and port as per your setup
}

void UR::connected() {
    qDebug() << "Connected to server";
}

void UR::disconnected() {
    qDebug() << "Disconnected from server";
}

void UR::readyRead() {
    qDebug() << "Received data from server: " << socket->readAll();
}

void UR::moveUR() {
    // Send movement command to the UR robot
    QByteArray data = "movel(p[1.0, 2.0, 3.0, 0.0, 0.0, 0.0], a=1.2, v=0.1)\n";
    socket->write(data);
}
