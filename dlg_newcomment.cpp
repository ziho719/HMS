#include "dlg_newcomment.h"
#include "ui_dlg_newcomment.h"

Dlg_newComment::Dlg_newComment(QString hotelname, QWidget *parent) :
    QDialog(parent),name(hotelname),
    ui(new Ui::Dlg_newComment)
{
    ui->setupUi(this);
    ui->lineEdit->setText("4.7");
    ui->textBrowser->setText(QString::fromLocal8Bit("体验不错，下次再来"));
}

Dlg_newComment::~Dlg_newComment()
{
    delete ui;
}

void Dlg_newComment::on_pushButton_clicked()
{
    if(ui->textBrowser->toPlainText().isEmpty()){
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("输入评论"),QMessageBox::Ok);
        return;
    }
    if(ui->lineEdit->text().isEmpty()){
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("输入评分"),QMessageBox::Ok);
        return ;
    }
    QString patten("\\d*\\.?\\d*");  //正则表达式判断是否数字
    QRegExp reg(patten);
    if(!reg.exactMatch(ui->lineEdit->text())){
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("评分应该是数字"),QMessageBox::Ok);
        return ;
    }
    if(ui->lineEdit->text().toDouble()>5 ||ui->lineEdit->text().toDouble()<0){
        QMessageBox::information(NULL,QString::fromLocal8Bit("酒店管理系统")
                                 ,QString::fromLocal8Bit("评分的范围不对"),QMessageBox::Ok);
        return ;
    }
    Hotel *h=System::getSystem()->find_hotel(name);
    h->get_hotel_info()->add_comment(System::getSystem()->get_user()->name(),
                                     ui->textBrowser->toPlainText(),ui->lineEdit->text().toDouble());
    emit success();
    this->close();
}
