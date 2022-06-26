#ifndef CLIENTPANEL_H
#define CLIENTPANEL_H

#include <QWidget>

namespace Ui {
class clientpanel;
}

class clientpanel : public QWidget
{
    Q_OBJECT

public:
    explicit clientpanel(QWidget *parent = nullptr);
    ~clientpanel();
    void fillTable();

private slots:
    void on_logoutBtn_clicked();
    void detail();
    void buy();
    void updatePanel();

private:
    Ui::clientpanel *ui;
};

#endif // CLIENTPANEL_H
