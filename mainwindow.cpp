#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "system.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化signDlg
    signDlg=new dlg_sign();
    connect(signDlg,SIGNAL(success()),this,SLOT(reshow_user()));


    ui->label_2->setPixmap(QPixmap(QString::fromLocal8Bit(":/pics/pic/1-豪华.jpg")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signInBtn_clicked()
{
    if(System::getSystem()->get_user()!=NULL)
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                        ,QString::fromLocal8Bit("请先注销"),QMessageBox::Ok);
    else{
        signDlg->exec();
    }
}

void MainWindow::reshow_user()
{
    if(System::getSystem()->get_user()!=NULL)
        ui->username_welcome->setText(QString::fromLocal8Bit("欢迎！").append(System::getSystem()->get_user()->name()));
    else
        ui->username_welcome->setText(QString::fromLocal8Bit("您尚未登录"));
    //TODO:function更新
    qDebug()<<"reshow user";
}

void MainWindow::on_signoutBtn_clicked()
{
    auto s=System::getSystem();
    if(s->get_user()){
        s->set_user(NULL);
        reshow_user();
    }
    else
    {
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("您尚未登录"),QMessageBox::Ok);
    }
}
