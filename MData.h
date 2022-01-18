
#ifndef KALENDARIUM_MDATA_H
#define KALENDARIUM_MDATA_H
#include <iostream>

class MData {
    int day,month,year;
public:
    MData(int year,int month,int day);
    int czy_zerowac(int year,int month,int day);
    void to_String();
    int checkifprzestepny(int year);
    int checkifdaysgood(int year,int month);
    MData operator +(const MData &v);
    MData operator +=(int i);
    int y_to_day(int year);
    int helpdate(int year);
    int to_days(int leap,int month,int day);
};


#endif //KALENDARIUM_MDATA_H
