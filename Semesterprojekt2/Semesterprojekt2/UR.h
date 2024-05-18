#ifndef UR_H
#define UR_H

#include <QtWidgets>
#include <QTcpSocket>
#include <QApplication>

class UR : public QWidget {
    Q_OBJECT

public:
    UR();
    UR(QWidget *parent = nullptr) : QWidget(parent) {
        socket = new QTcpSocket(this);
        connect(socket, &QTcpSocket::connected, this, &UR::connected);
        connect(socket, &QTcpSocket::disconnected, this, &UR::disconnected);
        connect(socket, &QTcpSocket::readyRead, this, &UR::readyRead);

        connectBtn = new QPushButton("Connect", this);
        connect(connectBtn, &QPushButton::clicked, this, &UR::connectToServer);

        moveBtn = new QPushButton("Move", this);
        connect(moveBtn, &QPushButton::clicked, this, &UR::moveUR);

        mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(connectBtn);
        mainLayout->addWidget(moveBtn);

        setLayout(mainLayout);
    }

public slots:

    void connectToServer();

    void connected();

    void disconnected();

    void readyRead();

    void moveUR();

private:
    QTcpSocket *socket;
    QPushButton *connectBtn;
    QPushButton *moveBtn;
    QVBoxLayout *mainLayout;
};

#endif // UR_H
