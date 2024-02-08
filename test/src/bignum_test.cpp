#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "../../src/bignum.cpp"

class CompareTwoNumbersTest : public testing::TestWithParam<std::tuple<std::string, std::string, int>> {
};

TEST_P(CompareTwoNumbersTest, CompareStrings) {
    std::string s1 = std::get<0>(GetParam());
    std::string s2 = std::get<1>(GetParam());
    int expected = std::get<2>(GetParam());

    BigNum a(s1);
    BigNum b(s2);

    int result = compare(a, b);

    EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(BigNum_Tests, CompareTwoNumbersTest,
    testing::Values(
        std::make_tuple("123", "321", -1),
        std::make_tuple("1", "1", 0),
        std::make_tuple("1111", "333", 1)
    )
);

class AddTwoNumbersTest : public testing::TestWithParam<std::tuple<std::string, std::string, std::string>> {
};

TEST_P(AddTwoNumbersTest, AddStrings) {
    std::string s1 = std::get<0>(GetParam());
    std::string s2 = std::get<1>(GetParam());
    std::string expected = std::get<2>(GetParam());

    BigNum a(s1);
    BigNum b(s2);

    BigNum result = add(a, b);

    EXPECT_EQ(result.to_string(), expected);
}

INSTANTIATE_TEST_SUITE_P(BigNum_Tests, AddTwoNumbersTest,
    testing::Values(
        std::make_tuple("123", "321", "444"),
        std::make_tuple("99999999999999999999", "1", "100000000000000000000"),
        std::make_tuple("1", "99999999999999999999", "100000000000000000000"),
        std::make_tuple("1111", "333", "1444")
    )
);

class SubtractTwoNumbersTest : public testing::TestWithParam<std::tuple<std::string, std::string, std::string>> {
};

TEST_P(SubtractTwoNumbersTest, SubtractStrings) {
    std::string s1 = std::get<0>(GetParam());
    std::string s2 = std::get<1>(GetParam());
    std::string expected = std::get<2>(GetParam());

    BigNum a(s1);
    BigNum b(s2);

    BigNum result = subtract(a, b);

    EXPECT_EQ(result.to_string(), expected);
}

INSTANTIATE_TEST_SUITE_P(BigNum_Tests, SubtractTwoNumbersTest,
    testing::Values(
        std::make_tuple("444", "321", "123"),
        std::make_tuple("100000000000000000000", "99999999999999999999", "1"),
        std::make_tuple("100000000000000000000", "1", "99999999999999999999"),
        std::make_tuple("1111", "333", "778")
    )
);
