#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QTimer>
#include "user.h"
#include "rememberme.h"
#include "signup.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->notification->hide();
    QSettings settings("c:/windows/winf32.ini", QSettings::IniFormat);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginBtn_clicked()
{
    QString username = ui->usernameInput->text().trimmed();
    QString password = ui->passwordInput->text().trimmed();
    bool returnValue = user::loginUser(username,password);
    ui->notification->show();
    if (returnValue) {
        if(user::isActive(username)){
            QSettings settings("c:/windows/winf32.ini", QSettings::IniFormat);
            settings.setValue("login",true);
            settings.setValue("username", username);
            settings.setValue("role",user::getRole(username));
        }else{
            ui->notification->show();
            ui->notification->setStyleSheet("color:red;");
            ui->notification->setText("این کاربر غیر فعال می باشد");
        }


    }else{
        ui->notification->show();
        ui->notification->setStyleSheet("color:red;");
        ui->notification->setText("نام کاربری یا رمز عبور اشتباه است");
    }
    QTimer::singleShot(5000, this, [this] () { ui->notification->hide();});



}

void MainWindow::on_rememberMe_clicked()
{
    rememberMe *r = new rememberMe(this);
    r->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    connect(r,SIGNAL(remember_me(QString,QString)),this,SLOT(remember_me(QString,QString)));
    r->show();
}

void MainWindow::remember_me(QString username , QString password)
{
    ui->usernameInput->setText(username);
    ui->passwordInput->setText(password);
}

void MainWindow::on_signupBtn_clicked()
{
    signup *s = new signup(this);
    s->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    s->show();
}
