#ifndef FIRST_LAB_TIME_H
#define FIRST_LAB_TIME_H

#include "List.h"

template <typename T>
class Time : public List<T>{
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
public:
    Time();
    void add(int,int,int,int,int,int);
    void print();
    void set_year(int);
    void set_month(int);
    void set_day(int);
    void set_hour(int);
    void set_minute(int);
    void set_second(int);
};


#endif //FIRST_LAB_TIME_H
