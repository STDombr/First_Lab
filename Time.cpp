#include <iostream>
#include <windows.h>
#include "Time.h"

template <typename T>
Time<T>::Time()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    year=st.wYear;
    month=st.wMonth;
    day=st.wDay;
    hour=st.wHour;
    minute=st.wMinute;
    second=st.wSecond;
}

template <typename T>
void Time<T>::add(int day_1, int month_1, int year_1, int hour_1, int minute_1, int second_1)
{

    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
if (hour_1>=0 && hour_1<24 &&
        minute_1>=0 && minute_1<60 &&
        second_1>=0 && second_1<60 &&
        month_1<=12 && month_1>0 &&
        year_1>=0)
    {
        int number_of_days=days[month_1-1];
        if (month_1==2 && (year_1%4==0 && year_1%100!=0 || year_1%400==0))
            number_of_days++;
        if (day_1>0 && day_1<=number_of_days)
        {
            set_year(year_1);
            set_month(month_1);
            set_day(day_1);
            set_hour(hour_1);
            set_minute(minute_1);
            set_second(second_1);
            return;
        }
    }
    std::cout<<"Invalid date!";
}

template <typename T>
void Time<T>::print()
{
    if (day/10==0)
        std::cout<<"0";
    std::cout<<day<<".";
    if (month/10==0)
        std::cout<<"0";
    std::cout<<month<<".";
    std::cout<<year<<" ";
    if (hour/10==0)
        std::cout<<"0";
    std::cout<<hour<<":";
    if (minute/10==0)
        std::cout<<"0";
    std::cout<<minute<<":";
    if (second/10==0)
        std::cout<<"0";
    std::cout<<second;
}

template <typename T>
void Time<T>::set_year(int a)
{
    this->year=a;
}

template <typename T>
void Time<T>::set_month(int a)
{
    this->month=a;
}

template <typename T>
void Time<T>::set_day(int a)
{
    this->day=a;
}

template <typename T>
void Time<T>::set_hour(int a)
{
    this->hour=a;
}

template <typename T>
void Time<T>::set_minute(int a)
{
    this->minute=a;
}

template <typename T>
void Time<T>::set_second(int a)
{
    this->second=a;
}