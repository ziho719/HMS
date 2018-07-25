#include "functionbtn.h"
#include "ui_functionbtn.h"

FunctionBtn::FunctionBtn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FunctionBtn)
{
    ui->setupUi(this);
}

FunctionBtn::~FunctionBtn()
{
    delete ui;
}

void FunctionBtn::on_Btn_clicked()
{
    emit Btn_clicked();
}
