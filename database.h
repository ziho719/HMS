#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSql>
#include "system.h"
namespace Database {

bool connect(QSqlDatabase &db);

void write_all();
void read_all();

void write_hotel();  //一个函数一个表
void write_room();
void write_comment();
void write_user();   //这个写三个表
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
