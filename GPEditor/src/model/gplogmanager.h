#ifndef GPLOGMANAGER_H
#define GPLOGMANAGER_H
#include <QObject>
#include <QString>
#include "gpsingleton.h"

class GPLogManager : public QObject, public GPSingleton<GPLogManager>
{
    Q_OBJECT
public:
    explicit GPLogManager(QObject * parent=NULL);

    void Error(const QString& error );

    void Info(const QString& info );

signals:
    void OnError( const QString& );

    void OnInfo( const QString& );

protected:
};

#endif // GPLOGMANAGER_H
