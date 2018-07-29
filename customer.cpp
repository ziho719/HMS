#include "customer.h"


QString Customer::get_phone()
{
    return phone;
}

void Customer::edit_phone(const QString &newPhone)
{
    phone=newPhone;
}

QString Customer::userType()
{
    return "customer";
}

