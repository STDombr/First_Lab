#ifndef FIRST_LAB_DATE_AND_TIME_H
#define FIRST_LAB_DATE_AND_TIME_H

#include "Times.h"
#include "Date.h"

/**
 * Strucrure to store information of time
 */
struct DIFF
{
    int days=0;
    int hours=0;
    int minutes=0;
    int seconds=0;
};

class Date_and_Time {
public:
    Date D;
    Time T;

    Date_and_Time();

    /**
    * function to data validation and add this data
     * @param t information of time
     * @param d information of date
     */
    void add(Time t,Date d);
/**
     * function to print date and time in consol
     */
    void print();
    /**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1==c2 and 0 if c1!=c2
    */

    /**
     * function to safe entered time
     * @return 1 if valid time and 0 if invalid time
     */
    int Enter_element();
    /**
     * function to safe yet date
     */
    void yet_time_and_date();
    /**
     * function to return class Time
     * @return Time
     */
    Time getTime();
    /**
     * function to return class Date
     * @return Date
     */
    Date getDate();
    /**
     * Creating information of random time and date
     */
    void random();

    /**
     * function to adding period of time1 to saved time
     * @param t information of time1
     */
    void plus_to_time(DIFF t);
    /**
     * function to minussing period time1 of saved time
     * @param t information of time1
     */
    void minus_to_time(DIFF t);

    /**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1!=c2 and 0 if c1==c2
    */
    friend bool operator== (Date_and_Time c1,Date_and_Time c2);
    /**
     * Operator != to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1!=c2 and 0 if c1==c2
    */
    friend bool operator!= (Date_and_Time c1,Date_and_Time c2);
    /**
     * Operator > to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1>c2 and 0 if c1<=c2
    */
    friend bool operator > (Date_and_Time c1,Date_and_Time c2);
    /**
     * Operator >= to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1>=c2 and 0 if c1<c2
    */
    friend bool operator >= (Date_and_Time c1,Date_and_Time c2);
};

/**
 * function to definition the difference about time1 and time2
 * @param a information of time1
 * @param b information of time2
 * @return difference about a and b
 */
DIFF difference(Date_and_Time a,Date_and_Time b);
/**
 * calculate count of seconds in difference
 * @param t difference
 */
void difference_in_seconds(DIFF t);
/**
 * calculate count of minutes in difference
 * @param t difference
 */
void difference_in_minutes(DIFF t);
/**
 * calculate count of hours in difference
 * @param t difference
 */
void difference_in_hours(DIFF t);
/**
 * calculate count of days in difference
 * @param t difference
 */
void difference_in_days(DIFF t);


#endif //FIRST_LAB_DATE_AND_TIME_H
