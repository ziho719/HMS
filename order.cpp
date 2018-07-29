#include "order.h"


Order::Order(QString user, QString hotel, QString roomType, double money)
    :user(user),hotel(hotel),roomType(roomType),money(money)
{
    status=STATUS::pending_pay;
}

const QString &Order::get_user()
{
    return user;
}

const QString &Order::get_hotel()
{
    return hotel;
}

const QString &Order::get_roomType()
{
    return roomType;
}

double Order::get_money()
{
    return money;
}

void Order::edit_user(const QString &u)
{
    user=u;
}

void Order::edit_hotel(const QString &h)
{
    hotel=h;
}

void Order::edit_roomType(const QString &r)
{
    roomType=r;
}

void Order::edit_money(const double &m)
{
    money=m;
}

void Order::change_status_to_checking_payment()
{
    status=STATUS::checking_payment;
}

void Order::change_status_to_pending_checkin()
{
    status=STATUS::pending_checkin;
}

void Order::change_status_to_pending_comment()
{
    status=STATUS::pending_comment;
}

void Order::change_status_to_have_refund()
{
    status=STATUS::have_refund;
}

void Order::change_status_to_have_cancel()
{
    status=STATUS::have_cancel;
}

void Order::change_status_to_done()
{
    status=STATUS::done;
}

QString Order::get_status()
{
    if(status==STATUS::pending_pay) return "pending_pay";
    else if(status==STATUS::checking_payment) return "checking_payment";
    else if(status==STATUS::pending_checkin) return "pending_checkin";
    else if(status==STATUS::pending_comment) return "pending_comment";
    else if(status==STATUS::have_refund) return "have_refund";
    else if(status==STATUS::have_cancel) return "have_cancel";
    else if(status==STATUS::done) return "done";
    else {
        qDebug()<<"order get status mistake";
        return "NULL";
    }
}
