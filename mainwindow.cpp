#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "system.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化signDlg
    signDlg=new dlg_sign();
    connect(signDlg,SIGNAL(success()),this,SLOT(reshow_user()));
    //初始化hotellist
    reshow_hotelInfo(System::getSystem()->get_hotelinfo_checked());

   //ui->label_2->setPixmap(QPixmap(QString::fromLocal8Bit(":/pics/pic/1-豪华.jpg")));
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
    //TODO:function更新
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

void MainWindow::add_new_order()
{

}

void MainWindow::open_dlg_payment(shared_ptr<HotelInfo> info, Room r)
{
    Dlg_newOrder *d=new Dlg_newOrder(info,r);
    d->changeUi();
    d->exec();
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
