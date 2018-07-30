#ifndef HOTEL_H
#define HOTEL_H

#include"hotelinfo.h"
#include<memory>
#include<QDebug>
#include <vector>
#include "system.h"

using namespace std;

namespace HotelStatus {
    enum STATUS{
        unchecked,
        changed,
        checked,
    };
}
using HotelStatus::checked;
using HotelStatus::unchecked;
using HotelStatus::changed;

class HotelInfo;

class Hotel
{
public:
    Hotel(shared_ptr<HotelInfo> p,const vector<QString>& mn);

    void change_status_to_unchecked();
    void change_status_to_checked();
    void change_status_to_changed();
    QString get_status();

    shared_ptr<HotelInfo> get_hotel_info();

    const vector<QString>& get_manager();
    bool is_manager(QString name);
    bool add_manager(QString name);

private:
    shared_ptr<HotelInfo> hotel_info;
    vector<QString> managerName;
    HotelStatus::STATUS status;
};

#endif // HOTEL_H
