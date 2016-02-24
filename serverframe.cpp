#include "serverframe.h"
#include "ui_serverframe.h"

ServerFrame::ServerFrame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerFrame)
{
    ui->setupUi(this);
    ui->pushButton_CreatServer->setText("Creat Server");
    mtcpsServer = new tcpServer(this);
    connect(ui->pushButton_CreatServer,SIGNAL(clicked(bool)),this,SLOT(slotCreateServer()));
    connect(this,SIGNAL(signalCreateServer(int)),mtcpsServer,SLOT(onCreateServer(int)));
    connect(mtcpsServer,SIGNAL(signalServerUpdate(QString)),this,SLOT(slotServerUpdated(QString)));
    connect(this,SIGNAL(signalServerStop()),mtcpsServer,SLOT(onServerStop()));
    connect(mtcpsServer,SIGNAL(signalServerStopped()),this,SLOT(slotServerStopped()));
    connect(mtcpsServer,SIGNAL(signalServerCreated()),this,SLOT(slotServerCreated()));
}

ServerFrame::~ServerFrame()
{
    delete ui;
}

void ServerFrame::slotServerStopped()
{
    ui->pushButton_CreatServer->setText("Creat Server");
    ui->textBrowser->append("Server stopped");
}

void ServerFrame::slotCreateServer()
{
    if(ui->pushButton_CreatServer->text() == "Creat Server")
    {
        port = ui->lineEdit_Port->text().toInt();
        emit signalCreateServer(port);
    }
    else
    {
        emit signalServerStop();
    }
}
void ServerFrame::slotServerCreated()
{
    ui->pushButton_CreatServer->setText("Stop Server");
    ui->textBrowser->append("Server created");
}
void ServerFrame::slotServerUpdated(QString msg)
{
    ui->textBrowser->append(msg);
}
