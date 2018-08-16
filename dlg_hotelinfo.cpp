#include "dlg_hotelinfo.h"
#include "ui_dlg_hotelinfo.h"

Dlg_hotelInfo::Dlg_hotelInfo(Hotel *h,QWidget *parent) :
    QDialog(parent),hotel(h),
    ui(new Ui::Dlg_hotelInfo)
{
    ui->setupUi(this);

    //根据登录用户不同改变UI,之后一般放在ChangeUi函数里

    ui->lineEdit_city->setText(hotel->get_hotel_info()->get_location().get_city());
    ui->lineEdit_province->setText(hotel->get_hotel_info()->get_location().get_province());
    ui->lineEdit_district->setText(hotel->get_hotel_info()->get_location().get_district());
    ui->lineEdit_name->setText(hotel->get_hotel_info()->get_name());
    ui->lineEdit_phone->setText(hotel->get_hotel_info()->get_phone());
    if(System::getSystem()->get_user()->userType()=="admin"){
        ui->lineEdit_city->setFocusPolicy(Qt::NoFocus);
        ui->lineEdit_province->setFocusPolicy(Qt::NoFocus);
        ui->lineEdit_district->setFocusPolicy(Qt::NoFocus);
        ui->lineEdit_name->setFocusPolicy(Qt::NoFocus);
        ui->lineEdit_phone->setFocusPolicy(Qt::NoFocus);
        ui->pBtn_yes->hide();
        ui->pBtn_no->hide();
    }
}

Dlg_hotelInfo::~Dlg_hotelInfo()
{
    delete ui;
}

void Dlg_hotelInfo::on_pBtn_yes_clicked()
{
    if(ui->lineEdit_city->text()!=hotel->get_hotel_info()->get_location().get_city() ||
       ui->lineEdit_province->text()!=hotel->get_hotel_info()->get_location().get_province() ||
       ui->lineEdit_district->text()!=hotel->get_hotel_info()->get_location().get_district() ||
       ui->lineEdit_name->text()!=hotel->get_hotel_info()->get_name() ||
       ui->lineEdit_phone->text()!=hotel->get_hotel_info()->get_phone())
    {
        Location l(ui->lineEdit_province->text(),ui->lineEdit_city->text(),
                                ui->lineEdit_district->text());
        hotel->get_hotel_info()->edit_location(l);
        hotel->get_hotel_info()->edit_name(ui->lineEdit_name->text());
        hotel->get_hotel_info()->edit_phone(ui->lineEdit_phone->text());
        hotel->change_status_to_changed();
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("修改成功，等待管理审核"),QMessageBox::Ok);
        this->close();
    }
    else{
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("您没有修改"),QMessageBox::Ok);
    }

}

void Dlg_hotelInfo::on_pBtn_no_clicked()
{
    this->close();
}
