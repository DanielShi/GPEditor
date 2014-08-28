#include <QLayout>
#include <QFileSystemModel>
#include <QFileInfo>
#include <QTreeView>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QDebug>
#include "gpprojectviewer.h"

GPProjectViewer::GPProjectViewer(QWidget *parent) :
    GPDockWidget("Project",parent),
    m_treeView(NULL)
{

}

void GPProjectViewer::DoLoadProject(const QString &path)
{
    // close current project if have
    DoCloseProject();

    QWidget * _dockContent = this->widget();

    QLayout * _layout = _dockContent->layout();

    QFileInfo  _fileInfo;

    _fileInfo.setFile(path);

    QString _dirPath = _fileInfo.absoluteDir().absolutePath();

    QFileSystemModel * _model = new QFileSystemModel();

    _model->setRootPath(_dirPath);

    m_treeView = new QTreeView();

    m_treeView->setModel(_model);

    m_treeView->setRootIndex(_model->index(_dirPath));

    m_treeView->setHeaderHidden(true);

    // only display the file name

    for( int i = 1 ; i < m_treeView->header()->count() ; i++ )
    {
        m_treeView->setColumnHidden(i,true);
    }

    _layout->addWidget(m_treeView);
}

void GPProjectViewer::DoCloseProject()
{
    if( m_treeView )
    {
        QFileSystemModel * _model = qobject_cast<QFileSystemModel*>(m_treeView->model());

        if( _model )
            delete _model;

        delete m_treeView;
        m_treeView = NULL;
    }
}
