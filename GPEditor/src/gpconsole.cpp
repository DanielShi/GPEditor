#include <QLayout>
#include "gpconsole.h"

GPConsole::GPConsole(QWidget *parent) :
    GPDockWidget("Console",parent),
    m_textEdit(NULL)
{
    m_textEdit = new QTextEdit(this);

    m_textEdit->setReadOnly(true);

    QLayout * layout = this->widget()->layout();

    layout->addWidget(m_textEdit);
}

void GPConsole::DoError(const QString &error)
{
    m_textEdit->append(error);
}

void GPConsole::DoInfo(const QString &info)
{
    m_textEdit->append(info);
}
