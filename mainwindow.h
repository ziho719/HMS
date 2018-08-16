#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QCloseEvent>
#include "dlg_sign.h"
#include <QMessageBox>
#include <QPixmap>
#include "wgt_hotel.h"
#include "wgt_room.h"
#include "wgt_about.h"
#include "dlg_neworder.h"
#include "dlg_userinfo.h"
#include "dlg_hotel.h"
#include "dlg_order.h"
#include "dlg_addmenber.h"
#include "functionbtn.h"
#include "system.h"
#include <memory>
#include <QListWidget>
#include <vector>

//UI的核心，主窗口

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
    void on_signInBtn_clicked(); //登录按钮按下-(如果没有登录)-打开登录界面（按钮已废弃但保留槽函数）
    void on_signoutBtn_clicked();  //
    void on_sort_confirm_clicked(); //确认搜索

public slots:
    void reshow_user(); //登录、注册、注销成功时界面的更改，不改变hotelinfo部分
    void reshow_hotelInfo(const vector<shared_ptr<HotelInfo> > &hotels);  //hotel的筛选等操作由System类中实现
    void show_room(shared_ptr<HotelInfo> &info);    //点击酒店时显示房间

    void open_dlg_payment(shared_ptr<HotelInfo> info,Room *r); //打开各类窗口的槽函数，供connect使用
    void open_dlg_userInfo();
    void open_dlg_order();
    void open_dlg_hotel();
    void open_dlg_newmember();
    void closeEvent(QCloseEvent *event);  //关闭程序时调用数据库
    void tri(QAction *act);   //menubar点击时的槽，just for fun

private:
    Ui::MainWindow *ui;
    dlg_sign *signDlg;
};

#endif // MAINWINDOW_H
