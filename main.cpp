#include <QTcpSocket>
#include <QHostAddress>

void sendURScriptCommand(const QString& command) {
    QTcpSocket socket;
    socket.connectToHost(QHostAddress("ROBOT_IP"), 30002); // Skift ROBOT_IP og porten om nødvendigt
    if(socket.waitForConnected()) {
        socket.write(command.toUtf8());
        socket.waitForBytesWritten();
        socket.disconnectFromHost();
    } else {
        qDebug() << "Unable to connect to the robot.";
    }
}

int main() {
    // Eksempelkommando: Flyt til en bestemt position
    QString urScriptCommand = "movej([0.1, -0.3, 0.5, -1.6, 1.5, 0.8], a=0.5, v=0.1)\n";

    // Send URScript-kommandoen til robotten
    sendURScriptCommand(urScriptCommand);

    return 0;
}
