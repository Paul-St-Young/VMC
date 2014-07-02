#include "vmc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VMC w;
    w.show();

    return a.exec();
}
