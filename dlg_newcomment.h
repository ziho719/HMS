#ifndef DLG_NEWCOMMENT_H
#define DLG_NEWCOMMENT_H

#include <QDialog>
#include "system.h"
#include <QMessageBox>
#include <QRegExp>

//新增评论的对话框

namespace Ui {
class Dlg_newComment;
}

class Dlg_newComment : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_newComment(QString hotelname,QWidget *parent = 0);
    ~Dlg_newComment();

signals:
    void success();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dlg_newComment *ui;
    QString name;
};

#endif // DLG_NEWCOMMENT_H
