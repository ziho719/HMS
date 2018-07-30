#ifndef DLG_HOTELINFO_H
#define DLG_HOTELINFO_H

#include <QDialog>
#include "hotel.h"
#include<QMessageBox>
#include "location.h"

namespace Ui {
class Dlg_hotelInfo;
}

class Dlg_hotelInfo : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_hotelInfo(Hotel *h,QWidget *parent = 0);
    ~Dlg_hotelInfo();

signals:
    void success();

private slots:
    void on_pBtn_yes_clicked();

    void on_pBtn_no_clicked();

private:
    Ui::Dlg_hotelInfo *ui;
    Hotel *hotel;
};

#endif // DLG_HOTELINFO_H
