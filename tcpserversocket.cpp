#include "tcpserversocket.h"

tcpServerSocket::tcpServerSocket(QObject *parent) : QTcpSocket(parent)
{

    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnect()));
    connect(this,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
}

void tcpServerSocket::slotDisconnect()
{
    int descriptor = 0;
    descriptor = this->socketDescriptor();
    emit signalDisconnect(descriptor);
}

void tcpServerSocket::slotReadyRead()
{
    QString msg;
    qDebug() << "received";
    msg = this->readAll();
    emit signalReadyRead(msg);
}

void tcpServerSocket::slotServerUpdate(QString msg)
{
    this->write(msg.toLatin1());
    this->flush();
    this->waitForBytesWritten(2000);
}
