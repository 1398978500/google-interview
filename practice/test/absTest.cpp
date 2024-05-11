#include <iostream>

using namespace std;

// int绝对值
int myAbs(int a) {
    const int bit31 = a >> 31;
    return (a ^ bit31) - bit31;
}

// float绝对值
float myAbs(float f) {

    int casted = *(int*)&f;
    casted &= 0x7fffffff;

    return *(float*)&casted;
}

// 异或交换两个int
void swapXor(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int main(int argc, char* argv[]) {
    cout << myAbs(-2.2f) << endl;
    cout << myAbs(-2) << endl;

    int a = 10;
    int b = 3;
    swapXor(a, b);
    cout << a << "  " << b << endl;

    return 0;
}

