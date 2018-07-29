#ifndef DLG_USERINFO_H
#define DLG_USERINFO_H

#include <QDialog>
#include "system.h"
#include <QMessageBox>

namespace Ui {
class Dlg_userInfo;
}

class Dlg_userInfo : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_userInfo(User *u,QWidget *parent = 0);
    ~Dlg_userInfo();

private slots:
    void on_cancel_clicked_clicked();

    void on_yes_clicked();

    void on_edit_pwd_clicked();

private:
    Ui::Dlg_userInfo *ui;
    User *user;
};

#endif // DLG_USERINFO_H
