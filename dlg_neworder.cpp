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

void Dlg_newOrder::on_pBtn_cancel_clicked()
{
    this->close();
}

void Dlg_newOrder::on_pBtn_pay_later_clicked()
{
    Order *o;
    if(room.get_discount()==1){
        o=new Order(System::getSystem()->get_user()->name(),info->get_name(),room.get_type(),room.get_price());
    }
    else{
        o=new Order(System::getSystem()->get_user()->name(),info->get_name(),room.get_type(),room.get_discount());
    }

    System::getSystem()->add_order(o);

    //打开查询订单界面

}

void Dlg_newOrder::on_pBtn_pay_now_clicked()
{
    Order *o;
    if(room.get_discount()==1){
        o=new Order(System::getSystem()->get_user()->name(),info->get_name(),room.get_type(),room.get_price());
    }
    else{
        o=new Order(System::getSystem()->get_user()->name(),info->get_name(),room.get_type(),room.get_discount());
    }
    o->change_status_to_checking_payment();
    System::getSystem()->add_order(o);

    //打开查询订单界面

}
