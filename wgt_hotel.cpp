#include "wgt_hotel.h"
#include "ui_wgt_hotel.h"

Wgt_hotel::Wgt_hotel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wgt_hotel)
{
    ui->setupUi(this);
}

Wgt_hotel::~Wgt_hotel()
{
    delete ui;
}
