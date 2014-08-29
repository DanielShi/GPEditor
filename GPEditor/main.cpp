#include <QtGui/QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QTimer>
#include "gpeditor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap _splashImg(":/splash/logo_powered_black.png");

    QSplashScreen _splashScreen(_splashImg);

    _splashScreen.show();

    a.processEvents();

    GPEditor w;

    QTimer::singleShot(3000,&w,SLOT(showMaximized()));

    _splashScreen.finish(&w);
    
    return a.exec();
}
