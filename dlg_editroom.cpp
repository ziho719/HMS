#include "dlg_editroom.h"
#include "ui_dlg_editroom.h"

Dlg_editRoom::Dlg_editRoom(Room *r, QWidget *parent) :
    QDialog(parent),room(r),
    ui(new Ui::Dlg_editRoom)
{
    ui->setupUi(this);
    changeUi();
}

Dlg_editRoom::~Dlg_editRoom()
{
    delete ui;
}

void Dlg_editRoom::changeUi()
{
    ui->lineEdit_name-> setText(room->get_type());
    ui->lineEdit_price->setText(QString::number(room->get_price(),'f',0));
    ui->lineEdit_sum->  setText(QString::number(room->get_sum(),10));
    ui->lineEdit_type->  setText(room->get_description());
    if(room->get_discount()!=1){
        ui->lineEdit_discount->setText(QString::number(room->get_discount(),'f',0));
    }
    else  ui->lineEdit_discount->clear();
    if(System::getSystem()->get_user()->userType()=="admin"){
        ui->lineEdit_name->    setFocusPolicy(Qt::NoFocus);
        ui->lineEdit_price->   setFocusPolicy(Qt::NoFocus);
        ui->lineEdit_sum->      setFocusPolicy(Qt::NoFocus);
        ui->lineEdit_type->     setFocusPolicy(Qt::NoFocus);
        ui->lineEdit_discount->setFocusPolicy(Qt::NoFocus);
        ui->yes->hide();
        ui->no->hide();
    }

}


void Dlg_editRoom::on_yes_clicked()
{
    if(ui->lineEdit_name-> text()==room->get_type() &&
       ui->lineEdit_price->text()==QString::number(room->get_price(),'f',0) &&
       ui->lineEdit_sum->  text()==QString::number(room->get_sum(),10) &&
       ui->lineEdit_type-> text()==room->get_description() &&
       ((ui->lineEdit_discount->text()=="" && room->get_discount()==1) ||
        ui->lineEdit_discount->text()==QString::number(room->get_discount(),'f',0)))
    {
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("您没有修改"),QMessageBox::Ok);
        return;
        this->close();
    }
    if(ui->lineEdit_name-> text()=="" ||
       ui->lineEdit_price->text()=="" ||
       ui->lineEdit_sum->  text()=="" ||
       ui->lineEdit_type-> text()=="" ){
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("请不要留空"),QMessageBox::Ok);
        return;
    }
    QRegExp reg("\\d*");   //正则判断是否数字
    if(!reg.exactMatch(ui->lineEdit_price->text()) ||
       !reg.exactMatch(ui->lineEdit_sum->text()) ||
            !(reg.exactMatch(ui->lineEdit_discount->text())|| ui->lineEdit_discount->text()=="")){
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("请填入合适数字"),QMessageBox::Ok);
        return;
    }

    if(ui->lineEdit_name-> text()!=room->get_type() ||
       ui->lineEdit_sum->  text()!=QString::number(room->get_sum(),10) ||
       ui->lineEdit_type-> text()!=room->get_description())
    {
        emit success();
    }
    else{
        QMessageBox::information(NULL,QString::fromLocal8Bit("success")
                                 ,QString::fromLocal8Bit("修改价格不需要审核"),QMessageBox::Ok);
    }

    room->set_description(ui->lineEdit_type->text());
    room->set_type(ui->lineEdit_name->text());
    room->set_price(ui->lineEdit_price->text().toDouble());
    room->set_sum(ui->lineEdit_sum->text().toInt());
    if(ui->lineEdit_discount->text()==""){
        room->set_discount(1);
    }
    else{
        room->set_discount(ui->lineEdit_discount->text().toDouble());
    }

    this->close();

}

void Dlg_editRoom::on_no_clicked()
{
    this->close();
}
