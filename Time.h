#ifndef FIRST_LAB_TIME_H
#define FIRST_LAB_TIME_H


class Time {
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
public:
    Time();
    void add(int,int,int,int,int,int);
    void print();
};


#endif //FIRST_LAB_TIME_H
