#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>

class tcpClient : public QTcpSocket
{
    Q_OBJECT
public:
    explicit tcpClient(QObject *parent = 0);

signals:
    void signalServerUpdate(QString msg);
    void signalDisconnected(int clientdescritpor);

public slots:
    void slotSend(QString msg, int length);
    void slotReceive();
    void slotDisconnect();
    bool slotConnect(QString address, int port);

};

#endif // TCPCLIENT_H
