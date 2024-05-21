# 记录一些有意思的函数


```
// 对数:向上取整
template<typename T>
constexpr T log2(T x) {
    return x <= 1 ? 0 : 1 + log2(x >> 1);
}
```
```
// 求N的倍数中大于X的最小的值
template<size_t N, typename X>
constexpr X nb(X x) {
    static_assert((N & (N - 1)) == 0, "N must be power of 2");
    return (x >> log2(static_cast<X>(N))) + !!(x & static_cast<X>(N - 1));
}

```

```
#include <iostream>

using namespace std;

class alignas(8) A{};

int main(int argc, char* argv[]) {
    // 空类加上alignas后大小不再是1
    cout << alignof(A) << endl; // 8
    cout << sizeof(A)<<endl;    // 8

    return 0;
}

```
