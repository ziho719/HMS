#ifndef DLG_ORDER_H
#define DLG_ORDER_H

#include <QDialog>
#include "wgt_order.h"

namespace Ui {
class Dlg_order;
}

class Dlg_order : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_order(QWidget *parent = 0);
    ~Dlg_order();

private slots:
    void on_pBtn_all_clicked();

private:
    Ui::Dlg_order *ui;
    Wgt_order *w;
};

#endif // DLG_ORDER_H
