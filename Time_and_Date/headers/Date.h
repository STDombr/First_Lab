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

#ifndef FIRST_LAB_DATE_H
#define FIRST_LAB_DATE_H

/**
 * Strucrure to store information of date
 */
struct DT
{
    int year;
    int month;
    int day;
};

/**
 * Structure that contains the structure DT with some methods
 */
class Date{
private:
    DT dt;
public:
    /**
     * Constructor to structure Date
     */
    Date();

    /**
    * function to data validation and add this data
    * @param day_1 information of day
     * @param month_1 information of month
     * @param year_1 information of year
     */
    void add(int day_1,int month_1,int year_1);
    /**
     * function to print date in consol
     */
    void print();
    /**
     * function to safe yet date
     */
    void yet_date();
    /**
     * safe information of day
     * @param a information of day
     */
    void set_year(int a);
    /**
     * safe information of day
     * @param a information of day
     */
    void set_month(int a);
    /**
     * safe information of day
     * @param a information of day
     */
    void set_day(int a);
    /**
     * Returning information of year
     * @return year
     */
    int get_year();

    /**
     * Returning information of year
     * @return year
     */
    int get_month();
    /**
     * Returning information of year
     * @return year
     */
    int get_day();
    /**
     * function to definition the weekday of date
     */
    void weekday();
    /**
     * Creating information of random day,month,year
     */
    void random();
    /**
     +* task
     *
     * function to definition number of week at year for the date
     */
    void num_of_week_at_year();


    /**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1==c2 and 0 if c1!=c2
    */
    friend bool operator== (Date c1,Date c2);
    /**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1!=c2 and 0 if c1==c2
    */
    friend bool operator!= (Date c1,Date c2);
    /**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1>c2 and 0 if c1<=c2
    */
    friend bool operator > (Date c1,Date c2);
    /**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1>=c2 and 0 if c1<c2
    */
    friend bool operator >= (Date c1,Date c2);
};


#endif //FIRST_LAB_DATE_H
