#ifndef SERVERFRAME_H
#define SERVERFRAME_H

#include <QDialog>

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
};

#endif // SERVERFRAME_H
