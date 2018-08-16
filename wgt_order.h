#ifndef WGT_ORDER_H
#define WGT_ORDER_H

#include <QWidget>
#include "system.h"
#include "dlg_newcomment.h"
#include <QMessageBox>


//UI的一个组件

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

public slots:
    void pay(); //虽然只有一个messageBox
    void open_dlg_newComment();  //
    void newComment_added();
    void refund(); //
    void cancel();
    void checkin();
    void check_pay();

signals:
    void pBtn_clicked();
    void success();

private:
    Ui::Wgt_order *ui;
    Order *order;
};

#endif // WGT_ORDER_H
