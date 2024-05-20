#include "UR5.h"
#include "wiringPi.h"
#include "motorkontrol.h"

UR5::UR5(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection,
            this, &UR5::newConnection);

    if(!server->listen(QHostAddress("192.168.1.69"), 29999))
       {
           qDebug() << "Server could not start";
       }
       else
       {
           qDebug() << "Server started!";
       }
}

void UR5::newConnection(){
    motorkontrol mk;
    QTcpSocket *socket = server->nextPendingConnection();
    
    socket->write("ned");
    std::cout << "Robot Ned: " << std::endl;
    socket->flush();

    while(1){
        std::cout << "Robot Check: " << std::endl;
        delay(100);
        if(mk.checkClKnap()){
            delay(2000);
            std::cout << "Robot Op: " << std::endl;
            socket->write("op");
            socket->flush();
            break;
        }
    }
}
