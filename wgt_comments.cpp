#include "wgt_comments.h"
#include "ui_wgt_comments.h"

Wgt_comments::Wgt_comments(const QString &name, const vector<Comment> &c, QWidget *parent):
    QWidget(parent),
    ui(new Ui::Wgt_comments)
{
    ui->setupUi(this);
    ui->hotelname->setText(name);
    QTableView *table=ui->tableView;
    QStandardItemModel* model = new QStandardItemModel(this);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置只读
    qDebug()<<"here??";
    for(int i=0;i<c.size();i++){
        model->setItem(i,0,new QStandardItem(c[i].get_userName()));
        model->setItem(i,1,new QStandardItem(c[i].get_content()));
        model->setItem(i,2,new QStandardItem(QString::number(c[i].get_mark(),'f',1)));
    }
    table->setModel(model);
}

Wgt_comments::~Wgt_comments()
{
    delete ui;
}
