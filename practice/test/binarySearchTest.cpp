#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

// 找到val在v中最左边的下标
int binarySearchL(vector<int>& v, int val) {
    int i = 0, j = v.size() - 1;

    while(i < j) {
        int mid = i + j >> 1;
        if(v[mid] >= val) {
            j = mid;
        }
        else {
            i = mid + 1;
        }
    }

    if(v[i] != val) {
        return -1;
    }

    return i;
}

// 找到val在v中最右边的下标
int binarySearchR(vector<int>& v, int val) {
    int i = 0, j = v.size() - 1;

    while(i < j) {
        int mid = i + j + 1 >> 1;
        if(v[mid] <= val) {
            i = mid;
        }
        else {
            j = mid - 1;
        }
    }

    if(v[i] != val) {
        return -1;
    }

    return i;
}

void test(vector<int>& v, int num, int l, int r) {
    int lIndex = binarySearchL(v, num);
    EXPECT_EQ(l, lIndex);
    cout << "要查找的数字" << num << endl;
    cout << "左下标: " << l << "  " << lIndex << endl;
    int rIndex = binarySearchR(v, num);
    EXPECT_EQ(r, rIndex);
    cout << "右下标" << r << "  " << rIndex << endl;
}

TEST(TEST_BINARY, SEARCH) {
    vector<int> v{ 2, 2, 3, 3, 4, 4, 4, 5, 5 };
    sort(v.begin(), v.end());

    for(int i : v) {
        cout << i << " < ";
    }
    cout << endl;

    test(v, 2, 0, 1);
    test(v, 3, 2, 3);
    test(v, 4, 4, 6);
    test(v, 5, 7, 8);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
