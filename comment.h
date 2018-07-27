#ifndef COMMENT_H
#define COMMENT_H

#include<QString>
//TODO: time funtion
using namespace std;

class Comment
{
public:
    Comment(const QString& name,const QString& content,double mark)
        :userName(name),content(content),mark(mark){}

    const QString& get_userName()const{ return userName; }
    const QString& get_content()const{ return content; }
          double    get_mark()const{return mark;}

private:
    const QString userName;
    const QString content;
          double     mark;
    //time
};

#endif // COMMENT_H
