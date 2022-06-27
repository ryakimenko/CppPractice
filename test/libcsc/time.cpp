#include <gtest/gtest.h>
#include <time/time.h>

TEST(timeTest, Time_TimeSpan)
{
    using namespace myTime::literals;

    myTime::TimeSpan ts1(1_m);
    myTime::TimeSpan ts2(30);
    myTime::Time time1(40_s);
    myTime::Time time2(30_s);

    std::cout << time1;

    EXPECT_EQ(30, (ts1 - ts2).getTime());
    EXPECT_EQ(90, (ts1 + ts2).getTime());

    EXPECT_EQ(100, (time1 + ts1).getTime());
    EXPECT_EQ(0, (time1 - ts1).getTime());
    EXPECT_EQ(10, (time1 - time2).getTime());
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}