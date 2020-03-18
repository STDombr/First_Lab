/**
 * 2nd Course K-28
 * Lab 1. Variant 2-9
 * Task: make a class that realise such tasks:
 *      1)gives the information about the date.
 *      2)determines the day of the week by date
 +* task
 *      determines the week number for the date
 * Purpose: contains declarations of methods of the class Date.
 *
 *@author Stanislav Dombrovskyi
 *@version 13/11/19
 */

#include <iostream>
#include <windows.h>
#include <ctime>
#include "Date.h"

/**
 * function to definition the weekday of date
 */
void Date::weekday()
{
    std::string s[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int code_of_month=dt.month+12*((14-dt.month)/12)-2;
    int code_of_year=dt.year-(14-dt.month)/12;
    std::cout<<s[(7000+(dt.day+code_of_year+code_of_year/4-code_of_year/100+code_of_year/400+(31*code_of_month)/12))%7]<<std::endl;
}

/**
     * Constructor to structure Date
     */
Date::Date()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    dt.year=st.wYear;
    dt.month=st.wMonth;
    dt.day=st.wDay;
}

/**
 * function to data validation and add this data
 * @param day_1 information of day
 * @param month_1 information of month
 * @param year_1 information of year
 */
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

/**
 * function to print date in consol
 */
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

/**
 * function to safe yet date
 */
void Date::yet_date()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    dt.year=st.wYear;
    dt.month=st.wMonth;
    dt.day=st.wDay;
}


/**
 * safe information of day
 * @param a information of day
 */
void Date::set_day(int a)
{
    dt.day=a;
}

/**
 * safe information of day
 * @param a information of day
 */
void Date::set_month(int a)
{
    dt.month=a;
}

/**
 * safe information of day
 * @param a information of day
 */
void Date::set_year(int a)
{
    dt.year=a;
}

/**
 * Returning information of year
 * @return year
 */
int Date::get_year()
{
    return dt.year;
}

/**
 * Returning information of month
 * @return month
 */
int Date::get_month()
{
    return dt.month;
}

/**
 * Returning information of day
 * @return day
 */
int Date::get_day()
{
    return dt.day;
}

/**
 * Creating information of random day,month,year
 */
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

/**
 * function to definition number of week at year for the date
 */
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


/**
 * Operator == to compare two elements
 * @param c1 first element
 * @param c2 second element
 * @return 1 if c1==c2 and 0 if c1!=c2
 */
bool operator== (Date c1,Date c2)
{
    return (c1.get_day()==c2.get_day() && c1.get_month()==c2.get_month() && c1.get_year()==c2.get_year());
}
/**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1!=c2 and 0 if c1==c2
    */
bool operator!= (Date c1,Date c2)
{
    return (!(c1.get_day()==c2.get_day() && c1.get_month()==c2.get_month() && c1.get_year()==c2.get_year()));
}
/**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1>c2 and 0 if c1<=c2
    */
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
/**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1>=c2 and 0 if c1<c2
    */
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