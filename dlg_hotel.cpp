#include "dlg_hotel.h"
#include "ui_dlg_hotel.h"

Dlg_hotel::Dlg_hotel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_hotel)
{
    ui->setupUi(this);
    if(System::getSystem()->get_user()->userType()=="admin"){
        ui->label->setText(QString::fromLocal8Bit("待审核的酒店："));
        ui->pBtn_newHotel->hide();
    }
    show_list();
}

Dlg_hotel::~Dlg_hotel()
{
    delete ui;
}

void Dlg_hotel::show_list()
{
    auto lw=ui->listWidget;
    lw->clear();
    for(auto hotel:System::getSystem()->select_hotel()){
        Wgt_hotel_manager *w=new Wgt_hotel_manager(hotel,this);
        auto item=new QListWidgetItem;
        item->setSizeHint(w->size());
        w->changeUi();
        lw->addItem(item);
        lw->setItemWidget(item,w);
        connect(w,SIGNAL(success()),this,SLOT(show_list()));
    }
}

void Dlg_hotel::on_pBtn_newHotel_clicked()
{
    auto s=System::getSystem();
    Location l1(QString::fromLocal8Bit(""),QString::fromLocal8Bit(""),QString::fromLocal8Bit(""));
    Hotel* h1 =new Hotel(HotelInfo::newHotelInfo(QString::fromLocal8Bit(""),l1,""
                                                 ,QString::fromLocal8Bit(":/pics/pic/演示.jpg")) ,vector<QString>{s->get_user()->name()});
    h1->change_status_to_unchecked();
    s->add_hotel(h1);
    show_list();

}
