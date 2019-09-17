#include <iostream>

using namespace std;

struct date
{
    int day;
    int month;
    int year;
};

class List
{
private:
    date array_of_date[100];
    int i=-1;
public:
    void Add_date(int date_day,int date_month,int date_year)
    {
        i++;
        array_of_date[i].day=date_day;
        array_of_date[i].month=date_month;
        array_of_date[i].year=date_year;
    }
    void Print_one_date(int j)
    {
        if (j<=i)
        {
            cout << array_of_date[j].day << ".";
            cout << array_of_date[j].month << ".";
            cout << array_of_date[j].year;
            cout << endl;
        } else
            cout<<"Error"<<endl;
    }
    void Print_all_date()
    {
        for (int j=0;j<=i;j++)
            Print_one_date(j);
    }

};

int main()
{
    List Time;
    Time.Add_date(7,6,2001);
    Time.Print_all_date();
}