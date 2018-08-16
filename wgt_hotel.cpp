#include "wgt_hotel.h"
#include "ui_wgt_hotel.h"

Wgt_hotel::Wgt_hotel(QWidget *parent, shared_ptr<HotelInfo> i) :
    QWidget(parent),info(i),
    ui(new Ui::Wgt_hotel)
{
    ui->setupUi(this);
    w=NULL;
}

Wgt_hotel::~Wgt_hotel()
{
    delete ui;
}

void Wgt_hotel::changeUi()
{
    ui->name->setText(info->get_name());
    pic.load(info->get_url());
    ui->pic->setPixmap(pic);
    QString loca;
    if(info->get_location().get_city()==info->get_location().get_province())
    {
        loca=info->get_location().get_province();
        loca.append(" ").append(info->get_location().get_district());
    }
    else{
        loca=info->get_location().get_province();
        loca.append(" ").append(info->get_location().get_city()).append(" ").append(info->get_location().get_district());
    }
    ui->l_lacation->setText(QString::fromLocal8Bit("地址： ")+loca);

    ui->l_phone->setText(QString::fromLocal8Bit("电话： ")+info->get_phone());
    ui->l_mark->setText(QString::fromLocal8Bit("评分：")+QString::number(info->get_mark(),'f',1));
    if(info->get_mark()>=4.8){
        ui->l_mark->setStyleSheet("color:#FFBB00");
    }
    else if(info->get_mark()>=4.5){
        ui->l_mark->setStyleSheet("color:#77FF00");
    }
    else if(info->get_mark()>=4){
        ui->l_mark->setStyleSheet("color:#00FFFF");
    }
    else{
        ui->l_mark->setStyleSheet("color:#000000");
    }
}

void Wgt_hotel::on_pBtn_comment_clicked()
{
    if(!w) w=new Wgt_comments(info->get_name(),info->get_comments());
    else {
        delete w;
        w=new Wgt_comments(info->get_name(),info->get_comments());
    }
    w->show();
}

void Wgt_hotel::on_pBtn_detail_clicked()
{
    emit pBtn_room_clicked(info);
}
