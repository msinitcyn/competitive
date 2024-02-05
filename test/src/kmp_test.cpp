#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "../../src/kmp.cpp"

TEST(KMP_Tests, PrefixFunctionTest) {

    std::string s = "aabbaabbc";
    std::vector<int> expected = {0,1,0,0,1,2,3,4,0};

    std::vector<int> actual = prefix_function(s);

    EXPECT_EQ(expected, actual);
}

TEST(KMP_Tests, FindTest) {

    std::string s = "abacbcabcabbabc";
    std::string pattern = "abc";

    int actual = find(s, pattern);

    EXPECT_EQ(6, actual);
}
