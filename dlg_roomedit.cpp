#include "dlg_roomedit.h"
#include "ui_dlg_roomedit.h"

Dlg_roomEdit::Dlg_roomEdit(Hotel *hotel, QWidget *parent) :
    QDialog(parent),hotel(hotel),
    ui(new Ui::Dlg_roomEdit)
{
    ui->setupUi(this);
    show_room();
}

Dlg_roomEdit::~Dlg_roomEdit()
{
    delete ui;
}

void Dlg_roomEdit::have_changed()
{
    hotel->change_status_to_changed();
    show_room();
}

void Dlg_roomEdit::show_room()
{
    auto lw=ui->listWidget;
    lw->clear();
    for(auto room:hotel->get_hotel_info()->get_rooms()){
        Wgt_roomEdit *w=new Wgt_roomEdit(room,this);
        auto item=new QListWidgetItem;
        item->setSizeHint(w->size());
        lw->addItem(item);
        lw->setItemWidget(item,w);
        connect(w,SIGNAL(success()),this,SLOT(have_changed()));
    }
}
