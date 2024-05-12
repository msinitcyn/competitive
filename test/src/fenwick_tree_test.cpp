#include <gtest/gtest-param-test.h>
#include <vector>
#include <gtest/gtest.h>
#include "../../src/fenwick_tree.cpp"

using std::tuple;
using std::make_tuple;
using std::vector;
using std::get;

class FenwickTreeSumTest : public testing::TestWithParam<tuple<vector<int>, int, int>> {
};

TEST_P(FenwickTreeSumTest, SumTest) {
    vector<int> data = get<0>(GetParam());
    int idx = get<1>(GetParam());
    int expected = get<2>(GetParam());

    Fenwick fenwick(data);
    int actual = fenwick.sum(idx);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(FenwickTree_Tests, FenwickTreeSumTest,
    testing::Values(
        make_tuple<vector<int>, int, int>({1,2,3,4,5}, 0, 1),
        make_tuple<vector<int>, int, int>({1,2,3,4,5}, 1, 3),
        make_tuple<vector<int>, int, int>({1,2,3,4,5}, 2, 6),
        make_tuple<vector<int>, int, int>({1,2,3,4,5}, 3, 10),
        make_tuple<vector<int>, int, int>({1,2,3,4,5}, 4, 15)
    )
);

class FenwickTreeAddTest : public testing::TestWithParam<tuple<vector<int>, int, int, int, int>> {
};

TEST_P(FenwickTreeAddTest, AddTest) {
    vector<int> data = get<0>(GetParam());
    int idx_to_update = get<1>(GetParam());
    int value = get<2>(GetParam());
    int idx_to_sum = get<3>(GetParam());
    int expected = get<4>(GetParam());

    Fenwick fenwick(data);
    fenwick.add(idx_to_update, value);

    int actual = fenwick.sum(idx_to_sum);
    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(FenwickTree_Tests, FenwickTreeAddTest,
    testing::Values(
        make_tuple<vector<int>, int, int, int, int>({1,2,3,4,5}, 0, 1, 1, 4),
        make_tuple<vector<int>, int, int, int, int>({1,2,3,4,5}, 1, 4, 3, 14),
        make_tuple<vector<int>, int, int, int, int>({1,2,3,4,5}, 4, 4, 4, 19)
    )
);
