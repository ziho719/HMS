#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dlg_sign.h"
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_signInBtn_clicked(); //登录按钮按下-(如果没有登录)-打开登录界面

public slots:
    void reshow_user(); //登录、注册、注销成功时界面的更改，不改变hotelinfo部分


private:
    Ui::MainWindow *ui;
    dlg_sign *signDlg;
};

#endif // MAINWINDOW_H
