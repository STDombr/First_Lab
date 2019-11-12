#ifndef FIRST_LAB_TIMES_H
#define FIRST_LAB_TIMES_H

struct TM
{
    int hour;
    int minute;
    int second;
};

//Клас для інформації про час
class Time
{
private:
    TM tmm;
public:
    //Конструктор, який задає теперішній час
    Time();
    //функція для добавляння часу
    void add(int,int,int);
    //функція для створення рандомного моменту часу
    void random();
    //функція добавляння до часу певного моменту
    void plus_to_time(TM);
    //функція віднімання від часу певного моменту
    void minus_to_time(TM);
    //функція для виведення часу
    void print();
    void set_hour(int);
    void set_minute(int);
    void set_second(int);
    int get_hour();
    int get_minute();
    int get_second();

    //перегрузка операторів для класу Time
    friend bool operator== (Time,Time);
    friend bool operator!= (Time,Time);
    friend bool operator > (Time,Time);
    friend bool operator >= (Time,Time);
};

void difference_in_seconds(TM);
void difference_in_minutes(TM);
void difference_in_hours(TM);
TM difference(Time,Time);


#endif //FIRST_LAB_TIMES_H
