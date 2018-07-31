#ifndef DLG_EDITROOM_H
#define DLG_EDITROOM_H

#include <QDialog>
#include "room.h"
#include "system.h"
#include <QRegExp>
#include <QMessageBox>

namespace Ui {
class Dlg_editRoom;
}

class Dlg_editRoom : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_editRoom(Room *r,QWidget *parent = 0);
    ~Dlg_editRoom();
    void changeUi();

private slots:
    void on_yes_clicked();
    void on_no_clicked();

signals:
    void success();

private:
    Ui::Dlg_editRoom *ui;
    Room *room;
};

#endif // DLG_EDITROOM_H
