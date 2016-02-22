#include "tcpserver.h"

tcpServer::tcpServer(QObject *parent) : QTcpServer(parent)
{
    connect(this,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
}

void tcpServer::onNewConnection()
{
    QTcpSocket *newsocket = this->nextPendingConnection();

    tcpClientList.append(newsocket);
}

void tcpServer::onCreateServer(int port)
{
    this->listen(QHostAddress::Any, port);
}
