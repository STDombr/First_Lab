#ifndef FIRST_LAB_DATE_H
#define FIRST_LAB_DATE_H

struct DT
{
    int year;
    int month;
    int day;
};

//Клас для інформації про дату
class Date{
private:
    DT dt;
public:
    //Конструктор, який задає теперішню дату
    Date();
    //функція для добавляння дати
    void add(int,int,int);
    //функція для виведення дати
    void print();
    int Enter_element();
    void yet_date();
    void set_year(int);
    void set_month(int);
    void set_day(int);
    int get_year();
    int get_month();
    int get_day();
    //функція яка визначає день тижня
    void weekday();
    //функція для задання рандомної дати
    void random();
    //функція для визначення номера тижня в році
    void num_of_week_at_year();


    //перегрузка операторів для класу Date
    friend bool operator== (Date,Date);
    friend bool operator!= (Date,Date);
    friend bool operator > (Date,Date);
    friend bool operator >= (Date,Date);
};


#endif //FIRST_LAB_DATE_H
