#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(w.width(),w.height());
    w.setWindowTitle(" ");
    w.setWindowIcon(QIcon(":/images/icon"));
    w.show();
    return a.exec();
}
