#include "wgt_comments.h"
#include "ui_wgt_comments.h"

Wgt_comments::Wgt_comments(const QString &name, const vector<Comment> &c, QWidget *parent):
    QWidget(parent),
    ui(new Ui::Wgt_comments)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("查看评论"));
    ui->hotelname->setText(name);
    QTableView *table=ui->tableView;
    QStandardItemModel* model = new QStandardItemModel(this);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置只读
    table->verticalHeader()->hide();

    for(int i=0;i<c.size();i++){
        model->setItem(i,0,new QStandardItem(c[i].get_userName()));
        model->setItem(i,1,new QStandardItem(c[i].get_content()));
        model->setItem(i,2,new QStandardItem(QString::number(c[i].get_mark(),'f',1)));
    }
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("用户名"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("评论"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("打分"));
    table->setModel(model);
    table->resizeColumnToContents(0);
    table->resizeColumnToContents(2);
    table->setColumnWidth(1,500);
}

Wgt_comments::~Wgt_comments()
{
    delete ui;
}
