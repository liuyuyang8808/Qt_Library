#include "mainwindow.h"
#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include "Library/UEProgressBar.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* window = new MainWindow();
    UEProgressBar* bar = new UEProgressBar(window);
    QVBoxLayout* layout = new QVBoxLayout;

    window->setLayout(layout);
    layout->addWidget(bar);

    window->show();
    return a.exec();
}
