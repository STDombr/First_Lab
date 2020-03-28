#include <iostream>
#include <ctime>
#include <gtest/gtest.h>

using namespace std;

int main()
{
    //srand(time(0));
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    //menu();
}