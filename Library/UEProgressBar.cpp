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

	InitLineEdit();
	InitProgressBar();
}

void UEProgressBar::InitLineEdit()
{
	QDoubleValidator* double_vaildator = new QDoubleValidator(m_line_edit);
	double_vaildator->setRange(m_min_value, m_max_value, 6);

	m_line_edit->setValidator(double_vaildator);
}

void UEProgressBar::InitProgressBar()
{
	m_progress_bar->setFormat("");
	m_progress_bar->setMaximum(m_max_value);
	m_progress_bar->setMinimum(m_min_value);
}

void UEProgressBar::UpdateValueByLineEdit(QString val)
{
	int input_i = val.toInt();
	if (input_i)
	{
		input_i = std::clamp(input_i, (int)m_min_value, (int)m_max_value);
		m_line_edit->setText(QString::number(input_i, 'f', 1));
		m_progress_bar->setValue(input_i);
		return;
	}
	else
	{
		double input_d = val.toDouble(); 
		if(input_d < m_min_value)
		{
			m_line_edit->setText(QString::number(m_min_value, 'f', 1));
			m_progress_bar->setValue(m_min_value);
			return;
		}
		else if (input_d > m_max_value)
		{
			m_line_edit->setText(QString::number(m_max_value, 'f', 1));
			m_progress_bar->setValue(m_max_value);
			return;
		}
		m_line_edit->setText(QString::number(input_d));
		m_progress_bar->setValue(input_d);
	}
}

void UEProgressBar::UpdateValueByProgressBar(double val)
{

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
	

	qDebug() << "mouse move";
}

void UEProgressBar::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
	{
		QString val = m_line_edit->text();
		UpdateValueByLineEdit(val);
	}
}










