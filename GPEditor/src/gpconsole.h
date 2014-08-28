#ifndef GPCONSOLE_H
#define GPCONSOLE_H

#include <QDockWidget>
#include <QTextEdit>
#include "gpdockwidget.h"

class GPConsole : public GPDockWidget
{
    Q_OBJECT
public:
    explicit GPConsole(QWidget *parent = 0);
    
signals:
    
public slots:
    void DoError(const QString& error);

    void DoInfo(const QString& info );

protected:
    QTextEdit * m_textEdit;
    
};

#endif // GPCONSOLE_H
