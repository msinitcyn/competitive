#include <gtest/gtest.h>
#include "../../src/dsu.cpp"

TEST(DSU_Tests, TwoItemsTest) {
    DSU dsu(2);

    int a = dsu.find(0);
    int b = dsu.find(1);

    EXPECT_NE(a, b);

    dsu.union_sets(0, 1);

    a = dsu.find(0);
    b = dsu.find(1);

    EXPECT_EQ(a, b);
}

TEST(DSU_Tests, PairsOfItemsTest) {
    DSU dsu(4);
    
    dsu.union_sets(0,1);
    dsu.union_sets(2,3);

    EXPECT_EQ(dsu.find(0), dsu.find(1));
    EXPECT_EQ(dsu.find(2), dsu.find(3));
    EXPECT_NE(dsu.find(0), dsu.find(2));
    EXPECT_NE(dsu.find(1), dsu.find(3));
}

TEST(DSU_Tests, MultipleItemsTest) {
    DSU dsu(5);
    
    dsu.union_sets(0,1);
    dsu.union_sets(2,3);
    dsu.union_sets(0, 4);

    EXPECT_EQ(dsu.find(4), dsu.find(1));
    EXPECT_NE(dsu.find(4), dsu.find(2));

    dsu.union_sets(3, 1);

    EXPECT_EQ(dsu.find(4), dsu.find(2));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
