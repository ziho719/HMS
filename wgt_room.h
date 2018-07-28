#ifndef WGT_ROOM_H
#define WGT_ROOM_H

#include <QWidget>
#include "room.h"
#include <QPixmap>
#include "system.h"
#include <QMessageBox>

namespace Ui {
class Wgt_room;
}

class Wgt_room : public QWidget
{
    Q_OBJECT

public:
    explicit Wgt_room(shared_ptr<HotelInfo> info,Room r,QWidget *parent = 0);
    ~Wgt_room();
public slots:
    void changeUi();

private slots:
    void on_pBtn_newOrder_clicked();

signals:
    void newOrder(shared_ptr<HotelInfo> info,Room r);

private:
    Ui::Wgt_room *ui;
    Room room;
    QPixmap pic;
    shared_ptr<HotelInfo> info;
};

#endif // WGT_ROOM_H
