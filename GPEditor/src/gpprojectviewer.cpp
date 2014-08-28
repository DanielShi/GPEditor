#include <QLayout>
#include <QFileSystemModel>
#include <QFileInfo>
#include <QTreeView>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QDebug>
#include "gpprojectviewer.h"

GPProjectViewer::GPProjectViewer(QWidget *parent) :
    GPDockWidget("Project",parent)
{

}

void GPProjectViewer::LoadProject(const QString &path)
{
    QWidget * _dockContent = this->widget();

    QLayout * _layout = _dockContent->layout();

    QFileInfo  _fileInfo;

    _fileInfo.setFile(path);

    QString _dirPath = _fileInfo.absoluteDir().absolutePath();

    QFileSystemModel * _model = new QFileSystemModel();

    _model->setRootPath(_dirPath);

    QTreeView * _view = new QTreeView();

    _view->setModel(_model);

    _view->setRootIndex(_model->index(_dirPath));

    _view->setHeaderHidden(true);

    // only display the file name

    for( int i = 1 ; i < _view->header()->count() ; i++ )
    {
        _view->setColumnHidden(i,true);
    }

    _layout->addWidget(_view);

    this->repaint();

}
