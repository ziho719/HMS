#ifndef ROOM_H
#define ROOM_H

#include<QString>

using namespace std;
class Room
{
public:
    Room();
    Room(QString type, QString url, QString description, double price, int sum, double discount=-1); //构造

    void set_type(QString newType);
    void set_url(QString newurl);
    void set_description(QString newdescription);
    void set_price(double newPrice);
    void set_discount(double newDiscount);
    void set_sum(int nSum);
    void operator+=(int num); //增加_sum，如旅客退房等
    void operator-=(int num); //减少

    const QString&   get_type() const;
    const QString&   get_url() const;
    const QString&   get_description() const;
    const double &   get_price()const;
    const double &   get_discount();
    const int    &   get_sum()const;

private:
    QString _type;  //房型或房名
    QString _url;   //图片
    QString _description;
    double  _price;
    double  _discount; //折扣后的价格
    int     _sum;  //房型数量

};

#endif // ROOM_H
