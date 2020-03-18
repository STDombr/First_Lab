/**
 * 2nd Course K-28
 * Lab 1. Variant 2-9
 * Task: make a class that realise such tasks:
 *      1)gives the information about the time.
 *      2)Adding period of time
 *      3)Minussing period of time
 *      4)Definition of Difference of time
 *
 * Purpose: contains declarations of methods of the class Time.
 *
 *@author Stanislav Dombrovskyi
 *@version 13/11/19
 */

#ifndef FIRST_LAB_TIMES_H
#define FIRST_LAB_TIMES_H

/**
 * Strucrure to store information of time
 */
struct TM
{
    int hour;
    int minute;
    int second;
};

/**
 * Structure that contains the structure TM with some methods
 */
class Time
{
private:
    TM tmm;
public:
    /**
     * Constructor to structure Date
     */
    Time();
    /**
    * function to time validation and add this time
    * @param hour_1 information of hour
     * @param minute_1 information of minute
     * @param second_1 information of second
     */
    void add(int hour_1,int minute_1,int second_1);
    /**
     * Creating information of random hour,minute,second
     */
    void random();

    /**
     * function to print date in consol
     */
    void print();
    /**
     * function to safe yet time
     */
    void yet_time();
    /**
     * safe information of hour
     * @param a information of hour
     */
    void set_hour(int a);
    /**
     * safe information of minute
     * @param a information of minute
     */
    void set_minute(int a);
    /**
     * safe information of second
     * @param a information of second
     */
    void set_second(int a);
    /**
 * function to adding period of time1 to saved time
 * @param t information of time1
 */
    void plus_to_time(TM t);

    /**
     * Returning information of hour
     * @return hour
     */
    int get_hour();
    /**
     * Returning information of minute
     * @return minute
     */
    int get_minute();
    /**
     * Returning information of second
     * @return second
     */
    int get_second();

    /**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1==c2 and 0 if c1!=c2
    */
    friend bool operator== (Time c1,Time c2);
    /**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1!=c2 and 0 if c1==c2
    */
    friend bool operator!= (Time c1,Time c2);
    /**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1>c2 and 0 if c1<=c2
    */
    friend bool operator > (Time c1,Time c2);
    /**
     * Operator == to compare two elements
    * @param c1 first element
    * @param c2 second element
    * @return 1 if c1>=c2 and 0 if c1<c2
    */
    friend bool operator >= (Time c1,Time c2);
};





#endif //FIRST_LAB_TIMES_H
