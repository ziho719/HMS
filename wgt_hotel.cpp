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

void Wgt_hotel::changeUi(const QString &url, const QString &name, const Location &l, const QString &phone, double mark)
{
    ui->name->setText(name);
    pic.load(url);
    ui->pic->setPixmap(pic);
    QString loca;
    if(l.get_city()==l.get_province())
    {
        loca=l.get_province();
        loca.append(" ").append(l.get_district());
    }
    else{
        loca=l.get_province();
        loca.append(" ").append(l.get_city()).append(" ").append(l.get_district());
    }
    ui->l_lacation->setText((loca));

    ui->l_phone->setText(phone);
    ui->l_mark->setText(QString::number(mark,'f',1));
}
