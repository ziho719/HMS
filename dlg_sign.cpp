#include "dlg_sign.h"
#include "ui_dlg_sign.h"

dlg_sign::dlg_sign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_sign)
{
    ui->setupUi(this);

}

dlg_sign::~dlg_sign()
{
    delete ui;
}


void dlg_sign::on_pushBtn_signin_clicked()
{
    //用户还是管理员、是否为空、用户存在吗、密码正确吗
    if(ui->lineEdit_username->text()=="") {
       QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统"),
                                QString::fromLocal8Bit("请填入用户名pls"),QMessageBox::Ok);
        return;
    }
    if(ui->lineEdit_pwd->text()==""){
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("填入密码pls"),QMessageBox::Ok);
        return;
    }
    if(ui->radioBtn_customer->isChecked()){ //选中用



        qDebug()<<"customer check";
    }
    else if(ui->radioBtn_manager->isChecked()){

        qDebug()<<"manager check";
    }
    else if(ui->radioBtn_admin->isChecked()){

        qDebug()<<"admin check";
    }
    else{
        QMessageBox::information(NULL,"酒店管理系统",QString::fromLocal8Bit("选择用户类型"),QMessageBox::Ok);
    }



    emit success();
    this->close();
}

void dlg_sign::on_pushBtn_signup_clicked()
{

}
