#include "mainwindow.h"
#include "Library/UEProgressBar.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UEProgressBar w;
    w.show();
    return a.exec();
}
