#ifndef GPEDITOR_H
#define GPEDITOR_H

#include <QMainWindow>

namespace Ui {
class GPEditor;
}

class GPProject;

class GPEditor : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GPEditor(QWidget *parent = 0);
    ~GPEditor();

public slots:
    void DoNewProject();

    void DoOpenProject();

    void DoCloseProject();

    void DoSaveProject();

signals:
    void OnProjectOpen( const QString& path );

    void OnProjectClose();

protected:
    bool InitOnLaunch();

    void RegisterWindow(QWidget* window);
    
private:
    Ui::GPEditor *ui;
    GPProject* m_project;
};

#endif // GPEDITOR_H
