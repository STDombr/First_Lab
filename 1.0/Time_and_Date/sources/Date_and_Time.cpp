#include "Date_and_Time.h"
#include <iostream>
#include <windows.h>

Date_and_Time::Date_and_Time()
{

}
/**
    * function to data validation and add this data
     * @param t information of time
     * @param d information of date
     */
void Date_and_Time::add(Time t,Date d)
{
    T=t;
    D=d;
}
/**
     * function to print date and time in consol
     */
void Date_and_Time::print()
{
    T.print();
    D.print();
}

/**
     * function to safe entered time and date
     * @return 1 if valid time and date and 0 if invalid time and date
     */
int Date_and_Time::Enter_element() {
    std::cout << "hour minute second day month year: " << std::endl;
    int j = 0, i1, i2, i3;
    std::cin >> i1 >> i2 >> i3;
    if (i1 >= 0 && i1 < 24 &&
        i2 >= 0 && i2 < 60 &&
        i3 >= 0 && i3 < 60) {
        T.set_hour(i1);
        T.set_minute(i2);
        T.set_second(i3);
        j++;
    }
    std::cin >> i1 >> i2>> i3;
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (i2 <= 12 && i2 > 0 &&
        i3 >= 0) {
        int number_of_days = days[i2 - 1];
        if (i2 == 2 && (i3 % 4 == 0 && i3 % 100 != 0 || i3 % 400 == 0))
            number_of_days++;
        if (i1 > 0 && i1 <= number_of_days) {
            D.set_day(i1);
            D.set_month(i2);
            D.set_year(i3);
            j++;
        }


    }
    return j;
}
/**
     * function to safe yet date
     */
void Date_and_Time::yet_time_and_date()
{
    T.yet_time();
    D.yet_date();
}
/**
     * function to return class Time
     * @return Time
     */
Time Date_and_Time::getTime()
{
    return T;
}
/**
     * function to return class Date
     * @return Date
     */
Date Date_and_Time::getDate()
{
    return D;
}

/**
     * Creating information of random time and date
     */
void Date_and_Time::random()
{
    T.random();
    D.random();
}

/**
 * function to definition the difference about time1 and time2
 * @param a information of time1
 * @param b information of time2
 * @return difference about a and b
 */
DIFF difference(Date_and_Time a,Date_and_Time b)
{
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    DIFF t;
    if (a>b)
    {
        while (a.D.get_year()!=b.D.get_year())
        {
            t.days+=365;
            b.D.set_year(b.D.get_year()+1);
        }
        while (a.D.get_month()!=b.D.get_month())
            if (a.D.get_month()>b.D.get_month())
            {
                t.days+=days[b.D.get_month()-1]-b.D.get_day()+1;
                b.D.set_month(b.D.get_month()+1);
                b.D.set_day(1);
            } else
            {
                t.days-=days[a.D.get_month()-1]-a.D.get_day()+1;
                a.D.set_month(a.D.get_month()+1);
                a.D.set_day(1);
            }
            if(a.D.get_day()>b.D.get_day())
                t.days+=a.D.get_day()-b.D.get_day();
            else
                t.days-=b.D.get_day()-a.D.get_day();
        t.hours=a.T.get_hour()-b.T.get_hour();
        t.minutes=a.T.get_minute()-b.T.get_minute();
        t.seconds=a.T.get_second()-b.T.get_second();
        if (t.seconds<0)
        {
            t.seconds+=60;
            t.minutes--;
        }
        if (t.minutes<0)
        {
            t.minutes+=60;
            t.hours--;
        }
        if (t.hours<0)
        {
            t.hours+=24;
            t.days--;
        }
    } else
    {
        while (a.D.get_year()!=b.D.get_year())
        {
            t.days+=365;
            a.D.set_year(a.D.get_year()+1);
        }
        while (a.D.get_month()!=b.D.get_month())
            if (b.D.get_month()>a.D.get_month())
            {
                t.days+=days[a.D.get_month()-1]-a.D.get_day()+1;
                a.D.set_month(a.D.get_month()+1);
                a.D.set_day(1);
            } else
            {
                t.days-=days[b.D.get_month()-1]-b.D.get_day()+1;
                b.D.set_month(b.D.get_month()+1);
                b.D.set_day(1);
            }
        if(b.D.get_day()>a.D.get_day())
            t.days+=b.D.get_day()-a.D.get_day();
        else
            t.days-=a.D.get_day()-b.D.get_day();

        t.hours=b.T.get_hour()-a.T.get_hour();
        t.minutes=b.T.get_minute()-a.T.get_minute();
        t.seconds=b.T.get_second()-a.T.get_second();
        if (t.seconds<0)
        {
            t.seconds+=60;
            t.minutes--;
        }
        if (t.minutes<0)
        {
            t.minutes+=60;
            t.hours--;
        }
        if (t.hours<0)
        {
            t.hours+=24;
            t.days--;
        }
    }
    return t;
}

/**
 * calculate count of hours in difference
 * @param t difference
 */
void difference_in_hours(DIFF t)
{
    std::cout<<t.days*24+t.hours+((float)t.minutes/60)<<" hours"<<std::endl;
}

/**
 * calculate count of minutes in difference
 * @param t difference
 */
void difference_in_minutes(DIFF t)
{
    std::cout<<t.days*24*60+t.hours*60+t.minutes+((float)t.seconds/60)<<" minutes"<<std::endl;
}

/**
 * calculate count of seconds in difference
 * @param t difference
 */
void difference_in_seconds(DIFF t)
{
    std::cout<<t.days*24*3600+t.hours*3600+t.minutes*60+t.seconds<<" seconds"<<std::endl;
}
/**
 * calculate count of days in difference
 * @param t difference
 */
void difference_in_days(DIFF t)
{
    std::cout<<t.days+((float)t.hours/24)<<" days"<<std::endl;
}

/**
 * Operator == to compare two elements
 * @param c1 first element
 * @param c2 second element
 * @return 1 if c1==c2 and 0 if c1!=c2
 */
bool operator== (Date_and_Time c1,Date_and_Time c2)
{
    return (c1.T==c2.T && c1.D==c2.D);
}
/**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1!=c2 and 0 if c1==c2
    */
bool operator!= (Date_and_Time c1,Date_and_Time c2)
{
    return (!(c1.T==c2.T && c1.D==c2.D));
}
/**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1>c2 and 0 if c1<=c2
    */
bool operator > (Date_and_Time c1,Date_and_Time c2)
{
    if (c1.D>c2.D)
        return 1;
    else if (c1.D==c2.D && c1.T>c2.T)
        return 1;
    else
        return 0;
}
/**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1>=c2 and 0 if c1<c2
    */
bool operator >= (Date_and_Time c1,Date_and_Time c2)
{
    if (c1.D>c2.D)
        return 1;
    else if (c1.D==c2.D && c1.T>=c2.T)
        return 1;
    else
        return 0;
}

/**
     * function to minussing period time1 of saved time
     * @param t information of time1
     */
void Date_and_Time::minus_to_time(DIFF t)
{
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    T.set_second(T.get_second()-t.seconds);
    T.set_minute(T.get_minute()-t.minutes);
    T.set_hour(T.get_hour()-t.hours);
    if (T.get_second()<0)
    {
        T.set_second(T.get_second()+60);
        T.set_minute(T.get_minute()-1);
    }
    if (T.get_minute()<0)
    {
        T.set_minute(T.get_minute()+60);
        T.set_hour(T.get_hour()-1);
    }
    if (T.get_hour()<0)
    {
        T.set_hour(T.get_hour()+24);
        D.set_day(D.get_day()-1);
        if (D.get_day()<1)
        {
            D.set_month(D.get_month()-1);
            if (D.get_month()<1)
            {
                D.set_year(D.get_year()-1);
                D.set_month(12);
            }
            D.set_day(D.get_day()+days[D.get_month()-1]);
        }
    }
    for(int i=0;i<t.days;i++)
    {
        D.set_day(D.get_day()-1);
        if (D.get_day()<1)
        {
            D.set_month(D.get_month()-1);
            if (D.get_month()<1)
            {
                D.set_year(D.get_year()-1);
                D.set_month(12);
            }
            D.set_day(D.get_day()+days[D.get_month()-1]);
        }
    }
}

/**
 * function to adding period of time1 to saved time
 * @param t information of time1
 */
void Date_and_Time::plus_to_time(DIFF t)
{
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    T.set_second(T.get_second()+t.seconds);
    T.set_minute(T.get_minute()+T.get_second()/60);
    T.set_second(T.get_second()%60);
    T.set_hour(T.get_hour()+T.get_minute()/60);
    T.set_minute(T.get_minute()%60);
    if (T.get_hour()>23)
    {
        T.set_hour(T.get_hour()%24);
        t.days++;
    }
    for(int i=0;i<t.days;i++)
    {
        D.set_day(D.get_day()+1);
        if (D.get_day()>days[D.get_month()-1])
        {
            D.set_day(1);
            D.set_month(D.get_month()+1);
            if (D.get_month()>12)
            {
                D.set_month(1);
                D.set_year(D.get_year()+1);
            }

        }

    }
}