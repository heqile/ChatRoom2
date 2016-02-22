#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class tcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit tcpServer(QObject *parent = 0);

private:

    QList<QTcpSocket*> tcpClientList;
    QStringList textList;
signals:
    void ServerUpdate();

public slots:
    void onNewConnection();
    void onClientUpdated();
    void onClientDisconnected();
    void onCreateServer(int port);
};

#endif // TCPSERVER_H
