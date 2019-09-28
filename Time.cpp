#include <iostream>
#include <windows.h>
#include "Time.h"

int days[]={31,28,31,30,31,30,31,31,30,31,30,31};

/*Time::Time()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    year=st.wYear;
    month=st.wMonth;
    day=st.wDay;
    hour=st.wHour;
    minute=st.wMinute;
    second=st.wSecond;
}*/

/*bool leap(int y)
{
    if (y%4==0 && y%100!=0 || y%400==0)
        return 1;
    else
        return 0;
}*/

/*void Time::add(int year_1, int month_1, int day_1, int hour_1, int minute_1, int second_1)
{
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
            year=year_1;
            month=month_1;
            day=day_1;
            hour=hour_1;
            minute=minute_1;
            second=second_1;
            return;
        }
    }
    std::cout<<"Invalid date!";
}*/

void Time::print()
{
    std::cout<<day<<"."<<month<<"."<<year<<" "<<hour<<":"<<minute<<":"<<second;
}