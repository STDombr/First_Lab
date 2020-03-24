#include <iostream>
#include <ctime>
//#include "Test.cpp"
#include "Tests.cpp"

using namespace std;

class ListTest : public ::testing::Test{
protected:
    virtual void SetUp(){
        l_2.add(1);
        l_2.add(2);
    }

    List<int> l_1;
    List<int> l_2;
};

TEST_F(ListTest, IsEmpty) {
    EXPECT_EQ(0,l_1.GetSize());
}


/*TEST(BasicTests, TestName) {
    List<int> L1;
    L1.add(123);
    EXPECT_EQ(123,L1.element(0));
}*/

int main()
{
    //srand(time(0));
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    //menu();
}