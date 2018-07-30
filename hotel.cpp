#include "hotel.h"

Hotel::Hotel(const shared_ptr<HotelInfo> &p,const QString& mn)
{
    hotel_info=p;
    managerName=mn;
    status=unchecked;
}

void Hotel::change_status_to_unchecked()
{
    status=unchecked;
}

void Hotel::change_status_to_checked()
{
    status=checked;
}

QString Hotel::get_status()
{
    if(status==checked) return "checked";
    else if(status==unchecked) return "unchecked";
    else{
        qDebug()<<"status have some mistakes";
        return "NULL";
    }
}

const shared_ptr<HotelInfo> Hotel::get_hotel_info() const
{
    return hotel_info;
}

QString Hotel::getManagerName() const
{
    return managerName;
}
