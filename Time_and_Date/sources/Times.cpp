#include <iostream>
#include <windows.h>
#include "Times.h"
#include <ctime>

//Конструктор, який задає теперішній час
Time::Time()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    tmm.hour=st.wHour;
    tmm.minute=st.wMinute;
    tmm.second=st.wSecond;
    TM t;
    t.second=0;
    t.minute=0;
    t.hour=2;
    plus_to_time(t);
}

//функція для добавляння часу
void Time::add(int hour_1, int minute_1, int second_1)
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
void Time::plus_to_time(TM t)
{
    tmm.second+=t.second;
    tmm.minute+=t.minute+tmm.second/60;
    tmm.second%=60;
    tmm.hour+=t.hour+tmm.minute/60;
    tmm.minute%=60;
    tmm.hour%=24;
}

//функція для створення рандомного моменту часу
void Time::random()
{
    tmm.hour=rand()%24;
    tmm.minute=rand()%60;
    tmm.second=rand()%60;
}

//функція відніманнявід часу певного моменту
void Time::minus_to_time(TM t)
{
    tmm.second-=t.second;
    tmm.minute-=t.minute;
    tmm.hour-=t.hour;
    if (tmm.second<0)
    {
        tmm.second+=60;
        tmm.minute--;
    }
    if (tmm.minute<0)
    {
        tmm.minute+=60;
        tmm.hour--;
    }
    tmm.hour=(tmm.hour+24)%24;
}

void Time::yet_time()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    tmm.hour=st.wHour;
    tmm.minute=st.wMinute;
    tmm.second=st.wSecond;
    TM t;
    t.second=0;
    t.minute=0;
    t.hour=2;
    plus_to_time(t);
}

int Time::Enter_element()
{
    std::cout<<"hour minute second: "<<std::endl;
    int i1,i2,i3;
    std::cin>>i1>>i2>>i3;
    if (i1>=0 && i1<24 &&
        i2>=0 && i2<60 &&
        i3>=0 && i3<60)
    {
        add(i1,i2,i3);
        return 1;
    }
    return 0;

}

//функція для виведення часу
void Time::print()
{
    if (tmm.hour/10==0)
        std::cout<<"0";
    std::cout<<tmm.hour<<":";
    if (tmm.minute/10==0)
        std::cout<<"0";
    std::cout<<tmm.minute<<":";
    if (tmm.second/10==0)
        std::cout<<"0";
    std::cout<<tmm.second<<" ";
}

void Time::set_hour(int a)
{
    tmm.hour=a;
}

void Time::set_minute(int a)
{
    tmm.minute=a;
}

void Time::set_second(int a)
{
    tmm.second=a;
}

//визначення різниці між моментами часу
TM difference(Time a,Time b)
{
    TM t;
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
void difference_in_hours(TM t)
{
    std::cout<<(t.hour+(float)(t.second+t.minute*60)/3600)<<" hours"<<std::endl;
}

//представлення різниці між моментами часу в хвилинах
void difference_in_minutes(TM t)
{
    std::cout<<t.hour*60+t.minute+((float)t.second/60)<<" minutes"<<std::endl;
}

//представлення різниці між моментами часу в секундах
void difference_in_seconds(TM t)
{
    std::cout<<t.hour*3600+t.minute*60+t.second<<" seconds"<<std::endl;
}

int Time::get_hour()
{
    return tmm.hour;
}

int Time::get_minute()
{
    return tmm.minute;
}


int Time::get_second()
{
    return tmm.second;
}

bool operator== (Time c1,Time c2)
{
    return (c1.get_hour()==c2.get_hour() && c1.get_minute()==c2.get_minute() && c1.get_second()==c2.get_second());
}

bool operator!= (Time c1,Time c2)
{
    return (!(c1.get_hour()==c2.get_hour() && c1.get_minute()==c2.get_minute() && c1.get_second()==c2.get_second()));
}

bool operator > (Time c1,Time c2)
{
    if (c1.get_hour()>c2.get_hour())
        return 1;
    if (c1.get_hour()==c2.get_hour() && c1.get_minute()>c2.get_minute())
        return 1;
    if (c1.get_hour()==c2.get_hour() && c1.get_minute()==c2.get_minute() && c1.get_second()>c2.get_second())
        return 1;
    return 0;
}
bool operator >= (Time c1,Time c2)
{
    if (c1.get_hour()>c2.get_hour())
        return 1;
    if (c1.get_hour()==c2.get_hour() && c1.get_minute()>c2.get_minute())
        return 1;
    if (c1.get_hour()==c2.get_hour() && c1.get_minute()==c2.get_minute() && c1.get_second()>=c2.get_second())
        return 1;
    return 0;
}