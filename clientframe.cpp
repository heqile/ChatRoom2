#include "clientframe.h"
#include "ui_clientframe.h"

ClientFrame::ClientFrame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientFrame)
{
    ui->setupUi(this);
    mclient = new tcpClient(this);
    ui->pushButton_Enter->setText("Enter");
    connect(ui->pushButton_Enter,SIGNAL(clicked(bool)),this,SLOT(onEnterOrExitRoom()));
    connect(ui->pushButton_Send,SIGNAL(clicked(bool)),this,SLOT(onSend()));
    connect(mclient,SIGNAL(signalServerUpdate(QString)),this,SLOT(onServerUpdate(QString)));
    connect(mclient,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(mclient,SIGNAL(readyRead()),mclient,SLOT(slotReceive()));
    connect(mclient,SIGNAL(signalServerStop()),this,SLOT(onServerStop()));
}

ClientFrame::~ClientFrame()
{
    delete ui;
}

void ClientFrame::onSend()
{
    QString text = ui->lineEdit_Name->text() + ": " + ui->lineEdit_text->text();
    int len = text.length();
    mclient->slotSend(text, len);
}

void ClientFrame::onServerUpdate(QString msg)
{
    ui->textBrowser->append(msg);
}

void ClientFrame::onDisconnected()
{
    QMessageBox::information(this,"Disconnected","Disconnected!");
}

void ClientFrame::onEnterOrExitRoom()
{
    if(ui->pushButton_Enter->text() == "Enter")
    {
        QString address = ui->lineEdit_ServerAddress->text();
        int port = ui->lineEdit_Port->text().toInt();
        if(mclient->slotConnect(address, port))
        {
            ui->pushButton_Enter->setText("Exit");
            QMessageBox::information(this,"Connected","Connected!");
        }
        else
        {
            QMessageBox::warning(this,"Error","Could not connect!");
        }

    }
    else
    {
        mclient->slotDisconnect();
        ui->pushButton_Enter->setText("Enter");
    }
}

void ClientFrame::onServerStop()
{
     qDebug() << "1";
    ui->textBrowser->append("Server stopped");
    ui->pushButton_Enter->setText("Enter");
}
