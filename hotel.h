#ifndef HOTEL_H
#define HOTEL_H

#include"hotelinfo.h"
#include<memory>
#include<QDebug>

using namespace std;

namespace HotelStatus {
    enum STATUS{
        unchecked,
        checked,
    };
}
using HotelStatus::checked;
using HotelStatus::unchecked;

class Hotel
{
public:
    Hotel(const shared_ptr<HotelInfo>& p,const QString& mn);

    void change_status_to_unchecked();
    void change_status_to_checked();
    QString get_status();

    const shared_ptr<HotelInfo> get_hotel_info() const;

private:
    shared_ptr<HotelInfo> hotel_info;
    QString managerName;
    HotelStatus::STATUS status;
};

#endif // HOTEL_H
