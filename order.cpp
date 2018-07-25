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
    if(status==STATUS::pending_pay) return "待付款";
    else if(status==STATUS::checking_payment) return "正在确认付款";
    else if(status==STATUS::pending_checkin) return "待入住";
    else if(status==STATUS::pending_comment) return "待评论";
    else if(status==STATUS::have_refund) return "已退款";
    else if(status==STATUS::have_cancel) return "订单已取消";
    else if(status==STATUS::done) return "感谢使用";
    else {
        qDebug()<<"order get status mistake";
        return "NULL";
    }
}
