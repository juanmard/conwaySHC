#include <QApplication>
#include "mainwindow.h"

#include "matbin.hpp"
#include "paleta.hpp"
#include "patron.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Pruebas simples de clases.
   SHC::MatBin prueba(6,6);
   prueba[1][1]=prueba[1][2]=SHC::Celda::full;
   prueba[2][1]=prueba[2][2]=SHC::Celda::full;

   SHC::Patron patron;
   patron[1][1]=patron[1][2]=SHC::Celda::full;
   patron[2][1]=patron[2][2]=SHC::Celda::full;

   SHC::Paleta paleta;

   paleta.add('c',&patron);

   // -----------------------------
   w.show();
   return a.exec();
}
