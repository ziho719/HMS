#include "wgt_order.h"
#include "ui_wgt_order.h"

Wgt_order::Wgt_order(Order *o, QWidget *parent) :
    QWidget(parent),order(o),
    ui(new Ui::Wgt_order)
{
    ui->setupUi(this);
}

Wgt_order::~Wgt_order()
{
    delete ui;
}

void Wgt_order::changeUi()
{
    if(order==NULL){
        ui->pBtn->close();
        if(System::getSystem()->get_user()->userType()=="customer"){
            ui->username->hide();
        }
    }
    else{
        ui->name->setText(order->get_hotel());
        ui->price->setText(QString::fromLocal8Bit("￥")+QString::number(order->get_money(),'f',0));
        ui->room->setText(order->get_roomType());
        if(System::getSystem()->get_user()->userType()=="customer"){
            ui->username->hide();
        }
        else{
            ui->username->setText(order->get_user());
        }
        //分用户类型、订单状态显示订单状态和对应操作
        if(System::getSystem()->get_user()->userType()=="customer"){
            if(order->get_status()=="pending_pay"){
                ui->pBtn->setText(QString::fromLocal8Bit("付款"));
                connect(this,SIGNAL(pBtn_clicked()),SLOT(pay()));
                ui->status->setText(QString::fromLocal8Bit("待付款"));
            }
            else if(order->get_status()=="checking_payment"){
                ui->pBtn->setText(QString::fromLocal8Bit("取消订单"));
                connect(this,SIGNAL(pBtn_clicked()),SLOT(cancel()));
                ui->status->setText(QString::fromLocal8Bit("待确认"));
            }
            else if(order->get_status()=="pending_checkin"){
                ui->pBtn->setText(QString::fromLocal8Bit("退款"));
                connect(this,SIGNAL(pBtn_clicked()),SLOT(refund()));
                ui->status->setText(QString::fromLocal8Bit("待入住"));
            }
            else if(order->get_status()=="pending_comment"){
                ui->pBtn->setText(QString::fromLocal8Bit("评论"));
                connect(this,SIGNAL(pBtn_clicked()),SLOT(open_dlg_newComment()));
                ui->status->setText(QString::fromLocal8Bit("待评论"));
            }
            else if(order->get_status()=="have_refund"){
                ui->pBtn->hide();
                ui->status->setText(QString::fromLocal8Bit("已退款"));
            }
            else if(order->get_status()=="have_cancel"){
                ui->pBtn->hide();
                ui->status->setText(QString::fromLocal8Bit("已取消"));
            }
            else if(order->get_status()=="done"){
                ui->pBtn->hide();
                ui->status->setText(QString::fromLocal8Bit("订单已完成，感谢使用"));
            }

        }
        else{
            if(order->get_status()=="pending_pay"){
                ui->pBtn->setText(QString::fromLocal8Bit("超时，取消该订单"));
                connect(this,SIGNAL(pBtn_clicked()),SLOT(cancel()));
                ui->status->setText(QString::fromLocal8Bit("待付款"));
            }
            else if(order->get_status()=="checking_payment"){
                ui->pBtn->setText(QString::fromLocal8Bit("已收到付款"));
                connect(this,SIGNAL(pBtn_clicked()),SLOT(check_pay()));
                ui->status->setText(QString::fromLocal8Bit("待确认"));
            }
            else if(order->get_status()=="pending_checkin"){
                ui->pBtn->setText(QString::fromLocal8Bit("已入住"));
                connect(this,SIGNAL(pBtn_clicked()),SLOT(checkin()));
                ui->status->setText(QString::fromLocal8Bit("待入住"));
            }
            else if(order->get_status()=="pending_comment"){
                ui->pBtn->hide();
                ui->status->setText(QString::fromLocal8Bit("待评论"));
            }
            else if(order->get_status()=="have_refund"){
                ui->pBtn->hide();
                ui->status->setText(QString::fromLocal8Bit("已退款"));
            }
            else if(order->get_status()=="have_cancel"){
                ui->pBtn->hide();
                ui->status->setText(QString::fromLocal8Bit("已取消"));
            }
            else if(order->get_status()=="done"){
                ui->pBtn->hide();
                ui->status->setText(QString::fromLocal8Bit("订单已完成"));
            }
        }
    }
}


void Wgt_order::on_pBtn_clicked()
{
    emit pBtn_clicked();
}

void Wgt_order::pay()
{
    QMessageBox::information(NULL,QString::fromLocal8Bit("支付完成")
                                    ,QString::fromLocal8Bit("不要钱，随便住"),QMessageBox::Ok);
    order->change_status_to_checking_payment();
    emit success();
}

void Wgt_order::open_dlg_newComment()
{
    Dlg_newComment *d=new Dlg_newComment(order->get_hotel());
    connect(d,SIGNAL(success()),this,SLOT(newComment_added()));
    d->exec();
}

void Wgt_order::newComment_added()
{
    order->change_status_to_done();
    emit success();
}

void Wgt_order::refund()
{
    QMessageBox::information(NULL,QString::fromLocal8Bit("退款完成")
                                    ,QString::fromLocal8Bit("不会把所有钱都退回给你的"),QMessageBox::Ok);
    order->change_status_to_have_refund();
    System::getSystem()->find_hotel(order->get_hotel())->get_hotel_info()->add_roomSum(order->get_roomType());
    emit success();
}

void Wgt_order::cancel()
{
    QMessageBox::information(NULL,QString::fromLocal8Bit("已取消")
                                    ,QString::fromLocal8Bit("已取消"),QMessageBox::Ok);
    order->change_status_to_have_cancel();
    System::getSystem()->find_hotel(order->get_hotel())->get_hotel_info()->add_roomSum(order->get_roomType());
    emit success();
}

void Wgt_order::checkin()
{
    QMessageBox::information(NULL,QString::fromLocal8Bit("HMS")
                                    ,QString::fromLocal8Bit("又送走一个"),QMessageBox::Ok);
    order->change_status_to_pending_comment();
    System::getSystem()->find_hotel(order->get_hotel())->get_hotel_info()->add_roomSum(order->get_roomType());
    emit success();
}

void Wgt_order::check_pay()
{
    order->change_status_to_pending_checkin();
    emit success();
}
