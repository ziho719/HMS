#include "dlg_neworder.h"
#include "ui_dlg_neworder.h"

Dlg_newOrder::Dlg_newOrder(shared_ptr<HotelInfo> info, Room r, QWidget *parent) :
    QDialog(parent),info(info),room(r),
    ui(new Ui::Dlg_newOrder)
{
    ui->setupUi(this);
}

Dlg_newOrder::~Dlg_newOrder()
{
    delete ui;
}

void Dlg_newOrder::changeUi()
{
    ui->hotelname->setText(info->get_name());
    if(room.get_discount()!=1) {
        ui->roomname_2->setText(QString::fromLocal8Bit("￥")+QString::number(room.get_discount(),'f',0));
    }
    else ui->roomname_2->setText(QString::fromLocal8Bit("￥")+QString::number(room.get_price(),'f',0));
    ui->roomname->setText(room.get_type());
}
