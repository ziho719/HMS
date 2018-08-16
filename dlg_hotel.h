#ifndef DLG_HOTEL_H
#define DLG_HOTEL_H

#include <QDialog>
#include "wgt_hotel_manager.h"
#include "system.h"
#include <QListWidgetItem>

//管理酒店的界面

namespace Ui {
class Dlg_hotel;
}

class Dlg_hotel : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_hotel(QWidget *parent = 0);
    ~Dlg_hotel();

public slots:
    void show_list(); //显示酒店列表
private slots:
    void on_pBtn_newHotel_clicked();

private:
    Ui::Dlg_hotel *ui;
};

#endif // DLG_HOTEL_H
