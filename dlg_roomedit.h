#ifndef DLG_ROOMEDIT_H
#define DLG_ROOMEDIT_H

#include <QDialog>
#include "system.h"
#include "wgt_roomedit.h"
#include <QListWidgetItem>
namespace Ui {
class Dlg_roomEdit;
}

//管理酒店的对话框

class Dlg_roomEdit : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_roomEdit(Hotel *hotel,QWidget *parent = 0);
    ~Dlg_roomEdit();
public slots:
    void have_changed(); //变成待审核
    void show_room();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dlg_roomEdit *ui;
    Hotel *hotel;
};

#endif // DLG_ROOMEDIT_H
