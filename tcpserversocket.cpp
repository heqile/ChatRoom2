#include "tcpserversocket.h"

tcpServerSocket::tcpServerSocket(QObject *parent) : QObject(parent)
{

}

void tcpServerSocket::slotServerStop()
{
    mtcpSocket->write("Server Stopped");
    mtcpSocket->flush();
    mtcpSocket->close();
}

void tcpServerSocket::slotDisconnect()
{
    int descriptor = 0;
    descriptor = mtcpSocket->socketDescriptor();
    emit signalDisconnect(descriptor);
}

void tcpServerSocket::slotReadyRead()
{
    QString msg;
    qDebug() << "received";
    msg = mtcpSocket->readAll();
    emit signalReadyRead(msg);
}

void tcpServerSocket::slotServerUpdate(QString msg)
{
    mtcpSocket->write(msg.toLatin1());
    mtcpSocket->flush();
    mtcpSocket->waitForBytesWritten(2000);
}
