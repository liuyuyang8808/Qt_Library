#include <QWidget>
#include <QFrame>
#include <QProgressBar>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <Windows.h>
#include <QToolTip>

QT_BEGIN_NAMESPACE
namespace Ui { class UEProgressBar; }
QT_END_NAMESPACE


class UEProgressBar : public QWidget
{
	Q_OBJECT
public:
	UEProgressBar(QWidget* parent = nullptr);
	~UEProgressBar();

	void InitAll();
	void InitLineEdit();
	void InitProgressBar ();
	void RefreshMousePos();
	void ShowTipsText();

	QString		CheckValue(QString val);
	void		UpdateValue(QString val);
	void        SelectAllText();

protected:
	void enterEvent(QEnterEvent* event) override;
	void leaveEvent(QEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;


private:
	Ui::UEProgressBar* ui;

	bool  m_is_mouse_move = false;
	bool  m_is_mouse_enter = false;
	
	double m_current_value = 10.0f;
	double m_max_value = 360.0f;
	double m_min_value = 1e-9;
	double m_frequency = 100.f;
	double m_frequency_wheel = 2.f;

	int      m_start_mouse_pos_x = 0;
	POINT    m_start_mouse_pos;

	QString  m_tips_text = "this is a tips";

	QLineEdit*		m_line_edit = nullptr;
	QProgressBar*   m_progress_bar = nullptr;
};




