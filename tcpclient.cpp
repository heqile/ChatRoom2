#include "tcpclient.h"


tcpClient::tcpClient(QObject *parent) : QTcpSocket(parent)
{
    //connect(this,SIGNAL(disconnected()),this,SLOT(slotServerStop()));
}

void tcpClient::slotServerStop()
{
       emit signalServerStop();
}

void tcpClient::slotSend(QString msg, int length)
{
    this->write(msg.toLatin1(),length);
//    qDebug() << QString::number(i);
    qDebug() <<msg;
     this->flush();
   // qDebug() << i;
    if(this->waitForBytesWritten(100))
        qDebug() << "send";
}

void tcpClient::slotReceive()
{
    qDebug() << "ok";
    QString msg;
    msg = this->readAll();
    if(msg == "Server Stopped")
        slotServerStop();
    else
        emit signalServerUpdate(msg);
}

void tcpClient::slotDisconnect()
{
    this->disconnectFromHost();
}

bool tcpClient::slotConnect(QString address, int port)
{
    this->connectToHost(address,port);
    //this->connectToHost("",1234);
    return this->waitForConnected(3000);

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
