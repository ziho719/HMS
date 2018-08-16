#include "dlg_addmenber.h"
#include "ui_dlg_addmenber.h"

Dlg_addmenber::Dlg_addmenber(Hotel *h, QWidget *parent) :
    QDialog(parent),hotel(h),
    ui(new Ui::Dlg_addmenber)
{
    ui->setupUi(this);
    if(hotel==NULL) { //是管理员账户
        ui->label->setText(QString::fromLocal8Bit("为平台注册管理员"));
    }
}

Dlg_addmenber::~Dlg_addmenber()
{
    delete ui;
}

void Dlg_addmenber::on_pushButton_2_clicked()
{
    this->close();
}

void Dlg_addmenber::on_pushButton_clicked()  //点击确认
{
    if(ui->lineEdit_pwd->text()=="" ||ui->lineEdit_user->text()==""){
        QMessageBox::information(NULL,QString::fromLocal8Bit("fail")
                                 ,QString::fromLocal8Bit("不要留空！"),QMessageBox::Ok);
        return;
    }
    auto s=System::getSystem();
    if(hotel==NULL) {
        if(s->check_name_available(ui->lineEdit_user->text())){
            s->add_admin(ui->lineEdit_user->text(),ui->lineEdit_pwd->text());
            QMessageBox::information(NULL,QString::fromLocal8Bit("success")
                                     ,QString::fromLocal8Bit("已添加！"),QMessageBox::Ok);
            this->close();
        }
        else{
            QMessageBox::information(NULL,QString::fromLocal8Bit("fail")
                                     ,QString::fromLocal8Bit("名字已存在"),QMessageBox::Ok);
            return;
        }
    }
    else{
        if(!s->find_manager(ui->lineEdit_user->text())){
            QMessageBox::information(NULL,QString::fromLocal8Bit("fail")
                                     ,QString::fromLocal8Bit("管理员账户不存在"),QMessageBox::Ok);
            return;
        }
        if(hotel->is_manager(ui->lineEdit_user->text())){
            QMessageBox::information(NULL,QString::fromLocal8Bit("fail")
                                     ,QString::fromLocal8Bit("该账户已是该酒店的管理员"),QMessageBox::Ok);
            return;
        }
        if(s->check_manager_account(ui->lineEdit_user->text(),ui->lineEdit_pwd->text())!=NULL){
            hotel->add_manager(ui->lineEdit_user->text());
            QMessageBox::information(NULL,QString::fromLocal8Bit("success")
                                     ,QString::fromLocal8Bit("已添加！"),QMessageBox::Ok);
            this->close();
        }
        else{

           QMessageBox::information(NULL,QString::fromLocal8Bit("fail")
                                    ,QString::fromLocal8Bit("密码不正确"),QMessageBox::Ok);
           return;

        }
    }
}
