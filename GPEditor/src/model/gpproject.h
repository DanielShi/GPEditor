#ifndef GPPROJECT_H
#define GPPROJECT_H

#include <QObject>

class GPProject : public QObject
{
    Q_OBJECT
public:
    explicit GPProject(QObject *parent = 0);

    void NewProject(const QString & filePath);

    void OpenProject(const QString & filePath);

    void CloseProject();

    void SaveProject();
    
signals:
    
public slots:
    
};

#endif // GPPROJECT_H
