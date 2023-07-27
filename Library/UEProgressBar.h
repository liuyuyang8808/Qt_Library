#include <QWidget>
#include <QFrame>
#include <QProgressBar>
#include <QMouseEvent>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <Windows.h>

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

	void UpdateValueByLineEdit(QString val);
	void UpdateValueByProgressBar(double val);

protected:
	//void enterEvent(QEnterEvent* event) override;
	//void leaveEvent(QEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;



private:
	Ui::UEProgressBar* ui;

	bool  m_is_mouse_move = false;
	
	double m_current_value = 10.0f;
	double m_max_value = 360.0f;
	double m_min_value = 1e-9;
	double m_frequency = 8.f;

	uint16_t m_last_mouse_pos_x = 0;
	POINT    m_last_mouse_pos;

	QLineEdit*		m_line_edit = nullptr;
	QProgressBar*   m_progress_bar = nullptr;
};




