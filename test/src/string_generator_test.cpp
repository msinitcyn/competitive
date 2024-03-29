#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "../../src/string_generator.cpp"

using std::vector;
using std::string;
using std::tuple;

class GenerateNumberStringsTest : public testing::TestWithParam<tuple<int, char, char, vector<string>>> {
};

vector<tuple<int, char, char, vector<string>>> GenerateTestData() {

    vector<tuple<int, char, char, vector<string>>> test_data;
    vector<string> expected_result = {"0"};
    test_data.push_back(make_tuple(1, '0', '0', expected_result));
    
    expected_result = {"000", "001", "010", "011", "100", "101", "110", "111"};
    test_data.push_back(make_tuple(3, '0', '1', expected_result));

    expected_result = {"55", "56", "57", "65", "66", "67", "75", "76", "77"};
    test_data.push_back(make_tuple(2, '5', '7', expected_result));

    expected_result = {"3333", "3334", "3343", "3344", "3433", "3434","3443","3444", "4333","4334","4343","4344","4433","4434","4443","4444"};
    test_data.push_back(make_tuple(4, '3', '4', expected_result));

    return test_data;
}

TEST_P(GenerateNumberStringsTest, GenerateNumberStrings) {
    int string_len = std::get<0>(GetParam());
    char low_digit = std::get<1>(GetParam());
    char high_digit = std::get<2>(GetParam());
    vector<string> expected = std::get<3>(GetParam());

    vector<string> actual = generate_number_strings(string_len, low_digit, high_digit);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(GenerateStrings_Tests, GenerateNumberStringsTest,
    testing::ValuesIn(GenerateTestData())
);
