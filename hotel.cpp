#include "hotel.h"

Hotel::Hotel(shared_ptr<HotelInfo> p, const vector<QString> &mn)
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

void Hotel::change_status_to_changed()
{
    status=changed;
}

void Hotel::change_status_to_unpassed()
{
    status=unpassed;
}

QString Hotel::get_status()
{
    if(status==checked) return "checked";
    else if(status==unchecked) return "unchecked";
    else if(status==changed) return "changed";
    else if(status==unpassed) return "unpassed";
    else{
        qDebug()<<"status have some mistakes";
        return "NULL";
    }
}

shared_ptr<HotelInfo> &Hotel::get_hotel_info()
{
    return hotel_info;
}

const vector<QString> &Hotel::get_manager()
{
    return managerName;
}

bool Hotel::is_manager(QString name)
{
    for(auto m:managerName){
        if(m==name) return true;
    }
    return false;
}

bool Hotel::add_manager(QString name)
{
    auto s=System::getSystem();
    if(s->find_manager(name)==NULL){
        return false;
    }
    else if(is_manager(name)){
        return false;
    }
    else
    {
        managerName.push_back(name);
        return true;
    }
}

