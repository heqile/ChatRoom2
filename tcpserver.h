#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "tcpserversocket.h"

class tcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit tcpServer(QObject *parent = 0);

private:

    QList<tcpServerSocket*> tcpClientList;
    QStringList textList;
signals:
    void signalServerUpdate(QString msg);
    void signalServerStopped();
    void signalServerStop();
    void signalServerCreated();

public slots:
    void onServerStop();
    void onNewConnection();
    void onClientUpdated(QString msg);
    void onClientDisconnected(int descriptor);
    void onCreateServer(int port);
};

#endif // TCPSERVER_H
