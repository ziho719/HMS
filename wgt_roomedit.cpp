#include "wgt_roomedit.h"
#include "ui_wgt_roomedit.h"

Wgt_roomEdit::Wgt_roomEdit(Room *r, QWidget *parent) :
    QWidget(parent),room(r),
    ui(new Ui::Wgt_roomEdit)
{
    ui->setupUi(this);
    changeUi();
}

Wgt_roomEdit::~Wgt_roomEdit()
{
    delete ui;

}

void Wgt_roomEdit::on_pBtn_clicked()
{
    Dlg_editRoom *d=new Dlg_editRoom(room);
    connect(d,SIGNAL(success()),this,SLOT(have_changed()));
    d->exec();

}

void Wgt_roomEdit::have_changed()
{
    emit success();
}

void Wgt_roomEdit::changeUi()
{
    ui->label->setText(room->get_type());
    if(System::getSystem()->get_user()->userType()=="admin"){
        ui->pBtn->setText(QString::fromLocal8Bit("具体信息"));
    }
}
