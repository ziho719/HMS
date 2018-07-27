#ifndef WGT_HOTEL_H
#define WGT_HOTEL_H

#include <QWidget>
#include "location.h"
#include <QPixmap>

namespace Ui {
class Wgt_hotel;
}

class Wgt_hotel : public QWidget
{
    Q_OBJECT

public:
    explicit Wgt_hotel(QWidget *parent = 0);
    ~Wgt_hotel();

public slots:
    void changeUi(const QString &url, const QString &name
                  , const Location &l, const QString &phone, double mark);
private:
    Ui::Wgt_hotel *ui;
    QPixmap pic;
};

#endif // WGT_HOTEL_H
