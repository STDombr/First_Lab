#include <iostream>
#include <windows.h>
#include "Time.h"
#include <ctime>

//Конструктор, який задає теперішній час
template <typename T>
Time<T>::Time()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    tm.hour=st.wHour;
    tm.minute=st.wMinute;
    tm.second=st.wSecond;
    TM<int> t;
    t.second=0;
    t.minute=0;
    t.hour=3;
    plus_to_time(t);
}

//функція для добавляння часу
template <typename T>
void Time<T>::add(int hour_1, int minute_1, int second_1)
{
    if (hour_1>=0 && hour_1<24 &&
        minute_1>=0 && minute_1<60 &&
        second_1>=0 && second_1<60)
    {
        set_hour(hour_1);
        set_minute(minute_1);
        set_second(second_1);
        return;
    }
    std::cout<<"Invalid date!";
}

//функція добавляння до часу певного моменту
template <typename T>
void Time<T>::plus_to_time(TM<T> t)
{
    tm.second+=t.second;
    tm.minute+=t.minute+tm.second/60;
    tm.second%=60;
    tm.hour+=t.hour+tm.minute/60;
    tm.minute%=60;
    tm.hour%=24;
}

//функція для створення рандомного моменту часу
template <typename T>
void Time<T>::random()
{
    tm.hour=rand()%24;
    tm.minute=rand()%60;
    tm.second=rand()%60;
}

//функція відніманнявід часу певного моменту
template <typename T>
void Time<T>::minus_to_time(TM<T> t)
{
    tm.second-=t.second;
    tm.minute-=t.minute;
    tm.hour-=t.hour;
    if (tm.second<0)
    {
        tm.second+=60;
        tm.minute--;
    }
    if (tm.minute<0)
    {
        tm.minute+=60;
        tm.hour--;
    }
    tm.hour=(tm.hour+24)%24;
}

//функція для виведення часу
template <typename T>
void Time<T>::print()
{
    if (tm.hour/10==0)
        std::cout<<"0";
    std::cout<<tm.hour<<":";
    if (tm.minute/10==0)
        std::cout<<"0";
    std::cout<<tm.minute<<":";
    if (tm.second/10==0)
        std::cout<<"0";
    std::cout<<tm.second<<" ";
}

template <typename T>
void Time<T>::set_hour(int a)
{
    tm.hour=a;
}

template <typename T>
void Time<T>::set_minute(int a)
{
    tm.minute=a;
}

template <typename T>
void Time<T>::set_second(int a)
{
    tm.second=a;
}

//визначення різниці між моментами часу
template <typename T>
TM<T> difference(Time<T> a,Time<T> b)
{
    TM<int> t;
    if (a>b)
    {
        t.hour=a.get_hour()-b.get_hour();
        t.minute=a.get_minute()-b.get_minute();
        t.second=a.get_second()-b.get_second();
        if (t.second<0)
        {
            t.second+=60;
            t.minute--;
        }
        if (t.minute<0)
        {
            t.minute+=60;
            t.hour--;
        }
    } else
    {
        t.hour=b.get_hour()-a.get_hour();
        t.minute=b.get_minute()-a.get_minute();
        t.second=b.get_second()-a.get_second();
        if (t.second<0)
        {
            t.second+=60;
            t.minute--;
        }
        if (t.minute<0)
        {
            t.minute+=60;
            t.hour--;
        }
    }
    return t;
}

//представлення різниці між моментами часу в годинах
template <typename T>
void difference_in_hours(TM<T> t)
{
    std::cout<<(t.hour+(float)(t.second+t.minute*60)/3600)<<" hours"<<std::endl;
}

//представлення різниці між моментами часу в хвилинах
template <typename T>
void difference_in_minutes(TM<T> t)
{
    std::cout<<t.hour*60+t.minute+((float)t.second/60)<<" minutes"<<std::endl;
}

//представлення різниці між моментами часу в секундах
template <typename T>
void difference_in_seconds(TM<T> t)
{
    std::cout<<t.hour*3600+t.minute*60+t.second<<" seconds"<<std::endl;
}

template <typename T>
T Time<T>::get_hour()
{
    return tm.hour;
}
template <typename T>
T Time<T>::get_minute()
{
    return tm.minute;
}
template <typename T>
T Time<T>::get_second()
{
    return tm.second;
}

//функція яка визначає день тижня
template <typename T>
void Date<T>::weekday()
{
    std::string s[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int code_of_month=dt.month+12*((14-dt.month)/12)-2;
    int code_of_year=dt.year-(14-dt.month)/12;
    std::cout<<s[(7000+(dt.day+code_of_year+code_of_year/4-code_of_year/100+code_of_year/400+(31*code_of_month)/12))%7]<<std::endl;
}

//Конструктор, який задає теперішню дату
template <typename T>
Date<T>::Date()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    dt.year=st.wYear;
    dt.month=st.wMonth;
    dt.day=st.wDay;
}

//функція для добавляння дати та часу
template <typename T>
void Date<T>::add(int day_1, int month_1, int year_1)
{

    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (month_1<=12 && month_1>0 &&
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
            return;
        }
    }
    std::cout<<"Invalid date!";
}

//функція для виведення дати
template <typename T>
void Date<T>::print()
{
    if (dt.day/10==0)
        std::cout<<"0";
    std::cout<<dt.day<<".";
    if (dt.month/10==0)
        std::cout<<"0";
    std::cout<<dt.month<<".";
    std::cout<<dt.year<<" ";
}

template <typename T>
void Date<T>::set_day(int a)
{
    dt.day=a;
}

template <typename T>
void Date<T>::set_month(int a)
{
    dt.month=a;
}

template <typename T>
void Date<T>::set_year(int a)
{
    dt.year=a;
}

template <typename T>
T Date<T>::get_year()
{
    return dt.year;
}
template <typename T>
T Date<T>::get_month()
{
    return dt.month;
}
template <typename T>
T Date<T>::get_day()
{
    return dt.day;
}

//функція для задання рандомної дати
template <typename T>
void Date<T>::random()
{
    time_t currTime = time(0);
    tm *ltm = std::localtime(&currTime);
    ltm->tm_mday = std::rand() % 3650 * -1;
    time_t next = mktime(ltm);
    ltm = std::localtime(&next);
    dt.year=ltm->tm_year + 1900;
    dt.month=ltm->tm_mon + 1;
    dt.day=ltm->tm_mday;
}

//функція для визначення номера тижня в році
template <typename T>
void Date<T>::num_of_week_at_year()
{
    time_t rowTime = time(0);
    tm* ptm = localtime(&rowTime);
    ptm->tm_year = dt.year - 1900;
    ptm->tm_mday=dt.day;
    ptm->tm_mon=dt.month;
    ptm->tm_mon -= 1;
    mktime(ptm);
    int wNum = (ptm->tm_yday + 1) / 7;
    if((ptm->tm_yday + 1) % 7) ++wNum;
    std::cout << wNum <<std::endl;
}