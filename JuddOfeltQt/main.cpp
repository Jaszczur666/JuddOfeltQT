#include "solverwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SolverWindow w;
    w.show();

    return a.exec();
}
