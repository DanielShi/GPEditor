#ifndef GPPROJECTVIEWER_H
#define GPPROJECTVIEWER_H
#include "gpdockwidget.h"

class QTreeView;

class GPProjectViewer : public GPDockWidget
{
    Q_OBJECT
public:
    explicit GPProjectViewer(QWidget *parent = 0);
    
signals:
    
public slots:
    void    DoLoadProject( const QString & path );

    void    DoCloseProject();

protected:
    QTreeView * m_treeView;

};

#endif // GPPROJECTVIEWER_H
