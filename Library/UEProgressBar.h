#include <QWidget>
#include <QFrame>
#include <QProgressBar>

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

private:
	Ui::UEProgressBar* ui;
};




