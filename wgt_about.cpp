#include "wgt_about.h"
#include "ui_wgt_about.h"

Wgt_about::Wgt_about(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wgt_about)
{
    ui->setupUi(this);
}

Wgt_about::~Wgt_about()
{
    delete ui;
}

void Wgt_about::on_pushButton_clicked()
{
    QMessageBox::information(NULL,QString::fromLocal8Bit("ziho")
                             ,QString::fromLocal8Bit("我也这么觉得"),QMessageBox::Ok);
    this->close();
}

void Wgt_about::on_pushButton_2_clicked()
{
    ui->pushButton->move(ui->pushButton_2->pos());
    ui->pushButton->setFixedWidth(ui->pushButton->width()+10);
    ui->pushButton->setFixedHeight(ui->pushButton->height()+10);
    QFont f=ui->pushButton->font();
    f.setPointSize(f.pointSize()+1);
    ui->pushButton->setFont(f);
    switch (rand()%10) {
    case 1:
        if(ui->pushButton_2->x()==20 &&ui->pushButton->y()==58)
        {
            ui->pushButton_2->move(150,300);
        }
        ui->pushButton_2->move(20,58);
        break;
    case 0:
        if(ui->pushButton_2->x()==89 &&ui->pushButton->y()==123)
        {
            ui->pushButton_2->move(150,300);
        }
        ui->pushButton_2->move(89,123);
        break;
    case 2:
        if(ui->pushButton_2->x()==330 &&ui->pushButton->y()==327)
        {
            ui->pushButton_2->move(150,300);
        }
        ui->pushButton_2->move(330,327);
        break;
    case 3:
        if(ui->pushButton_2->x()==57 &&ui->pushButton->y()==250)
        {
            ui->pushButton_2->move(150,300);
        }
        ui->pushButton_2->move(57,250);
        break;
    case 4:
        if(ui->pushButton_2->x()==141 &&ui->pushButton->y()==31)
        {
            ui->pushButton_2->move(150,300);
        }
        ui->pushButton_2->move(141,31);
        break;
    case 5:
        if(ui->pushButton_2->x()==200 &&ui->pushButton->y()==200)
        {
            ui->pushButton_2->move(150,300);
        }
        ui->pushButton_2->move(200,200);
        break;
    case 6:
        if(ui->pushButton_2->x()==1 &&ui->pushButton->y()==1)
        {
            ui->pushButton_2->move(150,300);
        }
        ui->pushButton_2->move(1,1);
        break;
    case 7:
        if(ui->pushButton_2->x()==300 &&ui->pushButton->y()==0)
        {
            ui->pushButton_2->move(150,300);
        }
        ui->pushButton_2->move(300,0);
        break;
    case 8:
        if(ui->pushButton_2->x()==30 &&ui->pushButton->y()==250)
        {
            ui->pushButton_2->move(150,300);
        }
        ui->pushButton_2->move(30,250);
        break;
    case 9:
        if(ui->pushButton_2->x()==41 &&ui->pushButton->y()==200)
        {
            ui->pushButton_2->move(150,300);
        }
        ui->pushButton_2->move(41,200);
        break;
    default:
        break;
    }
}
