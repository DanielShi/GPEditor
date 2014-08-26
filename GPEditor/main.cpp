#include <QtGui/QApplication>
#include "gpeditor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GPEditor w;
    w.showMaximized();
    
    return a.exec();
}
