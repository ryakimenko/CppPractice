#include <gtest/gtest.h>
#include <smartptr/SharedPtr.h>
#include <smartptr/UniquePtr.h>

TEST(smartptr, UniquePtr_SharedPtr)
{
    libcsc::UniquePtr<int> uniqTest(new int(7));
    *uniqTest = *uniqTest + 10;
    EXPECT_EQ(17, *(uniqTest));

    uniqTest.reset(new int(2));
    EXPECT_EQ(2, *(uniqTest));

    libcsc::SharedPtr<int> sharTest1(new int(33));
    EXPECT_EQ(1, sharTest1.use_count());

    libcsc::SharedPtr<int> sharTest2(sharTest1);
    EXPECT_EQ(2, sharTest2.use_count());

    *sharTest1 += 10;
    EXPECT_EQ(43, *(sharTest2.get()));

    sharTest1.reset(new int(888));
    EXPECT_EQ(1, sharTest1.use_count());
    EXPECT_EQ(1, sharTest2.use_count());

    sharTest2.reset(new int(2));

    auto&& sp = libcsc::SharedPtr<int>(std::move(sharTest2));
    EXPECT_EQ(2, *sp);
    EXPECT_EQ(nullptr, sharTest2.get());
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}