#ifndef WGT_HOTEL_MANAGER_H
#define WGT_HOTEL_MANAGER_H

#include <QWidget>
#include "hotel.h"
#include "system.h"
#include <QDebug>

namespace Ui {
class Wgt_hotel_manager;
}

class Wgt_hotel_manager : public QWidget
{
    Q_OBJECT

public:
    explicit Wgt_hotel_manager(Hotel *h,QWidget *parent = 0);
    ~Wgt_hotel_manager();

public slots:
    void changeUi();
    void have_changed(); //让它变成待审核
    void have_checked();
    void open_dlg_hotelinfo();
    void open_dlg_room();
    void open_dlg_managerlist();

signals:
    void success();

private slots:
    void on_edit_info_or_look_info_clicked();
    void on_edit_room_or_look_room_clicked();
    void on_edit_manager_or_check_clicked();

private:
    Ui::Wgt_hotel_manager *ui;
    Hotel *hotel;
};

#endif // WGT_HOTEL_MANAGER_H
