#ifndef GPDOCKWIDGET_H
#define GPDOCKWIDGET_H

#include <QDockWidget>

class GPDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit GPDockWidget(QWidget *parent = 0);
    explicit GPDockWidget(const QString &name,QWidget *parent = 0);

signals:
    
public slots:

protected:
    void Init();
    
};

#endif // GPDOCKWIDGET_H
