#include "wgt_room.h"
#include "ui_wgt_room.h"

Wgt_room::Wgt_room(shared_ptr<HotelInfo> info, Room r, QWidget *parent) :
    QWidget(parent),room(r),info(info),
    ui(new Ui::Wgt_room)
{
    ui->setupUi(this);
}

Wgt_room::~Wgt_room()
{
    delete ui;
}

void Wgt_room::changeUi()
{
    ui->name->setText(room.get_type());
    pic.load(room.get_url());
    ui->pic->setPixmap(pic);
    ui->price->setText(QString::fromLocal8Bit("￥")+QString::number(room.get_price(),'f',0));
    ui->type->setText(room.get_description());
    if(room.get_discount()!=1) {
        ui->ori_price->setText(QString::fromLocal8Bit("￥")+QString::number(room.get_price(),'f',0));
        ui->price->setText(QString::fromLocal8Bit("￥")+QString::number(room.get_discount(),'f',0));
        ui->price->setStyleSheet("color:red");
    }
    if(room.get_sum()>=10){
        ui->sum->setText(QString::fromLocal8Bit("房间充足，剩余")+QString::number(room.get_sum(),10)+QString::fromLocal8Bit("间"));
    }
    else if(room.get_sum()>0){
        ui->sum->setText(QString::fromLocal8Bit("房间不足，剩余")+QString::number(room.get_sum(),10)+QString::fromLocal8Bit("间"));
        ui->sum->setStyleSheet("color:red");
    }
    else {
        ui->sum->setText(QString::fromLocal8Bit("房间已无"));
        ui->pBtn_newOrder->close();
    }

}

void Wgt_room::on_pBtn_newOrder_clicked()
{
    if(System::getSystem()->get_user()==NULL)
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("需要先登录才能预定房间！"),QMessageBox::Ok);
    else{
        //直接建立订单信息不够，考虑发出信号
        emit newOrder(info,room);
        changeUi();
    }
}
