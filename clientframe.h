#ifndef CLIENTFRAME_H
#define CLIENTFRAME_H

#include <QDialog>
#include "tcpclient.h"

namespace Ui {
class ClientFrame;
}

class ClientFrame : public QDialog
{
    Q_OBJECT

public:
    explicit ClientFrame(QWidget *parent = 0);
    ~ClientFrame();    
private:
    Ui::ClientFrame *ui;
    tcpClient *mclient;
    QString name;
public slots:
    void onEnterOrExitRoom();
    void onServerStop();
    void onSend();
    void onServerUpdate(QString msg);
    void onDisconnected();
};

#endif // CLIENTFRAME_H
