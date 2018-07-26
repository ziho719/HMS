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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signInBtn_clicked()
{
    if(!System::getSystem()->get_user()) QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                                       ,QString::fromLocal8Bit("请先注销"),QMessageBox::Ok);

    signDlg->exec();

}

void MainWindow::reshow_user()
{
    if(!System::getSystem()->get_user()) ui->username_welcome->setText(tr("欢迎！")+System::getSystem()->get_user()->name());
    //TODO:function更新
    qDebug()<<"reshow user";
}
