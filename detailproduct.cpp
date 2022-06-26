#include "detailproduct.h"
#include "ui_detailproduct.h"
#include <QSettings>
#include "product.h"
#include <QDebug>
#include <QJsonObject>

detailProduct::detailProduct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::detailProduct)
{
    ui->setupUi(this);
    QSettings settings("c:/windows/winf32.ini", QSettings::IniFormat);
    QJsonObject op = product::getDetail(settings.value("detail_product").toString());
    for (int i = 0; i < op.keys().size(); i++) {
        ui->detailInput->append(op.keys().at(i) + " : " + op.value(op.keys().at(i)).toString());
    }
}

detailProduct::~detailProduct()
{
    QSettings settings("c:/windows/winf32.ini", QSettings::IniFormat);
    settings.setValue("detial_product","");
    delete ui;
}
