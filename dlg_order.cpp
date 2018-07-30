#include "dlg_order.h"
#include "ui_dlg_order.h"

Dlg_order::Dlg_order(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_order)
{
    ui->setupUi(this);
    on_pBtn_need_clicked();
}

Dlg_order::~Dlg_order()
{
    delete ui;
}

void Dlg_order::on_pBtn_all_clicked()
{
    ui->label_status->setText(QString::fromLocal8Bit("所有订单："));
    auto lw=ui->listWidget_order;
    lw->clear();
    w=new Wgt_order(NULL);
    auto item=new QListWidgetItem;
    item->setSizeHint(w->size());
    w->changeUi();
    lw->addItem(item);
    lw->setItemWidget(item,w);
    for(auto order:System::getSystem()->select_order()){  //here
        w=new Wgt_order(order);
        connect(w,SIGNAL(success()),this,SLOT(on_pBtn_all_clicked()));
        auto item=new QListWidgetItem;
        item->setSizeHint(w->size());
        w->changeUi();
        lw->addItem(item);
        lw->setItemWidget(item,w);
    }
}

void Dlg_order::on_pBtn_need_clicked()
{
    ui->label_status->setText(QString::fromLocal8Bit("待处理订单："));
    auto lw=ui->listWidget_order;
    lw->clear();
    w=new Wgt_order(NULL);
    auto item=new QListWidgetItem;
    item->setSizeHint(w->size());
    w->changeUi();
    lw->addItem(item);
    lw->setItemWidget(item,w);
    for(auto order:System::getSystem()->select_order()){  //here
        if(System::getSystem()->get_user()->userType()=="customer"){
            if(order->get_status()=="pending_pay" ||
               order->get_status()=="checking_payment" ||
               order->get_status()=="pending_checkin" ||
               order->get_status()=="pending_comment")
            {
                w=new Wgt_order(order);
                connect(w,SIGNAL(success()),this,SLOT(on_pBtn_need_clicked()));
                auto item=new QListWidgetItem;
                item->setSizeHint(w->size());
                w->changeUi();
                lw->addItem(item);
                lw->setItemWidget(item,w);
            }

        }
        else if(System::getSystem()->get_user()->userType()=="manager"){
            if(order->get_status()=="pending_pay" ||
               order->get_status()=="checking_payment" ||
               order->get_status()=="pending_checkin")
            {
                w=new Wgt_order(order);
                connect(w,SIGNAL(success()),this,SLOT(on_pBtn_all_clicked()));
                auto item=new QListWidgetItem;
                item->setSizeHint(w->size());
                w->changeUi();
                lw->addItem(item);
                lw->setItemWidget(item,w);
            }

        }

    }
}
