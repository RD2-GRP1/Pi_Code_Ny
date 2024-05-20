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

    socket->flush();

    while(1){
    delay(100);
    if(mk.checkClKnap()){
	delay(2000);
    socket->write("op");
    socket->flush();
    std::cout << "foelgende kommando er sendt: op" << std::endl;
    break;
      }
    }

   /* int i = 0;
    while(i <= 500) {
    delay(100);
        QByteArray date = socket->readAll();
    qDebug() << date;
    ++i; */
   // }
    //socket->waitForBytesWritten(3000);
    //socket->close();
}
