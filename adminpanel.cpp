#include "adminpanel.h"
#include "ui_adminpanel.h"
#include "user.h"
#include "mainwindow.h"
#include <QSettings>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QColor>
#include <QPushButton>
#include <QBoxLayout>
#include "edituser.h"

adminpanel::adminpanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminpanel)
{
    ui->setupUi(this);
    QSettings settings("c:/windows/winf32.ini", QSettings::IniFormat);
    ui->adminLabel->setText(settings.value("name").toString() + " عزیز ! خوش آمدید");
    ui->userTable->hide();
}

adminpanel::~adminpanel()
{
    delete ui;
}


void adminpanel::on_logoutBtn_clicked()
{
    user::logout();
    this->close();
    MainWindow *m = new MainWindow();
    m->setWindowTitle(" ");
    m->setWindowIcon(QIcon(":/images/icon"));
    m->show();
}

void adminpanel::on_userBtn_clicked()
{
    ui->userBtn->setStyleSheet("background-color:white;");
    ui->transactionBtn->setStyleSheet("background-color:green;");
    ui->productBtn->setStyleSheet("background-color:green;");
    ui->userTable->show();

    QJsonArray users = user::getAllUser();
    ui->userTable->setRowCount(users.size());
    ui->userTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    for (int i = 0; i < users.size(); i++) {
        QTableWidgetItem *item1 = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();
        QTableWidgetItem *item3 = new QTableWidgetItem();
        QTableWidgetItem *item4 = new QTableWidgetItem();
        QTableWidgetItem *item5 = new QTableWidgetItem();
        QTableWidgetItem *item6 = new QTableWidgetItem();
        QTableWidgetItem *item7 = new QTableWidgetItem();

        ui->userTable->setItem(i,0,item1);
        item1->setText(users.at(i)["name"].toString());
        item1->setTextAlignment(Qt::AlignCenter);
        ui->userTable->setItem(i,1,item2);
        item2->setText(users.at(i)["phone"].toString());
        item2->setTextAlignment(Qt::AlignCenter);
        ui->userTable->setItem(i,2,item3);
        item3->setText(users.at(i)["username"].toString());
        item3->setTextAlignment(Qt::AlignCenter);
        ui->userTable->setItem(i,3,item4);
        item4->setText(users.at(i)["address"].toString());
        item4->setTextAlignment(Qt::AlignCenter);

        ui->userTable->setItem(i,4,item6);
        if(users.at(i)["role"].toString() == "client"){
            item6->setText("مشتری");
        }else if (users.at(i)["role"].toString() == "customer") {
            item6->setText("فروشنده");
        }else {
            item6->setText("ادمین");
        }
        item6->setTextAlignment(Qt::AlignCenter);

        ui->userTable->setItem(i,5,item5);
        if (users.at(i)["status"].toBool()) {
            item5->setTextColor(QColor("green"));
            item5->setText("فعال");
        }else{
            item5->setTextColor(QColor("red"));
            item5->setText("غیر فعال");
        }
        item5->setTextAlignment(Qt::AlignCenter);

        QWidget* pWidget = new QWidget();
        QPushButton *btn = new QPushButton();
        btn->setText("ویرایش");
        btn->setToolTip(users.at(i)["username"].toString());
        btn->setStyleSheet("background-color:yellow;");
        btn->setFont(QFont("Yekan Bakh"));
        btn->setCursor(Qt::PointingHandCursor);
        QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
        pLayout->addWidget(btn);
        pLayout->setAlignment(Qt::AlignCenter);
        pLayout->setContentsMargins(0, 0, 0, 0);
        pWidget->setLayout(pLayout);
        ui->userTable->setCellWidget(i, 6, pWidget);
        connect(btn, &QPushButton::clicked, this, &adminpanel::onClicked);
    }
}
void adminpanel::onClicked(){
    QPushButton *b = qobject_cast<QPushButton *>(sender());

    QSettings settings("c:/windows/winf32.ini", QSettings::IniFormat);

    settings.setValue("edit_user",b->toolTip());

    edituser *edit = new edituser();
    edit->setWindowTitle(" ");
    edit->setWindowIcon(QIcon(":/images/icon"));
    edit->setFixedSize(edit->width(),edit->height());
    connect(edit,SIGNAL(update_user()),this,SLOT(update_user()));
    edit->show();
}

void adminpanel::update_user()
{
    ui->userBtn->click();
}
