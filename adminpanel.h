#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QWidget>

namespace Ui {
class adminpanel;
}

class adminpanel : public QWidget
{
    Q_OBJECT

public:
    explicit adminpanel(QWidget *parent = nullptr);
    ~adminpanel();

private slots:

    void on_logoutBtn_clicked();

    void on_userBtn_clicked();
    void onClicked();
    void update_user();


    void on_transactionBtn_clicked();

private:
    Ui::adminpanel *ui;
};

#endif // ADMINPANEL_H
