#include "tcpclient.h"


tcpClient::tcpClient(QObject *parent) : QTcpSocket(parent)
{

}

void tcpClient::slotSend(QString msg, int length)
{
    this->write(msg.toLatin1(),length);
}

void tcpClient::slotDisconnect()
{
    this->disconnectFromHost();
}

bool tcpClient::slotConnect(QString address, int port)
{
    this->connectToHost(address,port);
    if(!this->waitForConnected(3000))
    {
        return false;
    }
    else
    {
        return true;
    }
}


/*
void tcpClient::slotServerUpdate()
{
    QString msg;
    while(this->bytesAvailable())
    {
        msg = this->readAll();
        //emit signalClientUpdate();
    }
}

void tcpClient::slotDisconnect()
{
    emit signalDisconnected(this->socketDescriptor());
}
*/
