#include <gtest/gtest.h>
#include <soundex/soundex.h>

TEST(soundex, soundex_hash)
{
    EXPECT_EQ("A261", libcsc::soundex_hash("Ashcraft"));
    EXPECT_EQ("A261", libcsc::soundex_hash("Ashcroft"));
    EXPECT_EQ("B620", libcsc::soundex_hash("Burroughs"));
    EXPECT_EQ("B620", libcsc::soundex_hash("Burrows"));
    EXPECT_EQ("C532", libcsc::soundex_hash("Ciondecks"));
    EXPECT_EQ("E460", libcsc::soundex_hash("Ellery"));
    EXPECT_EQ("E460", libcsc::soundex_hash("Euler"));
    EXPECT_EQ("E251", libcsc::soundex_hash("Example"));
    EXPECT_EQ("G200", libcsc::soundex_hash("Gauss"));
    EXPECT_EQ("G200", libcsc::soundex_hash("Ghosh"));
    EXPECT_EQ("H416", libcsc::soundex_hash("Heilbronn"));
    EXPECT_EQ("H416", libcsc::soundex_hash("Hilbert"));
    EXPECT_EQ("K530", libcsc::soundex_hash("Knuth"));
    EXPECT_EQ("L300", libcsc::soundex_hash("Ladd"));
    EXPECT_EQ("L222", libcsc::soundex_hash("Lissajous"));
    EXPECT_EQ("L300", libcsc::soundex_hash("Lloyd"));
    EXPECT_EQ("L222", libcsc::soundex_hash("Lukasiewicz"));
    EXPECT_EQ("T522", libcsc::soundex_hash("Tymczak"));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}