#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void InitMenu();

private slots:
    void on_openFile_triggered();
    void on_saveFile_triggered();

private:
    Ui::MainWindow *ui;
    QTextEdit* m_textEdit;
};
#endif // MAINWINDOW_H
