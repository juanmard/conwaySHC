#include <QApplication>
#include "mainwindow.h"

#include "matbin.hpp"
#include "paleta.hpp"
#include "patron.hpp"
#include "conversor.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
