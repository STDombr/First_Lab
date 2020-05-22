#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "Array.cpp"
#include "List.cpp"
#include "Vector.cpp"

class ListTest : public ::testing::Test{
protected:
    virtual void SetUp(){
        l_2.add(1);
        l_2.add(2);
        l_2.add(3);
        l_2.add(4);
        l_2.add(5);
        l_3.random();
        l_4.random();
        l_5.random();
    }

    List<int> l_1;
    List<int> l_2;
    List<int> l_3;
    List<std::string> l_4;
    List<Date_and_Time> l_5;
};

TEST_F(ListTest, IsEmpty) {
    EXPECT_EQ(0,l_1.GetSize());
}

TEST_F(ListTest, PopWorks) {
    l_2.popTail();
    EXPECT_EQ(4,l_2.GetSize());
    l_2.popHead();
    EXPECT_EQ(3,l_2.GetSize());
    int n=l_2.popHead();
    EXPECT_EQ(2,n);
    n=l_2.popTail();
    EXPECT_EQ(4,n);
}

TEST_F(ListTest, RemoveWorks) {
    l_1.remove();
    l_2.remove();
    EXPECT_EQ(0,l_1.GetSize());
    EXPECT_EQ(0,l_2.GetSize());
}

TEST_F(ListTest, SortWorks) {
    l_3.heapsort();
    int n=l_3.GetSize();
    for(int i=0;i<n-1;i++)
        ASSERT_LE(l_3.element(i),l_3.element(i+1));

    l_4.quicksort();
    n=l_4.GetSize();
    for(int i=0;i<n-1;i++)
        ASSERT_LE(l_4.element(i),l_4.element(i+1));

    l_5.selectionsort();
    n=l_5.GetSize();
    for(int i=0;i<n-1;i++)
        ASSERT_TRUE(l_5.element(i)<=l_5.element(i+1));
}

class ArrayTest : public ::testing::Test{
protected:
    virtual void SetUp(){
        a_2.add(1);
        a_2.add(2);
        a_2.add(3);
        a_2.add(4);
        a_2.add(5);
        a_3.random();
        a_4.random();
        a_5.random();
    }

    Array<int> a_1;
    Array<int> a_2;
    Array<int> a_3;
    Array<std::string> a_4;
    Array<Date_and_Time> a_5;
};

TEST_F(ArrayTest, IsEmpty) {
    EXPECT_EQ(0,a_1.GetSize());
}

TEST_F(ArrayTest, PopWorks) {
    a_2.popTail();
    EXPECT_EQ(4,a_2.GetSize());
    a_2.popHead();
    EXPECT_EQ(3,a_2.GetSize());
    int n=a_2.popHead();
    EXPECT_EQ(2,n);
    n=a_2.popTail();
    EXPECT_EQ(4,n);
}

TEST_F(ArrayTest, RemoveWorks) {
    a_1.remove();
    a_2.remove();
    EXPECT_EQ(0,a_1.GetSize());
    EXPECT_EQ(0,a_2.GetSize());
}

TEST_F(ArrayTest, SortWorks) {
    a_3.heapsort();
    int n=a_3.GetSize();
    for(int i=0;i<n-1;i++)
        ASSERT_LE(a_3.element(i),a_3.element(i+1));

    a_4.quicksort();
    n=a_4.GetSize();
    for(int i=0;i<n-1;i++)
        ASSERT_LE(a_4.element(i),a_4.element(i+1));

    a_5.selectionsort();
    n=a_5.GetSize();
    for(int i=0;i<n-1;i++)
        ASSERT_TRUE(a_5.element(i)<=a_5.element(i+1));
}

class VectorTest : public ::testing::Test{
protected:
    virtual void SetUp(){
        v_2.add(1);
        v_2.add(2);
        v_2.add(3);
        v_2.add(4);
        v_2.add(5);
        v_3.random();
        v_4.random();
        v_5.random();
    }

    Vector<int> v_1;
    Vector<int> v_2;
    Vector<int> v_3;
    Vector<std::string> v_4;
    Vector<Date_and_Time> v_5;
};

TEST_F(VectorTest, IsEmpty) {
    EXPECT_EQ(0,v_1.GetSize());
}

TEST_F(VectorTest, PopWorks) {
    v_2.popTail();
    EXPECT_EQ(4,v_2.GetSize());
    v_2.popHead();
    EXPECT_EQ(3,v_2.GetSize());
    int n=v_2.popHead();
    EXPECT_EQ(2,n);
    n=v_2.popTail();
    EXPECT_EQ(4,n);
}

TEST_F(VectorTest, RemoveWorks) {
    v_1.remove();
    v_2.remove();
    EXPECT_EQ(0,v_1.GetSize());
    EXPECT_EQ(0,v_2.GetSize());
}

TEST_F(VectorTest, SortWorks) {
    v_3.heapsort();
    int n=v_3.GetSize();
    for(int i=0;i<n-1;i++)
        ASSERT_LE(v_3.element(i),v_3.element(i+1));

    v_4.quicksort();
    n=v_4.GetSize();
    for(int i=0;i<n-1;i++)
        ASSERT_LE(v_4.element(i),v_4.element(i+1));

    v_5.selectionsort();
    n=v_5.GetSize();
    for(int i=0;i<n-1;i++)
        ASSERT_TRUE(v_5.element(i)<=v_5.element(i+1));
}
