#include "tcpserver.h"

tcpServer::tcpServer(QObject *parent) : QTcpServer(parent)
{
 //   tcpServerSocket *test = new tcpServerSocket(this);
    connect(this,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
}

void tcpServer::onNewConnection()
{

    tcpServerSocket *newsocket = new tcpServerSocket(this);
    connect(newsocket,SIGNAL(signalDisconnect(int)),this,SLOT(onClientDisconnected(int)));
    connect(newsocket,SIGNAL(signalReadyRead(QString)),this,SLOT(onClientUpdated(QString)));
  //  connect(this,SIGNAL(signalServerUpdate(QString)),newsocket,SLOT(slotServerUpdate(QString)));
    newsocket->setSocketDescriptor(this->nextPendingConnection()->socketDescriptor());

    tcpClientList.append(newsocket);
    //qDebug() << "newsocket->socketDescriptor()";
    qDebug() << tcpClientList.at(0)->socketDescriptor();
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
