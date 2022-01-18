

#include "MData.h"
#include <iostream>
#include <cstdlib>

MData::MData(int year,int month,int day) {
    this->year=year;
    this->month=month;
    this->day=day;

    if(czy_zerowac(year,month,day)) {
        this->year = 0;
        this->month = 0;
        this->day = 0;
    }

}

int MData::czy_zerowac(int year,int month,int day) {
    if (year<1)
        return 1;
    if (month<1 || month >12)
        return 1;
    if (checkifdaysgood(year,month)< day || day < 1)
        return 1;

    return 0;
}
void MData::to_String(){
    std::cout<<"YYYY-MM-DD"<<std::endl;
    std::cout<<year<<"-"<<month<<"-"<<day<<std::endl;
}
int MData::checkifprzestepny(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}
int MData::checkifdaysgood(int year,int month) {
    //styczen
    if (month == 1)
        return 31;
    //luty
    if (month == 2) {
        return checkifprzestepny(year) ? 29 : 28;
    }
    //marzec
    if (month == 3)
        return 31;
    //kwieceien
    if (month == 4)
        return 30;
    // maj
    if (month == 5)
        return 31;
    // czerwiec
    if (month == 6)
        return 30;
    // lipiec
    if (month == 7)
        return 31;
    // sierpien
    if (month == 8)
        return 31;
    // wrzesien
    if (month == 9)
        return 30;
    // pazdzernik
    if (month == 10)
        return 31;
    //listopad
    if (month == 11)
        return 30;
    // grudzien
    if (month == 12)
        return 31;

    return 0;
}
MData MData::operator+(const MData &v) {
    int a=0,b=0,c=0;

    if(this->day+v.day>checkifdaysgood(this->year, this->month)) {
        a = abs((this->day + v.day)-checkifdaysgood(this->year, this->month));
        b+1;
    } else
        a=this->day+v.day;

    if((this->month+v.month)>12) {
        b += ((abs(this->month + v.month))-12);
        c++;
    }else
        b+=this->month + v.month;

    c+=(this->year+v.year);


    return MData(this->year=c, this->month=b, this->day=a);
}

MData MData::operator+=(int i) {
    int pomi =i;
    int pomy= this->year;
    pomi += to_days(helpdate(this->year), this->month, this->day);

    while (pomi>y_to_day(pomy))
    {
        pomi-=y_to_day(pomy);
        pomy++;
    }
    while (pomi <=0)
    {
        pomy--;
        pomi +=y_to_day(pomy);
    }

    int pom2;
    while ((pom2=pomi-checkifdaysgood(this->year, this->month))>0)
    {
        pomi=pom2;
        this->month++;
    }
    return MData(pomy, this->month, pomi);
}
int MData::y_to_day(int year) {
    return 365+helpdate(year);
}
int MData::helpdate(int year) {
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}
int MData::to_days(int leap,int month,int day) {
    for (int i = month - 2; i >= 0; i--) {
        day +=checkifdaysgood(this->year, this->month);
    }
    return day;
}


