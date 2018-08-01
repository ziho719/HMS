#ifndef LOCATION_H
#define LOCATION_H

#include<QString>
#include<QRegExp>

class Location
{
public:
    Location(QString province,QString city,QString district)
        :province(province),city(city),district(district){}
    Location()
        :province(""),city(""),district(""){}

    const QString& get_province() const{return province;}
    const QString& get_city() const{return city;}
    const QString& get_district() const{return district;}

    void set_province(const QString p)   {province=p;}
    void set_city(const QString c)        {city=c;}
    void set_district(const QString d)  {district=d;}

    bool match(QString loca)
    {
        QRegExp r("\\w*"+loca+"\\w*");
        if(r.exactMatch(province+city+district))
            return true;
        else return false;
    }

private:
    QString province;
    QString city;
    QString district;

};

#endif // LOCATION_H


