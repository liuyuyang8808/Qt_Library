#include "UEProgressBar.h"
#include "ui_ueprogressBar.h"

UEProgressBar::UEProgressBar(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::UEProgressBar)
{
	ui->setupUi(this);

	InitAll();
}

UEProgressBar::~UEProgressBar()
{
	delete ui;
}

void UEProgressBar::InitAll()
{
}






