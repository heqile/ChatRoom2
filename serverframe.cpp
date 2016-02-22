#include "serverframe.h"
#include "ui_serverframe.h"

ServerFrame::ServerFrame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerFrame)
{
    ui->setupUi(this);
}

ServerFrame::~ServerFrame()
{
    delete ui;
}
