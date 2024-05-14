#include <gtest/gtest.h>
#include <iostream>

using namespace std;

// int绝对值
int myAbs(int a) {
    const int bit31 = a >> 31;
    return (a ^ bit31) - bit31;
}

// float绝对值
float myAbs(float f) {

    int casted = *( int* ) &f;
    casted &= 0x7fffffff;

    return *( float* ) &casted;
}

// 异或交换两个int
void swapXor(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

TEST(TEST_FLOAT, FLOAT_ABS) {
    float f1 = myAbs(-2.2f);
    cout << f1 << endl;
    EXPECT_FLOAT_EQ(f1, 2.2f);

    int i = myAbs(-10);
    EXPECT_EQ(i, 10);
}

TEST(TEST_SWAP, SWAP_XOR) {
    int a = 10;
    int b = 3;
    swapXor(a, b);
    cout << a << "  " << b << endl;
    EXPECT_EQ(a, 3);
    EXPECT_EQ(b, 10);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
