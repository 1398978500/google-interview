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

```
#include <iostream>

using namespace std;

// 类完美转发的一种用法

class Base {
public:
    Base() = default;

    virtual ~Base() = default;

    virtual void run() = 0;

};

template<typename F>
class Derived : public Base {
public:
    Derived(F&& f) : _f(forward<F>(f)) {}

    virtual ~Derived() = default;

    virtual void run() {
        _f();
    }

private:
    typename remove_reference<F>::type _f;
};

template<typename F>
class Derivedp : public Base {
public:
    Derivedp(F* f) : _f(f) {}

    virtual ~Derivedp() = default;

    virtual void run() {
        (*_f)();
    }

private:
    typename remove_reference<F>::type* _f;
};

// 调用run
template<typename F>
void run(F&& f) {
    cout << "F&& f  " << endl;
    Base* base = new Derived<F>(forward<F>(f));
    base->run();
}

template<typename F>
void run(F* f) {
    cout << "F* f " << endl;
    Base* base = new Derivedp<F>(f);
    base->run();
}

void f0() {
    cout << "f0 " << endl;
}

int main(int argc, char* argv[]) {
    // 调用 run(F* f)
    run(f0);

    // 调用 run(F&& f)
    run([]() {
        cout << "[]() {}" << endl;
            });

    return 0;
}
```


