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
	double_vaildator->setRange(m_min_value, m_max_value, 1);

	m_line_edit->setValidator(double_vaildator);
	m_line_edit->setText(QString::number(m_current_value, 'f', 1));
}

void UEProgressBar::InitProgressBar()
{
	m_progress_bar->setFormat("");
	m_progress_bar->setMaximum(m_max_value);
	m_progress_bar->setMinimum(m_min_value);
	m_progress_bar->setValue(m_current_value);
}



QString UEProgressBar::CheckValue(QString val)
{
	int input_i = val.toInt();
	double input_d = val.toDouble();

	if (input_i)
	{
		input_i = std::clamp(input_i, (int)m_min_value, (int)m_max_value);
		return QString::number(input_i, 'f', 1);
	}
	else
	{
		if(input_d < m_min_value)
		{
			return QString::number(m_min_value, 'f', 1);
		}
		else if (input_d > m_max_value)
		{
			return QString::number(m_max_value, 'f', 1);
		}
	}
	return QString::number(input_d);
}



void UEProgressBar::UpdateValue(QString val)
{
	QString check_val = CheckValue(val);

	m_line_edit->setText(check_val);
	m_progress_bar->setValue(check_val.toDouble());
	m_current_value = check_val.toDouble();
}

void UEProgressBar::RefreshMousePos()
{
	SetCursorPos(m_start_mouse_pos.x, m_start_mouse_pos.y);
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
		GetCursorPos(&m_start_mouse_pos);
		m_start_mouse_pos_x = event->pos().x();
	}		

	qDebug() << "mouse press";
}

void UEProgressBar::mouseReleaseEvent(QMouseEvent* event)
{
	setCursor(Qt::SizeHorCursor);

	m_is_mouse_move = false;
	this->setMouseTracking(false);


	SetCursorPos(m_start_mouse_pos.x, m_start_mouse_pos.y);

	qDebug() << "mouse release";
}

void UEProgressBar::mouseMoveEvent(QMouseEvent* event)
{
	setCursor(Qt::BlankCursor);
	m_is_mouse_move = true;

	int current_x = event->pos().x();
	int delta_val = current_x - m_start_mouse_pos_x;
	m_current_value = delta_val / m_frequency + m_current_value;
	UpdateValue(QString::number(m_current_value));
	RefreshMousePos();

	qDebug() << "mouse move";
}

void UEProgressBar::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
	{
		QString input_val = m_line_edit->text();
		UpdateValue(input_val);
	}
}










