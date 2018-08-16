#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSql>
#include "system.h"

//数据库有关的函数集，只在开始、结束调用

namespace Database {

bool connect(QSqlDatabase &db);

void write_all();  //调用这个
void read_all();

void write_hotel();  //一个函数一个表
void write_room();
void write_comment();
void write_user();   //这个写三个表（其实一个也行）
void write_order();
void write_hotelmanager();


void read_hotel();
void read_room();
void read_comment();
void read_user();
void read_order();
void read_hotelmanager();
}



#endif // DATABASE_H
