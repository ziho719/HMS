#ifndef DLG_SIGN_H
#define DLG_SIGN_H

#include <QDialog>
#include <QMessageBox>
#include<QDebug>
#include<QMessageBox>
#include "system.h"

namespace Ui {
class dlg_sign;
}

class dlg_sign : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_sign(QWidget *parent = 0);
    ~dlg_sign();
signals:
    void success(); //登录成功
private slots:

    void on_pushBtn_signin_clicked();

    void on_pushBtn_signup_clicked();

private:
    Ui::dlg_sign *ui;
};

#endif // DLG_SIGN_H
