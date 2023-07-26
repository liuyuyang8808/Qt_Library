#include <QWidget>
#include <QFrame>
#include <QProgressBar>
#include <QMouseEvent>

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

protected:
	void enterEvent(QEvent* event) override;
	void leaveEvent(QEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
private:
	Ui::UEProgressBar* ui;

	bool  m_is_mouse_move = false;
	
	float m_current_value = 0.0f;
	float m_max_value = 360.0f;
	float m_min_value = 0.0f;
	
	int m_current_mouse_pos = 0.0f;
	int m_last_mouse_pos = 0.0f;

	QProgressBar* m_progress_bar = nullptr;

};




