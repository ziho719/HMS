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
                //todo:付款界面
                ui->status->setText(QString::fromLocal8Bit("待付款"));
            }
            else if(order->get_status()=="checking_payment"){
                ui->pBtn->setText(QString::fromLocal8Bit("取消订单"));
                ui->status->setText(QString::fromLocal8Bit("待确认"));
            }
            else if(order->get_status()=="pending_checkin"){
                ui->pBtn->setText(QString::fromLocal8Bit("退款"));
                ui->status->setText(QString::fromLocal8Bit("待入住"));
            }
            else if(order->get_status()=="pending_comment"){
                ui->pBtn->setText(QString::fromLocal8Bit("评论"));
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
                ui->status->setText(QString::fromLocal8Bit("待付款"));
            }
            else if(order->get_status()=="checking_payment"){
                ui->pBtn->setText(QString::fromLocal8Bit("未收到，取消订单"));
                ui->status->setText(QString::fromLocal8Bit("待确认"));
            }
            else if(order->get_status()=="pending_checkin"){
                ui->pBtn->setText(QString::fromLocal8Bit("已入住"));
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
                ui->status->setText(QString::fromLocal8Bit("订单已完成，感谢使用"));
            }
        }
    }
}


void Wgt_order::on_pBtn_clicked()
{
    emit pBtn_clicked();
}
