#include "serverframe.h"
#include "ui_serverframe.h"

ServerFrame::ServerFrame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerFrame)
{
    ui->setupUi(this);
    mtcpsServer = new tcpServer(this);
    connect(ui->pushButton_CreatServer,SIGNAL(clicked(bool)),this,SLOT(slotCreateServer()));
    connect(this,SIGNAL(signalCreateServer(int)),mtcpsServer,SLOT(onCreateServer(int)));
    connect(mtcpsServer,SIGNAL(signalServerUpdate(QString)),this,SLOT(slotServerUpdated(QString)));
}

ServerFrame::~ServerFrame()
{
    delete ui;
}

void ServerFrame::slotCreateServer()
{
    port = ui->lineEdit_Port->text().toInt();
    emit signalCreateServer(port);
}

void ServerFrame::slotServerUpdated(QString msg)
{
    ui->textBrowser->append(msg);
}
