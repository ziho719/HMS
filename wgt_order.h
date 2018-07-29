#ifndef WGT_ORDER_H
#define WGT_ORDER_H

#include <QWidget>
#include "system.h"

namespace Ui {
class Wgt_order;
}

class Wgt_order : public QWidget
{
    Q_OBJECT

public:
    explicit Wgt_order(Order *o,QWidget *parent = 0);
    ~Wgt_order();
    void changeUi();

private slots:
    void on_pBtn_clicked();

signals:
    void pBtn_clicked();

private:
    Ui::Wgt_order *ui;
    Order *order;
};

#endif // WGT_ORDER_H
