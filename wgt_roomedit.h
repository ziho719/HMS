#ifndef WGT_ROOMEDIT_H
#define WGT_ROOMEDIT_H

#include <QWidget>
#include "system.h"
#include "dlg_editroom.h"


//UI的一个组件


namespace Ui {
class Wgt_roomEdit;
}

class Wgt_roomEdit : public QWidget
{
    Q_OBJECT

public:
    explicit Wgt_roomEdit(Room *r,QWidget *parent = 0);
    ~Wgt_roomEdit();



private slots:
    void on_pBtn_clicked();
    void have_changed();
    void changeUi();

signals:
    void success();

private:
    Ui::Wgt_roomEdit *ui;
    Room *room;
};

#endif // WGT_ROOMEDIT_H
