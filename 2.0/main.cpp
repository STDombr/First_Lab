#include <iostream>
#include <ctime>
#include <gtest/gtest.h>
#include "Test.cpp"
#include <QtWidgets/QApplication>
#include "mainwindow.h"
#include <chrono>

using namespace std;

List<double> L1;
Array<double> L2;
Vector<double> L3;

int main(int argc, char *argv[])
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
   /*
   List<int> Test;

    auto begin = std::chrono::steady_clock::now();
    Test.random();
    auto end = std::chrono::steady_clock::now();

    std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()<<std::endl;*/
   return 0;
}
