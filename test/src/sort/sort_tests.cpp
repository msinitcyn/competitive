#include <gtest/internal/gtest-type-util.h>
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "../../../src/sort/bubble_sort.cpp"
#include "../../../src/sort/insertion_sort.cpp"
#include "../../../src/sort/selection_sort.cpp"
#include "../../../src/sort/quick_sort.cpp"
#include "../../../src/sort/merge_sort.cpp"
#include "../../../src/sort/heap_sort.cpp"

using std::string;
using std::vector;

template <typename T>
class SortFixture : public ::testing::Test {
public:
    vector<vector<T>> get_initial_data();
    vector<vector<T>> get_expected_data();
};

template <>
vector<vector<int>> SortFixture<int>::get_initial_data() {
    return {
        {5, 2, 3, 1, 4},
        {1}
    };
}

template <>
vector<vector<int>> SortFixture<int>::get_expected_data() {
    return {
        {1, 2, 3, 4, 5},
        {1}
    };
}

template <>
vector<vector<string>> SortFixture<string>::get_initial_data() {
    return {{"apple", "orange", "banana", "pear"}};
}

template <>
vector<vector<string>> SortFixture<string>::get_expected_data() {
    return {{"apple", "banana", "orange", "pear"}};
}

template <>
vector<vector<char>> SortFixture<char>::get_initial_data() {
    return {{'d', 'a', 'c', 'b'}};
}

template <>
vector<vector<char>> SortFixture<char>::get_expected_data() {
    return {{'a', 'b', 'c', 'd'}};
}

template <>
vector<vector<float>> SortFixture<float>::get_initial_data() {
    return {{5.1f, 2.2f, 3.3f, 1.1f, 4.4f}};
}

template <>
vector<vector<float>> SortFixture<float>::get_expected_data() {
    return {{1.1f, 2.2f, 3.3f, 4.4f, 5.1f}};
}

using type_to_test = ::testing::Types<int, string, char, float>;
TYPED_TEST_SUITE(SortFixture, type_to_test);

TYPED_TEST(SortFixture, BubbleSortTest) {
    vector<vector<TypeParam>> initial_data = this->get_initial_data();
    vector<vector<TypeParam>> expected_data = this->get_expected_data();

    for (int i = 0; i < initial_data.size(); ++i) {
        bubble_sort<TypeParam>(initial_data[i]);
        ASSERT_EQ(initial_data[i], expected_data[i]);
    }
}

TYPED_TEST(SortFixture, InsertionSortTest) {
    vector<vector<TypeParam>> initial_data = this->get_initial_data();
    vector<vector<TypeParam>> expected_data = this->get_expected_data();

    for (int i = 0; i < initial_data.size(); ++i) {
        insertion_sort<TypeParam>(initial_data[i]);
        ASSERT_EQ(initial_data[i], expected_data[i]);
    }
}

TYPED_TEST(SortFixture, SelectionSortTest) {
    vector<vector<TypeParam>> initial_data = this->get_initial_data();
    vector<vector<TypeParam>> expected_data = this->get_expected_data();

    for (int i = 0; i < initial_data.size(); ++i) {
        selection_sort<TypeParam>(initial_data[i]);
        ASSERT_EQ(initial_data[i], expected_data[i]);
    }
}

TYPED_TEST(SortFixture, QuickSortTest) {
    vector<vector<TypeParam>> initial_data = this->get_initial_data();
    vector<vector<TypeParam>> expected_data = this->get_expected_data();

    for (int i = 0; i < initial_data.size(); ++i) {
        quick_sort<TypeParam>(initial_data[i]);
        ASSERT_EQ(initial_data[i], expected_data[i]);
    }
}

TYPED_TEST(SortFixture, MergeSortTest) {
    vector<vector<TypeParam>> initial_data = this->get_initial_data();
    vector<vector<TypeParam>> expected_data = this->get_expected_data();

    for (int i = 0; i < initial_data.size(); ++i) {
        merge_sort<TypeParam>(initial_data[i]);
        ASSERT_EQ(initial_data[i], expected_data[i]);
    }
}

TYPED_TEST(SortFixture, HeapSortTest) {
    vector<vector<TypeParam>> initial_data = this->get_initial_data();
    vector<vector<TypeParam>> expected_data = this->get_expected_data();

    for (int i = 0; i < initial_data.size(); ++i) {
        heap_sort<TypeParam>(initial_data[i]);
        ASSERT_EQ(initial_data[i], expected_data[i]);
    }
}
