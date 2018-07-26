#ifndef WGT_HOTEL_H
#define WGT_HOTEL_H

#include <QWidget>

namespace Ui {
class Wgt_hotel;
}

class Wgt_hotel : public QWidget
{
    Q_OBJECT

public:
    explicit Wgt_hotel(QWidget *parent = 0);
    ~Wgt_hotel();

private:
    Ui::Wgt_hotel *ui;
};

#endif // WGT_HOTEL_H
