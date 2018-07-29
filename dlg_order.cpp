#include "dlg_order.h"
#include "ui_dlg_order.h"

Dlg_order::Dlg_order(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_order)
{
    ui->setupUi(this);

    on_pBtn_all_clicked();//for test
}

Dlg_order::~Dlg_order()
{
    delete ui;
}

void Dlg_order::on_pBtn_all_clicked()
{
    auto lw=ui->listWidget_order;
    lw->clear();
    w=new Wgt_order(NULL);
    auto item=new QListWidgetItem;
    item->setSizeHint(w->size());
    w->changeUi();
    lw->addItem(item);
    lw->setItemWidget(item,w);
    for(auto order:System::getSystem()->get_orders()){
        w=new Wgt_order(order);
        auto item=new QListWidgetItem;
        item->setSizeHint(w->size());
        w->changeUi();
        lw->addItem(item);
        lw->setItemWidget(item,w);

        //connect
    }
}
