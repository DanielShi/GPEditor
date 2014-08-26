#include <QFile>
#include <QMessageBox>
#include "gpproject.h"

GPProject::GPProject(QObject *parent) :
    QObject(parent)
{
}

void GPProject::NewProject(const QString &filePath)
{
    QFile file(filePath);

    if( file.open(QIODevice::WriteOnly|QIODevice::Text) )
    {
        // TODO: put down some config here

        file.close();
    }
    else
    {
        QMessageBox::information(qobject_cast<QWidget*>(this->parent()),tr("Info"),
                                         tr("Failed to create new project!"));
    }
}

void GPProject::OpenProject(const QString &filePath)
{
}

void GPProject::CloseProject()
{
}

void GPProject::SaveProject()
{
}
