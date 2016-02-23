#include "tcpserver.h"

tcpServer::tcpServer(QObject *parent) : QTcpServer(parent)
{
    connect(this,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
}

void tcpServer::onNewConnection()
{

    tcpServerSocket *newsocket = new tcpServerSocket;
    connect(newsocket,SIGNAL(signalDisconnect(int)),this,SLOT(onClientDisconnected(int)));
    connect(newsocket,SIGNAL(signalReadyRead(QString)),this,SLOT(onClientUpdated(QString)));
    connect(this,SIGNAL(signalServerUpdate(QString)),newsocket,SLOT(slotServerUpdate(QString)));
    newsocket->setSocketDescriptor(this->nextPendingConnection()->socketDescriptor());

    tcpClientList.append(newsocket);
    //qDebug() << "newsocket->socketDescriptor()";
}

void tcpServer::onClientUpdated(QString msg)
{
    emit signalServerUpdate(msg);
}

void tcpServer::onClientDisconnected(int descriptor)
{
    int i = 0;
    for(i = 0; i < tcpClientList.count(); i++)
    {
        if(tcpClientList.at(i)->socketDescriptor() == descriptor)
        {
            tcpClientList.removeAt(i);
            return;
        }
    }
            // -->error

}

void tcpServer::onCreateServer(int port)
{
    this->listen(QHostAddress::Any, port);
    if(this->isListening())
        qDebug() << "server start";
}
