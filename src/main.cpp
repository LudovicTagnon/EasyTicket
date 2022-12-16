#include <iostream>

#include <QApplication>

#include "model/EasyTicket.h"

/*
 * https://doc.qt.io/archives/qt-4.7/designer-using-a-ui-file.html
 * https://www.youtube.com/watch?v=dOovH6TvaY4
 * Don't forget to put the dll
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    EasyTicket easyTicket = EasyTicket();

    easyTicket.start();

    return a.exec();
}
