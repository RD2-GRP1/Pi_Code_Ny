#include <QtWidgets>
#include <QTcpSocket>

class URClient : public QWidget {
    Q_OBJECT

public:
    URClient(QWidget *parent = nullptr) : QWidget(parent) {
        socket = new QTcpSocket(this);
        connect(socket, &QTcpSocket::connected, this, &URClient::connected);
        connect(socket, &QTcpSocket::disconnected, this, &URClient::disconnected);
        connect(socket, &QTcpSocket::readyRead, this, &URClient::readyRead);

        connectBtn = new QPushButton("Connect", this);
        connect(connectBtn, &QPushButton::clicked, this, &URClient::connectToServer);

        moveBtn = new QPushButton("Move", this);
        connect(moveBtn, &QPushButton::clicked, this, &URClient::moveUR);

        mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(connectBtn);
        mainLayout->addWidget(moveBtn);

        setLayout(mainLayout);
    }

private slots:
    void connectToServer() {
        socket->connectToHost("192.168.1.54", 29999); // Change IP address and port as per your setup
    }

    void connected() {
        qDebug() << "Connected to server";
    }

    void disconnected() {
        qDebug() << "Disconnected from server";
    }

    void readyRead() {
        qDebug() << "Received data from server: " << socket->readAll();
    }

    void moveUR() {
        // Send movement command to the UR robot
        QByteArray data = "movel(p[1.0, 2.0, 3.0, 0.0, 0.0, 0.0], a=1.2, v=0.1)\n";
        socket->write(data);
    }

private:
    QTcpSocket *socket;
    QPushButton *connectBtn;
    QPushButton *moveBtn;
    QVBoxLayout *mainLayout;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    URClient client;
    client.show();

    return app.exec();
}

#include "main.moc"
