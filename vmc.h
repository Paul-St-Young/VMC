#ifndef VMC_H
#define VMC_H

#include <QMainWindow>
#include "metropolis.h"

namespace Ui {
class VMC;
}

class VMC : public QMainWindow
{
    Q_OBJECT

public:
    explicit VMC(QWidget *parent = 0);
    ~VMC();

private slots:
    void on_Start_clicked();

private:
    Ui::VMC *ui;
};

#endif // VMC_H
