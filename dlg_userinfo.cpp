#include "dlg_userinfo.h"
#include "ui_dlg_userinfo.h"

Dlg_userInfo::Dlg_userInfo(User *u, QWidget *parent) :
    QDialog(parent),user(u),
    ui(new Ui::Dlg_userInfo)
{
    ui->setupUi(this);
    ui->lineEdit_phone->setText(u->get_phone());
    ui->lineEdit_user->setText(u->name());
    ui->pwd_Box->hide();
}

Dlg_userInfo::~Dlg_userInfo()
{
    delete ui;
}

void Dlg_userInfo::on_cancel_clicked_clicked()
{
    this->close();
}

void Dlg_userInfo::on_yes_clicked()
{
    if(ui->lineEdit_newpwd->text()!="" && ui->lineEdit_oldpwd->text()!=""){
        if(!user->edit_pwd(ui->lineEdit_oldpwd->text(),ui->lineEdit_newpwd->text())){
            QMessageBox::information(NULL,QString::fromLocal8Bit("fail")
                                     ,QString::fromLocal8Bit("原密码不正确"),QMessageBox::Ok);
            return;
        }
    }
    else if(ui->lineEdit_newpwd->text()=="" && ui->lineEdit_oldpwd->text()=="")
    {
        //do nothing
    }
    else if(ui->lineEdit_newpwd->text()==""){
        QMessageBox::information(NULL,QString::fromLocal8Bit("HMS")
                                 ,QString::fromLocal8Bit("输入新密码！"),QMessageBox::Ok);
        return;
    }
    else if(ui->lineEdit_oldpwd->text()==""){
        QMessageBox::information(NULL,QString::fromLocal8Bit("HMS")
                                 ,QString::fromLocal8Bit("输入原密码！"),QMessageBox::Ok);
        return;
    }
    else{
        qDebug()<<"wrong";
        return;
    }
    QRegExp r("\\d*");
    if(ui->lineEdit_phone->text()!="" && !r.exactMatch(ui->lineEdit_phone->text())){
        QMessageBox::information(NULL,QString::fromLocal8Bit("HMS")
                                 ,QString::fromLocal8Bit("不是一个电话号"),QMessageBox::Ok);
        return;
    }
    user->edit_phone(ui->lineEdit_phone->text());

    QMessageBox::information(NULL,QString::fromLocal8Bit("HMS")
                             ,QString::fromLocal8Bit("修改成功"),QMessageBox::Ok);
    this->close();
}

void Dlg_userInfo::on_edit_pwd_clicked()
{
    ui->pwd_Box->show();
}
