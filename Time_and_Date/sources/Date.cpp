#include <iostream>
#include <windows.h>
#include <ctime>
#include "Date.h"

//функція яка визначає день тижня
void Date::weekday()
{
    std::string s[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int code_of_month=dt.month+12*((14-dt.month)/12)-2;
    int code_of_year=dt.year-(14-dt.month)/12;
    std::cout<<s[(7000+(dt.day+code_of_year+code_of_year/4-code_of_year/100+code_of_year/400+(31*code_of_month)/12))%7]<<std::endl;
}

//Конструктор, який задає теперішню дату
Date::Date()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    dt.year=st.wYear;
    dt.month=st.wMonth;
    dt.day=st.wDay;
}

//функція для добавляння дати та часу
void Date::add(int day_1, int month_1, int year_1)
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
void Date::print()
{
    if (dt.day/10==0)
        std::cout<<"0";
    std::cout<<dt.day<<".";
    if (dt.month/10==0)
        std::cout<<"0";
    std::cout<<dt.month<<".";
    std::cout<<dt.year<<" ";
}

void Date::set_day(int a)
{
    dt.day=a;
}

void Date::set_month(int a)
{
    dt.month=a;
}

void Date::set_year(int a)
{
    dt.year=a;
}

int Date::get_year()
{
    return dt.year;
}

int Date::get_month()
{
    return dt.month;
}

int Date::get_day()
{
    return dt.day;
}

//функція для задання рандомної дати
void Date::random()
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
void Date::num_of_week_at_year()
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


//перегрузка операторів для класу Date
bool operator== (Date c1,Date c2)
{
    return (c1.get_day()==c2.get_day() && c1.get_month()==c2.get_month() && c1.get_year()==c2.get_year());
}

bool operator!= (Date c1,Date c2)
{
    return (!(c1.get_day()==c2.get_day() && c1.get_month()==c2.get_month() && c1.get_year()==c2.get_year()));
}

bool operator > (Date c1,Date c2)
{
    if (c1.get_year()>c2.get_year())
        return 1;
    if (c1.get_year()==c2.get_year() && c1.get_month()>c2.get_month())
        return 1;
    if (c1.get_year()==c2.get_year() && c1.get_month()==c2.get_month() && c1.get_day()>c2.get_day())
        return 1;
    return 0;
}
bool operator >= (Date c1,Date c2)
{
    if (c1.get_year()>c2.get_year())
        return 1;
    if (c1.get_year()==c2.get_year() && c1.get_month()>c2.get_month())
        return 1;
    if (c1.get_year()==c2.get_year() && c1.get_month()==c2.get_month() && c1.get_day()>=c2.get_day())
        return 1;
    return 0;
}