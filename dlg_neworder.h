#ifndef DLG_NEWORDER_H
#define DLG_NEWORDER_H

#include <QDialog>
#include "system.h"
#include "hotelinfo.h"
#include <memory>
#include "room.h"

namespace Ui {
class Dlg_newOrder;
}

class Dlg_newOrder : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_newOrder(shared_ptr<HotelInfo> info, Room r,QWidget *parent = 0);
    ~Dlg_newOrder();

public slots:
    void changeUi();

private:
    Ui::Dlg_newOrder *ui;
    shared_ptr<HotelInfo> info;
    Room room;
};

#endif // DLG_NEWORDER_H
