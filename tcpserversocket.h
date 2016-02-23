#ifndef TCPSERVERSOCKET_H
#define TCPSERVERSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class tcpServerSocket : public QObject
{
    Q_OBJECT
public:
    explicit tcpServerSocket(QObject *parent = 0);
    QTcpSocket *mtcpSocket;
signals:
    void signalDisconnect(int descriptor);
    void signalReadyRead(QString msg);

public slots:
    void slotDisconnect();
    void slotReadyRead();
    void slotServerUpdate(QString msg);

};

#endif // TCPSERVERSOCKET_H
