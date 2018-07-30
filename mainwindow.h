#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dlg_sign.h"
#include <QMessageBox>
#include <QPixmap>
#include "wgt_hotel.h"
#include "wgt_room.h"
#include "dlg_neworder.h"
#include "dlg_userinfo.h"
#include "dlg_hotel.h"
#include "dlg_order.h"
#include "functionbtn.h"
#include "system.h"
#include <memory>
#include <QListWidget>
#include <vector>


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
    void on_signoutBtn_clicked();

public slots:
    void reshow_user(); //登录、注册、注销成功时界面的更改，不改变hotelinfo部分
    void reshow_hotelInfo(const vector<shared_ptr<HotelInfo> > &hotels);  //hotel的筛选等操作由类中实现
    void show_room(shared_ptr<HotelInfo> &info);
    //void add_new_order();
    void open_dlg_payment(shared_ptr<HotelInfo> info,Room r);
    void open_dlg_userInfo();
    void open_dlg_order();
    void open_dlg_hotel();
signals:


private:
    Ui::MainWindow *ui;
    dlg_sign *signDlg;
};

#endif // MAINWINDOW_H
