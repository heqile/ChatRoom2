#ifndef SERVERFRAME_H
#define SERVERFRAME_H

#include <QDialog>
#include "tcpserver.h"

namespace Ui {
class ServerFrame;
}

class ServerFrame : public QDialog
{
    Q_OBJECT

public:
    explicit ServerFrame(QWidget *parent = 0);
    ~ServerFrame();

private:
    Ui::ServerFrame *ui;
    tcpServer *mtcpsServer;
    int port;

signals:
    void signalCreateServer(int port);
    void signalServerStop();

public slots:
    void slotServerCreated();
    void slotServerStopped();
    void slotCreateServer();
    void slotServerUpdated(QString msg);
};

#endif // SERVERFRAME_H
