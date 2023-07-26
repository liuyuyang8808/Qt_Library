#include "UEProgressBar.h"
#include "ui_ueprogressBar.h"
#include <QDebug>

UEProgressBar::UEProgressBar(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::UEProgressBar)
{
	ui->setupUi(this);

	m_progress_bar = ui->progressBar;
	m_line_edit = ui->lineEdit;

	InitAll();
}

UEProgressBar::~UEProgressBar()
{
	delete ui;
}

void UEProgressBar::InitAll()
{
	setCursor(Qt::SizeHorCursor);

	m_progress_bar->setFormat("");
	m_progress_bar->setMaximum(m_max_value);
	m_progress_bar->setMinimum(m_min_value);

	m_line_edit->setWindowOpacity(1);
}

void UEProgressBar::UpdateUeProgressBarValue(double val)
{
	m_progress_bar->setValue(val);
	m_line_edit->setText(QString::number(val));
	m_current_value = val;

	qDebug() << "update value";
}

//void UEProgressBar::enterEvent(QEnterEvent* event)
//{
//	qDebug() << "enter event";
//	return;
//}
//
//void UEProgressBar::leaveEvent(QEvent* event)
//{
//	qDebug() << "leave event";
//}

void UEProgressBar::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		this->setMouseTracking(true);
		GetCursorPos(&m_last_mouse_pos);
	}		

	qDebug() << "mouse press";
}

void UEProgressBar::mouseReleaseEvent(QMouseEvent* event)
{
	this->setMouseTracking(false);
	setCursor(Qt::SizeHorCursor);

	SetCursorPos(m_last_mouse_pos.x,m_last_mouse_pos.y);

	qDebug() << "mouse release";
}

void UEProgressBar::mouseMoveEvent(QMouseEvent* event)
{
	setCursor(Qt::BlankCursor);

	m_is_mouse_move = true;
	
	QPoint current_mouse_position= event->pos();
	if (m_last_mouse_pos_x < current_mouse_position.x())
	{
		m_current_value += m_frequency  / 7;
	}
	else if (m_last_mouse_pos_x > current_mouse_position.x())
	{
		m_current_value -= m_frequency / 7;
	}
	m_last_mouse_pos_x = current_mouse_position.x();
	m_current_value = std::clamp(m_current_value, m_min_value, m_max_value);
	UpdateUeProgressBarValue(m_current_value);
	

	qDebug() << "mouse move";
}

void UEProgressBar::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Enter)
	{
		double current_val = m_line_edit->text().toDouble();
		UpdateUeProgressBarValue(current_val);
	}
}










