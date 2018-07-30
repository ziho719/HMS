#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "system.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->signInBtn->close();
    ui->signoutBtn->close();
    //初始化signDlg
    signDlg=new dlg_sign();
    connect(signDlg,SIGNAL(success()),this,SLOT(reshow_user()));
    reshow_user();
    //初始化hotellist

    reshow_hotelInfo(System::getSystem()->get_hotelinfo_checked());


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

    //以下为functionBTnBox的更新

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
        //connect
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
        //TODO:connect
    }
}

void MainWindow::show_room(shared_ptr<HotelInfo> &info)
{
    auto lw=ui->list_detail;
    lw->clear();
    for(Room room:info->get_rooms()){
        Wgt_room *w=new Wgt_room(info,room,this);
        auto item=new QListWidgetItem;
        item->setSizeHint(w->size());
        w->changeUi();
        lw->addItem(item);
        lw->setItemWidget(item,w);
        connect(w,SIGNAL(newOrder(shared_ptr<HotelInfo>,Room)),this,SLOT(open_dlg_payment(shared_ptr<HotelInfo>,Room)));
    }
    ui->label_whatitis->setText(QString::fromLocal8Bit("查看房间,当前酒店为：")+info->get_name());

}

void MainWindow::open_dlg_payment(shared_ptr<HotelInfo> info, Room r)
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
}

void MainWindow::open_dlg_hotel()
{
    Dlg_hotel *d=new Dlg_hotel();
    d->exec();
    reshow_hotelInfo(System::getSystem()->get_hotelinfo_checked());
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
