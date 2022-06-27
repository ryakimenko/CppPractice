#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <list/list.h>

TEST(TestList, LoopTrue)
{
    libcsc::myList<int> list;
    for (int i = 0; i < 10; i++) {
        list.push_back(i);
    }
    list.make_loop(2);
    EXPECT_EQ(true, list.check_loop());
}

TEST(TestList, LoopFalse)
{
    libcsc::myList<int> list;
    for (int i = 0; i < 10; i++) {
        list.push_back(i);
    }
    EXPECT_EQ(false, list.check_loop());
}

TEST(TestList, EmptyTrue)
{
    libcsc::myList<int> list;
    EXPECT_EQ(true, list.is_empty());
}

TEST(TestList, EmptyFalse)
{
    libcsc::myList<int> list;
    for (int i = 0; i < 10; i++) {
        list.push_back(i);
    }
    EXPECT_EQ(false, list.is_empty());
}

TEST(TestList, Iterator)
{
    libcsc::myList<int> list;
    for (int i = 0; i < 10; i++) {
        list.push_back(i);
    }
    int j;
    auto i = list.begin();
    for (j = 0; i != list.end(); i++, j++) {
        EXPECT_EQ(j, i->data_);
    }
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}