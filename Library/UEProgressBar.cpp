#include "UEProgressBar.h"
#include "ui_ueprogressBar.h"
#include <QDebug>

UEProgressBar::UEProgressBar(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::UEProgressBar)
{
	ui->setupUi(this);

	m_progress_bar = ui->progressBar;

	InitAll();
}

UEProgressBar::~UEProgressBar()
{
	delete ui;
}

void UEProgressBar::InitAll()
{
	setCursor(Qt::SizeHorCursor);
}

void UEProgressBar::enterEvent(QEvent* event)
{
	qDebug() << "enter event";
}

void UEProgressBar::leaveEvent(QEvent* event)
{
	qDebug() << "leave event";
}

void UEProgressBar::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		this->setMouseTracking(true);
	}

	qDebug() << "mouse press";
}

void UEProgressBar::mouseReleaseEvent(QMouseEvent* event)
{
	this->setMouseTracking(false);
	setCursor(Qt::SizeHorCursor);

	qDebug() << "mouse release";
}

void UEProgressBar::mouseMoveEvent(QMouseEvent* event)
{
	setCursor(Qt::BlankCursor);

	m_is_mouse_move = true;
	m_current_mouse_pos = event->pos().x();
	int delta = m_current_mouse_pos - m_last_mouse_pos;
	m_current_mouse_pos += delta;

	m_progress_bar->setValue(m_current_mouse_pos);

	

	qDebug() << "mouse move";
}







