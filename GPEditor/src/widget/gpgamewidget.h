#ifndef GPGAMEWIDGET_H
#define GPGAMEWIDGET_H

#include <QGLWidget>

class GPGameWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GPGameWidget(QWidget *parent = 0);
    
signals:
    
public slots:

protected:
    virtual void initializeGL();

    virtual void resizeGL(int w, int h);

    virtual void paintGL();

};

#endif // GPGAMEWIDGET_H
