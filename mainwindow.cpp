#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_CreateServer,SIGNAL(clicked(bool)),this,SLOT(on_openServerFrame()));
    connect(ui->pushButton_EnterRoom,SIGNAL(clicked(bool)),this,SLOT(on_openClientFrame()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openServerFrame()
{
    serverframe = new ServerFrame(this);
    serverframe->show();
}

void MainWindow::on_openClientFrame()
{
    clientframe = new ClientFrame(this);
    clientframe->show();
}

