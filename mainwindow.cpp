#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "system.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->signInBtn->close();  //废弃的button
    ui->signoutBtn->close();

    signDlg=new dlg_sign(); //初始化signDlg
    connect(signDlg,SIGNAL(success()),this,SLOT(reshow_user()));
    reshow_user();

    //显示酒店列表
    reshow_hotelInfo(System::getSystem()->get_hotelinfo_checked());//初始化hotellist

    //只是一些有趣的东西
    QMenu *m=new QMenu(QString::fromLocal8Bit("帮助"));
    QAction *a=new QAction(QString::fromLocal8Bit("关于软件"),this);
    m->addAction(a);
    ui->menuBar->addMenu(m);
    connect(ui->menuBar,SIGNAL(triggered(QAction*)),this,SLOT(tri(QAction*)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signInBtn_clicked()
{
    if(System::getSystem()->get_user()!=NULL)
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                        ,QString::fromLocal8Bit("请先注销"),QMessageBox::Ok);
    else{
        signDlg->exec();
    }
}

void MainWindow::reshow_user()
{
    if(System::getSystem()->get_user()!=NULL)
        ui->username_welcome->setText(QString::fromLocal8Bit("欢迎！").append(System::getSystem()->get_user()->name()));
    else
        ui->username_welcome->setText(QString::fromLocal8Bit("您尚未登录"));

    //以下为functionBTnBox的更新，由用户改变而改变，用了functionbtn中的组件，
    //同样的信号连接不同的槽函数，在槽函数中实现功能
    auto ft=ui->FuntionTable;
    ft->clear();
    ft->setRowCount(1);
    ft->setColumnCount(5);
    for(int i = 0; i < 5 ; i++){
        ft->setColumnWidth(i, 93);
    }
    ft->setRowHeight(0,100);
    ft->verticalHeader()->hide();
    ft->horizontalHeader()->hide();
    ft->setShowGrid(false);
    if(System::getSystem()->get_user()==NULL){ //没登录时
        FunctionBtn *btn1=new FunctionBtn(QString::fromLocal8Bit("登录"),QString::fromLocal8Bit("注册"));
        connect(btn1,SIGNAL(Btn_clicked()),this,SLOT(on_signInBtn_clicked()));
        ft->setCellWidget(0,0,btn1);
    }
    else if(System::getSystem()->get_user()->userType()=="customer"){
        FunctionBtn *btn1=new FunctionBtn(QString::fromLocal8Bit("完善"),QString::fromLocal8Bit("信息"));
        connect(btn1,SIGNAL(Btn_clicked()),this,SLOT(open_dlg_userInfo()));
        ft->setCellWidget(0,0,btn1);

        FunctionBtn *btn2=new FunctionBtn(QString::fromLocal8Bit("查看"),QString::fromLocal8Bit("订单"));
        connect(btn2,SIGNAL(Btn_clicked()),this,SLOT(open_dlg_order()));
        ft->setCellWidget(0,1,btn2);

        FunctionBtn *btn3=new FunctionBtn(QString::fromLocal8Bit("注销"),QString::fromLocal8Bit(""));
        connect(btn3,SIGNAL(Btn_clicked()),this,SLOT(on_signoutBtn_clicked()));
        ft->setCellWidget(0,2,btn3);
    }
    else if(System::getSystem()->get_user()->userType()=="manager"){
        FunctionBtn *btn1=new FunctionBtn(QString::fromLocal8Bit("完善"),QString::fromLocal8Bit("信息"));
        connect(btn1,SIGNAL(Btn_clicked()),this,SLOT(open_dlg_userInfo()));
        ft->setCellWidget(0,0,btn1);

        FunctionBtn *btn2=new FunctionBtn(QString::fromLocal8Bit("管理"),QString::fromLocal8Bit("订单"));
        connect(btn2,SIGNAL(Btn_clicked()),this,SLOT(open_dlg_order()));
        ft->setCellWidget(0,1,btn2);

        FunctionBtn *btn3=new FunctionBtn(QString::fromLocal8Bit("管理"),QString::fromLocal8Bit("酒店"));
        connect(btn3,SIGNAL(Btn_clicked()),this,SLOT(open_dlg_hotel()));
        ft->setCellWidget(0,2,btn3);

        FunctionBtn *btn4=new FunctionBtn(QString::fromLocal8Bit("注销"),QString::fromLocal8Bit(""));
        connect(btn4,SIGNAL(Btn_clicked()),this,SLOT(on_signoutBtn_clicked()));
        ft->setCellWidget(0,3,btn4);
    }
    else if(System::getSystem()->get_user()->userType()=="admin"){
        FunctionBtn *btn1=new FunctionBtn(QString::fromLocal8Bit("审核"),QString::fromLocal8Bit("酒店"));
        connect(btn1,SIGNAL(Btn_clicked()),this,SLOT(open_dlg_hotel()));
        ft->setCellWidget(0,0,btn1);

        FunctionBtn *btn2=new FunctionBtn(QString::fromLocal8Bit("添加"),QString::fromLocal8Bit("管理员"));
        connect(btn2,SIGNAL(Btn_clicked()),this,SLOT(open_dlg_newmember()));
        ft->setCellWidget(0,1,btn2);

        FunctionBtn *btn3=new FunctionBtn(QString::fromLocal8Bit("注销"),QString::fromLocal8Bit(""));
        connect(btn3,SIGNAL(Btn_clicked()),this,SLOT(on_signoutBtn_clicked()));
        ft->setCellWidget(0,2,btn3);
    }
    else{
        qDebug()<<"judge user type wrong";
    }
    qDebug()<<"reshow user";
}

void MainWindow::reshow_hotelInfo(const vector<shared_ptr<HotelInfo>>& hotels)
{
    auto lw=ui->HotelList;
    lw->clear();
    for(shared_ptr<HotelInfo> hotel:hotels){
        Wgt_hotel *w=new Wgt_hotel(this,hotel);
        auto item=new QListWidgetItem;
        item->setSizeHint(w->size());
        w->changeUi();
        lw->addItem(item);
        lw->setItemWidget(item,w);

        connect(w,SIGNAL(pBtn_room_clicked(shared_ptr<HotelInfo>&)),this,SLOT(show_room(shared_ptr<HotelInfo>&)));
    }
}

void MainWindow::show_room(shared_ptr<HotelInfo> &info)
{
    auto lw=ui->list_detail;
    lw->clear();
    for(Room *room:info->get_rooms()){
        Wgt_room *w=new Wgt_room(info,room,this);
        auto item=new QListWidgetItem;
        item->setSizeHint(w->size());
        w->changeUi();
        lw->addItem(item);
        lw->setItemWidget(item,w);
        connect(w,SIGNAL(newOrder(shared_ptr<HotelInfo>,Room *)),this,SLOT(open_dlg_payment(shared_ptr<HotelInfo>,Room *)));
    }
    ui->label_whatitis->setText(QString::fromLocal8Bit("查看房间,当前酒店为：")+info->get_name());

}

void MainWindow::open_dlg_payment(shared_ptr<HotelInfo> info, Room *r)
{
    Dlg_newOrder *d=new Dlg_newOrder(info,r);
    d->changeUi();
    d->exec();

}

void MainWindow::open_dlg_userInfo()
{
    Dlg_userInfo *d=new Dlg_userInfo(System::getSystem()->get_user());
    d->exec();
    reshow_user();

}

void MainWindow::open_dlg_order()
{
    Dlg_order *d=new Dlg_order();
    d->exec();
    reshow_hotelInfo(System::getSystem()->get_hotelinfo_checked());
    ui->list_detail->clear();
    ui->label_whatitis->clear();
}

void MainWindow::open_dlg_hotel()
{
    Dlg_hotel *d=new Dlg_hotel();
    d->exec();
    reshow_hotelInfo(System::getSystem()->get_hotelinfo_checked());
}

void MainWindow::open_dlg_newmember()
{
    Dlg_addmenber *d=new Dlg_addmenber(NULL);
    d->exec();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug()<<"close event success";
    QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                             ,QString::fromLocal8Bit("数据已存储"),QMessageBox::Ok);
    Database::write_all();   //存进数据库
    event->accept();

}

void MainWindow::tri(QAction *act)
{
    if(act->text()==QString::fromLocal8Bit("关于软件")){
        Wgt_about *w=new Wgt_about();
        w->show();
    }
}

void MainWindow::on_signoutBtn_clicked()
{
    auto s=System::getSystem();
    if(s->get_user()){
        s->set_user(NULL);
        reshow_user();
    }
    else
    {
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("您尚未登录"),QMessageBox::Ok);
    }
}

void MainWindow::on_sort_confirm_clicked()
{
    QString loca=ui->search_loca->text();
    QString key=ui->search_key->text();
    QString Mode;
    if(ui->rBtn_mark->isChecked())
        Mode="mark_down";
    else if(ui->rBtn_price_down->isChecked())
        Mode="price_down";
    else if(ui->rBtn_price_up->isChecked())
        Mode="price_up";
    else
        Mode="";
    reshow_hotelInfo(System::getSystem()->get_hotelinfo_checked(loca,key,Mode)); //排序工作由System完成
}
