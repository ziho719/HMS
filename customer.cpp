#include "customer.h"


const QString &Customer::get_phone()
{
    return phone;
}

void Customer::edit_phone(const QString &newPhone)
{
    phone=newPhone;
}
