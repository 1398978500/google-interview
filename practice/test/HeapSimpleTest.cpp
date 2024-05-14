#include <gtest/gtest.h>
#include <iostream>

#include "Heap.h"

using namespace std;
using namespace lw;

TEST(TEST_HEAP, SORT) {
    HeapSimple<int> h({ 4, 2, 3, 8 });

    h.show();
    EXPECT_EQ(h[0], 8);

    h.insert(6);
    h.show();
    EXPECT_EQ(h[0], 8);

    h.heapSort();
    h.show();
    EXPECT_EQ(h[0], 2);

    h.heapify();
    h.show();
}

int main(int argc, char const* argv[]) {
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
