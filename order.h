#ifndef ORDER_H
#define ORDER_H

#include<QString>
#include<QDebug>

using namespace std;
namespace OrderStatus {
    enum STATUS{
        pending_pay, //未付款
        checking_payment,
        pending_checkin, //未入住
        pending_comment, //待评论
        have_refund,  //已退款
        have_cancel,  //已取消订单
        done, //全部完成
    };
}
using OrderStatus::STATUS;


class Order
{
public:
    Order(QString user,QString hotel,QString roomType,double money);

    const QString & get_user();
    const QString & get_hotel();
    const QString & get_roomType();
          double    get_money();

    //可能不会使用（确实没有使用，订单一下达就不应该更改了，但保留）
    void edit_user(const QString& u);
    void edit_hotel(const QString& h);
    void edit_roomType(const QString& r);
    void edit_money(const double& m) ;

    void change_status_to_checking_payment();
    void change_status_to_pending_checkin();
    void change_status_to_pending_comment();
    void change_status_to_have_refund();
    void change_status_to_have_cancel();
    void change_status_to_done();

    QString get_status();
private:
    QString user;
    QString hotel;
    QString roomType;
    double money;

    OrderStatus::STATUS status;
};

#endif // ORDER_H
