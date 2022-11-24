#include "xenonform.h"
#include <QMessageBox>

XenonForm::XenonForm()
{
    m_label = new QLabel("Label");
    m_lineEdit = new QLineEdit();
    m_pushButton = new QPushButton("Далее");

    QMessageBox *messageBox = new QMessageBox();
    messageBox->setText("Form is filled");
    QObject::connect(m_pushButton, &QPushButton::clicked, [=]() {
        if(m_lineEdit->text().toStdString().length() > 0 && m_label->text().toStdString().length() > 0)
            messageBox->show();
    });

    m_layout = new QVBoxLayout(this);
    setLayout(m_layout);
    m_layout->addWidget(m_label);
    m_layout->addWidget(m_lineEdit);
    m_layout->addWidget(m_pushButton);
}

void XenonForm::SetButtonAction(std::function<void ()> onButtonPush)
{
    QObject::connect(m_pushButton, &QPushButton::clicked, onButtonPush);
}

std::string XenonForm::GetLineString() { return m_lineEdit->text().toStdString(); }
std::string XenonForm::GetLabelString() { return m_label->text().toStdString(); }
void XenonForm::SetLabelString(std::string str) { m_label->setText(str.c_str()); }

XenonForm::~XenonForm()
{
    delete m_ui;
}
