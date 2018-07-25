#ifndef LOCATION_H
#define LOCATION_H

#include<QString>

class Location
{
public:
    Location(QString province,QString city,QString district)
        :province(province),city(city),district(district){}

    const QString& get_province(){return province;}
    const QString& get_city(){return city;}
    const QString& get_district(){return district;}

private:
    QString province;
    QString city;
    QString district;

};

#endif // LOCATION_H
