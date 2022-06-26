#include "mainwindow.h"
#include <QApplication>
#include <QSettings>
#include <adminpanel.h>
#include <QDebug>
#include "clientpanel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSettings settings("c:/windows/winf32.ini", QSettings::IniFormat);
    if(settings.value("login").toBool()){
        if (settings.value("role").toString() == "admin") {
            adminpanel *admin = new adminpanel();
            admin->setFixedSize(admin->width(),admin->height());
            admin->setWindowState(Qt::WindowMaximized);
            admin->setWindowTitle(" ");
            admin->setWindowIcon(QIcon(":/images/icon"));
            admin->show();
        }else if (settings.value("role").toString() == "client") {
            clientpanel *client = new clientpanel();
            client->setFixedSize(client->width(),client->height());
            client->setWindowState(Qt::WindowMaximized);
            client->setWindowTitle(" ");
            client->setWindowIcon(QIcon(":/images/icon"));
            client->show();
        }else{

        }
        return a.exec();

    }else{
        MainWindow w;
        w.setFixedSize(w.width(),w.height());
        w.setWindowTitle(" ");
        w.setWindowIcon(QIcon(":/images/icon"));
        w.show();
        return a.exec();
    }





}
