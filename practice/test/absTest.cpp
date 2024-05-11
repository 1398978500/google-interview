#include <iostream>

using namespace std;

int myAbs(int a) {
    const int bit31 = a >> 31;
    return (a ^ bit31) - bit31;
}

float myAbs(float f) {

    int casted = *(int*)&f;
    casted &= 0x7fffffff;

    return *(float*)&casted;
}

int main(int argc, char* argv[]) {
    cout << myAbs(-2.2f) << endl;
    cout << myAbs(-2) << endl;

    return 0;
}

