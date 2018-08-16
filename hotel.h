#ifndef HOTEL_H
#define HOTEL_H

#include"hotelinfo.h"
#include<memory>
#include<QDebug>
#include <vector>
#include "system.h"

//酒店类

using namespace std;

namespace HotelStatus {  //定义了酒店状态
    enum STATUS{
        unchecked,
        changed,
        checked,
        unpassed,
    };
}
using HotelStatus::checked;
using HotelStatus::unchecked;
using HotelStatus::changed;
using HotelStatus::unpassed;

class HotelInfo;

class Hotel
{
public:
    Hotel(shared_ptr<HotelInfo> p,const vector<QString>& mn);

    void change_status_to_unchecked();   //与状态有关函数
    void change_status_to_checked();
    void change_status_to_changed();
    void change_status_to_unpassed();
    QString get_status();

    shared_ptr<HotelInfo>& get_hotel_info();

    const vector<QString>& get_manager();  //与管理员有关函数
    bool is_manager(QString name);
    bool add_manager(QString name);

private:
    shared_ptr<HotelInfo> hotel_info;
    vector<QString> managerName;
    HotelStatus::STATUS status;
};

#endif // HOTEL_H
