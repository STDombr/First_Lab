#include <iostream>
#include <ctime>
#include <gtest/gtest.h>
#include "Test.cpp"
#include <QtWidgets/QApplication>
#include "mainwindow.h"

using namespace std;

List<int> ListInt;
List<double> ListDouble;
List<std::string> ListString;
List<Date_and_Time> ListDate;

int main(int argc, char* argv[])
{
   srand(time(0));
   int temp;
   cout<<"1 - to run Google Tests"<<endl;
    cout<<"2 - to run QT interface"<<endl;
    cin>>temp;
    if (temp == 1)
    {
        ::testing::InitGoogleTest();
        return RUN_ALL_TESTS();
    }
    else if (temp == 2)
    {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }

    return 0;
}
