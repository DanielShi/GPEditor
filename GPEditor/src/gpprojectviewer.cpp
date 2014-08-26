#include <QLayout>
#include <QFileSystemModel>
#include <QTreeView>
#include <QHeaderView>
#include <QVBoxLayout>
#include "gpprojectviewer.h"

GPProjectViewer::GPProjectViewer(QWidget *parent) :
    GPDockWidget("Project",parent)
{
    QWidget * _dockContent = this->widget();

    QLayout * _layout = _dockContent->layout();

    QFileSystemModel * _model = new QFileSystemModel();

    _model->setRootPath(QDir::currentPath());

    QTreeView * _view = new QTreeView();

    _view->setModel(_model);

    _view->setRootIndex(_model->index(QDir::currentPath()));

    _view->setHeaderHidden(true);

    // only display the file name

    for( int i = 1 ; i < _view->header()->count() ; i++ )
    {
        _view->setColumnHidden(i,true);
    }

    _layout->addWidget(_view);

}
