#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString src = "Hello";
    QString b64String = base64_encode(src);
    qDebug() << "Encoded string is " << b64String;
    return a.exec();
}
