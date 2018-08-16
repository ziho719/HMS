#ifndef WGT_HOTEL_H
#define WGT_HOTEL_H

#include <QWidget>
#include "location.h"
#include <QPixmap>
#include "hotelinfo.h"
#include <memory>
#include "wgt_comments.h"

//UI的一个组件

namespace Ui {
class Wgt_hotel;
}

class Wgt_hotel : public QWidget
{
    Q_OBJECT

public:
    explicit Wgt_hotel(QWidget *parent = 0,shared_ptr<HotelInfo> i=NULL);
    ~Wgt_hotel();

public slots:
    void changeUi();


private slots:
    void on_pBtn_comment_clicked();
    void on_pBtn_detail_clicked();
signals:
    void pBtn_room_clicked(shared_ptr<HotelInfo> &ptr);

private:
    Ui::Wgt_hotel *ui;
    shared_ptr<HotelInfo> info;
    QPixmap pic;
    Wgt_comments *w;
};

#endif // WGT_HOTEL_H
