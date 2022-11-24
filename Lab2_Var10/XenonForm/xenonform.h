#ifndef XENONFORM_H
#define XENONFORM_H

#include <QWidget>
#include <QObject>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <functional>
#include "XenonForm_global.h"

QT_BEGIN_NAMESPACE
namespace Ui { class XenonForm; }
QT_END_NAMESPACE

class XENONFORM_EXPORT XenonForm : public QWidget
{
    Q_OBJECT

public:
    XenonForm();
     ~XenonForm();
    void SetLabelString(std::string str);
    void SetButtonAction(std::function<void ()> onButtonPush);
    std::string GetLabelString();
    std::string GetLineString();
private:
    Ui::XenonForm *m_ui;
    QVBoxLayout *m_layout;
    QLabel *m_label;
    QLineEdit *m_lineEdit;
    QPushButton *m_pushButton;

};

#endif // XENONFORM_H
