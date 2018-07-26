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
    QString name_input=ui->lineEdit_username->text();
    QString pwd_input=ui->lineEdit_pwd->text();
    if(ui->radioBtn_customer->isChecked()){ //选中了用户
        qDebug()<<"customer check";
        Customer *customer=System::getSystem()->check_customer_account(name_input,pwd_input);
        if(customer!=NULL){
            System::getSystem()->set_user(customer);
            emit success();
            this->close();
        }
        else if(System::getSystem()->find_customer(name_input)==NULL){
            QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                     ,QString::fromLocal8Bit("用户不存在"),QMessageBox::Ok);
            return;
        }
        else{
            QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                     ,QString::fromLocal8Bit("密码不正确"),QMessageBox::Ok);
            return;
        }

    }
    else if(ui->radioBtn_manager->isChecked()){
        qDebug()<<"manager check";
        Manager *m=System::getSystem()->check_manager_account(name_input,pwd_input);
        if(m!=NULL){
            System::getSystem()->set_user(m);
            emit success();
            this->close();
        }
        else if(System::getSystem()->find_manager(name_input)==NULL){
            QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                     ,QString::fromLocal8Bit("用户不存在"),QMessageBox::Ok);
            return;
        }
        else{
            QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                     ,QString::fromLocal8Bit("密码不正确"),QMessageBox::Ok);
            return;
        }
    }
    else if(ui->radioBtn_admin->isChecked()){

        qDebug()<<"admin check";
        Administrater *a=System::getSystem()->check_admin_account(name_input,pwd_input);
        if(a!=NULL){
            System::getSystem()->set_user(a);
            emit success();
            this->close();
        }
        else if(System::getSystem()->find_admin(name_input)==NULL){
            QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                     ,QString::fromLocal8Bit("用户不存在"),QMessageBox::Ok);
            return;
        }
        else{
            QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                     ,QString::fromLocal8Bit("密码不正确"),QMessageBox::Ok);
            return;
        }
    }
    else{
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("选择用户类型"),QMessageBox::Ok);
        return;
    }

}

void dlg_sign::on_pushBtn_signup_clicked()
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
    QString name_input=ui->lineEdit_username->text();
    QString pwd_input=ui->lineEdit_pwd->text();
    if(!System::getSystem()->check_name_available(name_input)){
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("用户名已存在"),QMessageBox::Ok);
        return;
    }
    if(ui->radioBtn_customer->isChecked()){ //选中用户
        System::getSystem()->add_customer(name_input,pwd_input,NULL);
        emit success();
        this->close();
        qDebug()<<"customer sign up";
    }
    else if(ui->radioBtn_manager->isChecked()){
        System::getSystem()->add_manager(name_input,pwd_input);
        emit success();
        this->close();
        qDebug()<<"manager sign up";
    }
    else if(ui->radioBtn_admin->isChecked()){
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("不能注册管理员账户"),QMessageBox::Ok);
        qDebug()<<"admin sign up refuse";
    }
    else{
        QMessageBox::information(NULL,"酒店管理系统",QString::fromLocal8Bit("选择用户类型"),QMessageBox::Ok);
        return;
    }
}
