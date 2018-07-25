#ifndef FUNCTIONBTN_H
#define FUNCTIONBTN_H

#include <QWidget>

namespace Ui {
class FunctionBtn;
}

class FunctionBtn : public QWidget
{
    Q_OBJECT

public:
    explicit FunctionBtn(QWidget *parent = 0);
    ~FunctionBtn();



private slots:
    void on_Btn_clicked();

signals:
    void Btn_clicked();

private:
    Ui::FunctionBtn *ui;
};

#endif // FUNCTIONBTN_H
