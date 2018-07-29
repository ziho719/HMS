#include "functionbtn.h"
#include "ui_functionbtn.h"

FunctionBtn::FunctionBtn(QString top, QString d, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FunctionBtn)
{
    ui->setupUi(this);
    ui->labeltop->setText(top);
    ui->labeldown->setText(d);
}

FunctionBtn::~FunctionBtn()
{
    delete ui;
}

void FunctionBtn::on_Btn_clicked()
{
    qDebug()<<"cli";
    emit Btn_clicked();
}
