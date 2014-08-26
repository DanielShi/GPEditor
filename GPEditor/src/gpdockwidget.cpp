#include <QVBoxLayout>
#include "gpdockwidget.h"

GPDockWidget::GPDockWidget(QWidget *parent) :
    QDockWidget(parent)
{
    Init();
}


GPDockWidget::GPDockWidget(const QString &name,QWidget *parent) :
    QDockWidget(name,parent)
{
    Init();
}


void GPDockWidget::Init()
{
    QWidget * _dockContent = this->widget();

    if( !_dockContent )
    {
        _dockContent = new QWidget(this);
        _dockContent->setLayout( new QVBoxLayout() );
        this->setWidget(_dockContent);
    }
}
