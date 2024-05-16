#include <gtest/gtest.h>
#include <iostream>

#include "Sort.h"

using namespace lw;
using namespace std;

void showVec(const vector<int>& v) {
    for(int i : v) {
        cout << i << "  ";
    }
    cout << endl;
}

// gtest判断一个vector是否有序(升序)
void exceptVectorIsSorted(vector<int>& v) {
    for(int i = 1; i < v.size(); i++) {
        EXPECT_LE(v[i - 1], v[i]);
    }
}

TEST(TEST_SORT, MERGE) {
    vector<int> v{ 325432, 989,  547510, 3,    -93, 189019, 5042, 123,   597, 42,
                   7506,   184,  184,    2409, 45,  824,    4,    -2650, 9,   662,
                   3928,   -170, 45358,  395,  842, 7697,   110,  14,    99,  221 };

    mergeSort(v, 0, v.size() - 1);

    showVec(v);
    exceptVectorIsSorted(v);
}

TEST(TEST_SORT, QUICK) {
    vector<int> v{ 325432, 989,  547510, 3,    -93, 189019, 5042, 123,   597, 42,
                   7506,   184,  184,    2409, 45,  824,    4,    -2650, 9,   662,
                   3928,   -170, 45358,  395,  842, 7697,   110,  14,    99,  221 };

    quickSort(v, 0, v.size() - 1);

    showVec(v);
    exceptVectorIsSorted(v);
}

TEST(TEST_SORT, SELECT) {
    vector<int> v{ 325432, 989,  547510, 3,    -93, 189019, 5042, 123,   597, 42,
                   7506,   184,  184,    2409, 45,  824,    4,    -2650, 9,   662,
                   3928,   -170, 45358,  395,  842, 7697,   110,  14,    99,  221 };

    selectSort(v);

    showVec(v);
    exceptVectorIsSorted(v);
}

TEST(TEST_SORT, INSERT) {
    vector<int> v{ 325432, 989,  547510, 3,    -93, 189019, 5042, 123,   597, 42,
                   7506,   184,  184,    2409, 45,  824,    4,    -2650, 9,   662,
                   3928,   -170, 45358,  395,  842, 7697,   110,  14,    99,  221 };

    insertSort(v);

    showVec(v);
    exceptVectorIsSorted(v);
}

TEST(TEST_SORT, BUBBLE) {
    vector<int> v{ 325432, 989,  547510, 3,    -93, 189019, 5042, 123,   597, 42,
                   7506,   184,  184,    2409, 45,  824,    4,    -2650, 9,   662,
                   3928,   -170, 45358,  395,  842, 7697,   110,  14,    99,  221 };

    bubbleSort(v);

    showVec(v);
    exceptVectorIsSorted(v);
}

int main(int argc, char const* argv[]) {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
