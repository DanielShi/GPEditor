#include <QDebug>
#include "gplogmanager.h"

//GPLogManager* GPLogManager::sInstance = NULL;

GPLogManager::GPLogManager(QObject*parent) :
    QObject(parent)
{
}

void GPLogManager::Error(const QString &error)
{
    emit OnError(error);
}

void GPLogManager::Info(const QString &info)
{
    emit OnInfo(info);
}
