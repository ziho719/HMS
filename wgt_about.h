#ifndef WGT_ABOUT_H
#define WGT_ABOUT_H

#include <QWidget>
#include <QMessageBox>
#include <stdlib.h>
#include <QFont>

//just for fun，与程序功能无关

namespace Ui {
class Wgt_about;
}

class Wgt_about : public QWidget
{
    Q_OBJECT

public:
    explicit Wgt_about(QWidget *parent = 0);
    ~Wgt_about();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Wgt_about *ui;
};

#endif // WGT_ABOUT_H
