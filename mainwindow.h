#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serverframe.h"
#include "clientframe.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ServerFrame *serverframe;
    ClientFrame *clientframe;

public slots:
    void on_openServerFrame();
    void on_openClientFrame();

};

#endif // MAINWINDOW_H
