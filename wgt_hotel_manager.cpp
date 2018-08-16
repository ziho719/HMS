#include "wgt_hotel_manager.h"
#include "ui_wgt_hotel_manager.h"

Wgt_hotel_manager::Wgt_hotel_manager(Hotel *h, QWidget *parent) :
    QWidget(parent),hotel(h),
    ui(new Ui::Wgt_hotel_manager)
{
    ui->setupUi(this);
    changeUi();
}

Wgt_hotel_manager::~Wgt_hotel_manager()
{
    delete ui;
}

void Wgt_hotel_manager::changeUi()
{
    ui->label_hotelname->setText(hotel->get_hotel_info()->get_name());
    if(hotel->get_status()=="unchecked"){
        ui->label_status->setText(QString::fromLocal8Bit("新酒店"));
    }
    else if(hotel->get_status()=="changed"){
        ui->label_status->setText(QString::fromLocal8Bit("信息已修改"));
    }
    else if(hotel->get_status()=="unpassed"){
        ui->label_status->setText(QString::fromLocal8Bit("未通过审核"));
    }
    else if(hotel->get_status()=="checked"){
        ui->label_status->setText(QString::fromLocal8Bit("已审核"));
    }
    else;

    auto user=System::getSystem()->get_user();
    if(user->userType()=="manager"){
        ui->delete_or_unpassed->hide();
    }
    else if(user->userType()=="admin"){
        ui->edit_info_or_look_info->setText(QString::fromLocal8Bit("查看信息"));
        ui->edit_room_or_look_room->setText(QString::fromLocal8Bit("查看房间"));
        ui->edit_manager_or_check->setText(QString::fromLocal8Bit("审核完毕"));
    }
    else {qDebug()<<"wgt_h_m user bug";}
}

void Wgt_hotel_manager::to_changed()
{
    if(hotel->get_status()!="uncheck") hotel->change_status_to_changed();
}

void Wgt_hotel_manager::to_checked()
{
    hotel->change_status_to_checked();
    emit success();
}

void Wgt_hotel_manager::to_unpassed()
{
    hotel->change_status_to_unpassed();
    emit success();
}

void Wgt_hotel_manager::open_dlg_hotelinfo()
{
    qDebug()<<"open_dlg_hotelinfo";
    Dlg_hotelInfo *d=new Dlg_hotelInfo(hotel);
    d->exec();
    changeUi();
}

void Wgt_hotel_manager::open_dlg_room()
{
    qDebug()<<"open_dlg_room";
    Dlg_roomEdit *d=new Dlg_roomEdit(hotel);
    d->exec();
    changeUi();
}

void Wgt_hotel_manager::open_dlg_managerlist()
{
    qDebug()<<"open_dlg_hotelinfo";
    Dlg_addmenber *d=new Dlg_addmenber(hotel);
    d->exec();
    changeUi();
}

void Wgt_hotel_manager::on_edit_info_or_look_info_clicked()
{
    open_dlg_hotelinfo();
}

void Wgt_hotel_manager::on_edit_room_or_look_room_clicked()
{
    open_dlg_room();
}

void Wgt_hotel_manager::on_edit_manager_or_check_clicked()
{
    auto user=System::getSystem()->get_user();
    if(user->userType()=="manager"){
        open_dlg_managerlist();
    }
    else if(user->userType()=="admin"){
        to_checked();
    }
    else {qDebug()<<"wgt_h_m user bug";}
}

void Wgt_hotel_manager::on_delete_or_unpassed_clicked()
{
    auto user=System::getSystem()->get_user();
    if(user->userType()=="manager"){
        //没加入删除功能，暂时不会触发到这里
    }
    else if(user->userType()=="admin"){
        to_unpassed();
    }
}
