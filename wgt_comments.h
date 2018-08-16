#ifndef WGT_COMMENTS_H
#define WGT_COMMENTS_H

#include <QWidget>
#include "comment.h"
#include <vector>
#include <QString>
#include <QHeaderView>
#include <QTableView>
#include <QStandardItemModel>
#include <QDebug>

//评论对话框

namespace Ui {
class Wgt_comments;
}

class Wgt_comments : public QWidget
{
    Q_OBJECT

public:
    explicit Wgt_comments(const QString& name,const vector<Comment>& c,QWidget *parent = 0);
    ~Wgt_comments();

private:
    Ui::Wgt_comments *ui;
};

#endif // WGT_COMMENTS_H
