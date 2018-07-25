#include "room.h"

Room::Room()
    :_type("null"),_url("NULL"),_description("NULL"),_price(0),_people(0),_sum(0),_discount(0)
{
}

Room::Room(QString type, QString url, QString description, double price, int people, int sum, double discount)
    :_type(type),_url(url),_description(description),_price(price),_people(people),_sum(sum),_discount(discount)
{

}



void Room::set_type(QString newType)
{
    _type=newType;
}

void Room::set_url(QString newurl)
{
    _url=newurl;
}

void Room::set_description(QString newdescription)
{
    _description=newdescription;
}

void Room::set_price(double newPrice)
{
    _price=newPrice;
}

void Room::set_people(int newPeople)
{
    _people=newPeople;
}

void Room::set_discount(double newDiscount)
{
    _discount=newDiscount;
}

void Room::set_sum(int nSum)
{
    _sum=nSum;
}

void Room::operator+=(int num)
{
    _sum+=num;
}

void Room::operator-=(int num)
{
    _sum-=num;
}

const QString &Room::get_type() const
{
    return _type;
}

const QString &Room::get_url() const
{
    return _url;
}

const QString &Room::get_description() const
{
    return _description;
}

const double &Room::get_price() const
{
    return _price;
}

const int &Room::get_people() const
{
    return _people;
}

double Room::get_discount()
{
    return _discount;
}

const double &Room::get_price_discounted() const
{
    return _discount*_price;
}

const int &Room::get_sum() const
{
    return _sum;
}
