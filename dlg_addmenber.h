#ifndef DLG_ADDMENBER_H
#define DLG_ADDMENBER_H

#include <QDialog>
#include "system.h"
#include <QMessageBox>

//为酒店新增管理员的界面

namespace Ui {
class Dlg_addmenber;
}

class Dlg_addmenber : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_addmenber(Hotel *h,QWidget *parent = 0);
    ~Dlg_addmenber();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dlg_addmenber *ui;
    Hotel *hotel;
};

#endif // DLG_ADDMENBER_H
