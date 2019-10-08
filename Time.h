#ifndef FIRST_LAB_TIME_H
#define FIRST_LAB_TIME_H

#include "List.h"

template <typename T>
struct DT
{
    int year;
    int month;
    int day;
};

template <typename T>
struct TM
{
    int hour;
    int minute;
    int second;
};

//Клас для інформації про час
template <typename T>
class Time
{
private:
    TM<int> tm;
public:
    //Конструктор, який задає теперішній час
    Time();
    //функція для добавляння часу
    void add(int,int,int);
    //функція для створення рандомного моменту часу
    void random();
    //функція добавляння до часу певного моменту
    void plus_to_time(TM<T>);
    //функція віднімання від часу певного моменту
    void minus_to_time(TM<T>);
    //функція для виведення часу
    void print();
    void set_hour(int);
    void set_minute(int);
    void set_second(int);
    T get_hour();
    T get_minute();
    T get_second();

    //перегрузка операторів для класу Time
    friend bool operator== (Time<T> c1,Time<T> c2)
    {
        return (c1.get_hour()==c2.get_hour() && c1.get_minute()==c2.get_minute() && c1.get_second()==c2.get_second());
    }

    friend bool operator!= (Time<T> c1,Time<T> c2)
    {
        return (!(c1.get_hour()==c2.get_hour() && c1.get_minute()==c2.get_minute() && c1.get_second()==c2.get_second()));
    }

    friend bool operator > (Time<T> c1,Time<T> c2)
    {
        if (c1.get_hour()>c2.get_hour())
            return 1;
        if (c1.get_hour()==c2.get_hour() && c1.get_minute()>c2.get_minute())
            return 1;
        if (c1.get_hour()==c2.get_hour() && c1.get_minute()==c2.get_minute() && c1.get_second()>c2.get_second())
            return 1;
        return 0;
    }
    friend bool operator >= (Time<T> c1,Time<T> c2)
    {
        if (c1.get_hour()>c2.get_hour())
            return 1;
        if (c1.get_hour()==c2.get_hour() && c1.get_minute()>c2.get_minute())
            return 1;
        if (c1.get_hour()==c2.get_hour() && c1.get_minute()==c2.get_minute() && c1.get_second()>=c2.get_second())
            return 1;
        return 0;
    }
};

//Клас для інформації про дату
template <typename T>
class Date : public List<T>{
private:
    DT<int> dt;
public:
    //Конструктор, який задає теперішню дату
    Date();
    //функція для добавляння дати
    void add(int,int,int);
    //функція для виведення дати
    void print();
    void set_year(int);
    void set_month(int);
    void set_day(int);
    T get_year();
    T get_month();
    T get_day();
    //функція яка визначає день тижня
    void weekday();
    //функція для задання рандомної дати
    void random();
    //функція для визначення номера тижня в році
    void num_of_week_at_year();


    //перегрузка операторів для класу Date
    friend bool operator== (Date<T> c1,Date<T> c2)
    {
        return (c1.get_day()==c2.get_day() && c1.get_month()==c2.get_month() && c1.get_year()==c2.get_year());
    }

    friend bool operator!= (Date<T> c1,Date<T> c2)
    {
        return (!(c1.get_day()==c2.get_day() && c1.get_month()==c2.get_month() && c1.get_year()==c2.get_year()));
    }

    friend bool operator > (Date<T> c1,Date<T> c2)
    {
        if (c1.get_year()>c2.get_year())
            return 1;
        if (c1.get_year()==c2.get_year() && c1.get_month()>c2.get_month())
            return 1;
        if (c1.get_year()==c2.get_year() && c1.get_month()==c2.get_month() && c1.get_day()>c2.get_day())
            return 1;
        return 0;
    }
    friend bool operator >= (Date<T> c1,Date<T> c2)
    {
        if (c1.get_year()>c2.get_year())
            return 1;
        if (c1.get_year()==c2.get_year() && c1.get_month()>c2.get_month())
            return 1;
        if (c1.get_year()==c2.get_year() && c1.get_month()==c2.get_month() && c1.get_day()>=c2.get_day())
            return 1;
        return 0;
    }
};



#endif //FIRST_LAB_TIME_H
