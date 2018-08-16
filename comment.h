#ifndef COMMENT_H
#define COMMENT_H

#include<QString>
using namespace std;

class Comment
{
public:
    Comment(const QString& name,const QString& content,double mark)
        :userName(name),content(content),mark(mark){}

    const QString& get_userName()const{ return userName; }
    const QString& get_content()const{ return content; }
          double    get_mark()const{return mark;}

          //不应该可以改变评论，没有setter函数

private:
    const QString userName;
    const QString content;
          double     mark;
};

#endif // COMMENT_H
