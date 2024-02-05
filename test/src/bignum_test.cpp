#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "../../src/bignum.cpp"

TEST(BigNum_Tests, ToStringTest) {

    std::string s = "123456678901234567890123456789012345678901234567890";
    BigNum bigNum(s);

    EXPECT_EQ(s, bigNum.to_string());
}
