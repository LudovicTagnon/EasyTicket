#include "mainwindow.h"

#include <QApplication>

/*
 * https://doc.qt.io/archives/qt-4.7/designer-using-a-ui-file.html
 * https://www.youtube.com/watch?v=dOovH6TvaY4
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
