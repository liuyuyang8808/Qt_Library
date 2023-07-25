#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitMenu()
{
    QMenuBar* menuBar = this->menuBar();

    QMenu* menuFile = menuBar->addMenu(tr("File"));
    QMenu* menuEdit = menuBar->addMenu(tr("Edit"));
    QMenu* menuView = menuBar->addMenu(tr("View"));


    // get menuFile
    QAction* actionNew = menuFile->addAction(tr("New"));
    actionNew->setIcon(QIcon(":/images/new.png"));
    QAction* actionOpen = menuFile->addAction(tr("Open"));
    QAction* actionSave = menuFile->addAction(tr("Save"));


    connect(actionOpen, &QAction::triggered, this, &MainWindow::on_openFile_triggered);
    connect(actionSave, &QAction::triggered, this, &MainWindow::on_saveFile_triggered);
}



void MainWindow::on_openFile_triggered()
{
    QString fileFilter = "Open File (*.txt);; Header File (*.h);; Source File (*.cpp)";

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);; Source Files (*.h)"));
	if (fileName.isEmpty())
		return;
    else 
    {
       qDebug() << fileName;
    }
    
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
		qDebug() << "Open file failed!";
		return;
	}
	QTextStream in(&file);
    while (!in.atEnd())
    {
		QString line = in.readLine();
		qDebug() << line;
        ui->textEdit->append(line);
	}
    file.close();
}


void MainWindow::on_saveFile_triggered()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);; Source Files (*.h)"));
	if (fileName.isEmpty())
		return;
    else
    {
	   qDebug() << fileName;
	}
	
	QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
		qDebug() << "Open file failed!";
		return;
	}
	QTextStream out(&file);
	out << ui->textEdit->toPlainText();
	file.close();
}
