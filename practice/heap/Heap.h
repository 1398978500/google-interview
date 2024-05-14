#pragma once

#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::swap;
using std::vector;

namespace lw {

// 简单堆实现(使用vector) 大根堆
template <class T>
class HeapSimple {
public:
    HeapSimple() {}
    HeapSimple(const vector<T>& inData);
    HeapSimple(vector<T>&& inData);
    ~HeapSimple() {}

    // 堆化一下
    void heapify();
    // 堆排序
    void heapSort();
    // 上浮
    void up(int iIndex);
    // 下沉
    void down(int iIndex, int iSize);
    // 插入数据
    void insert(const T& val);

    // 获取最大值并删掉最大值
    T popMax();
    // 移除下标是iIndex的元素
    void remove(int iIndex);

    void show();

    size_t getSize() {
        return data.size();
    }
    bool isEmpty() {
        return data.empty();
    }
    T getMax() {
        T t;
        if(!data.empty()) {
            t = data[0];
        }
        return t;
    }
    T& operator[](int iIndex) {
        if(iIndex < 0 || iIndex > data.size()) {
            cerr << "error iIndex : " << iIndex << endl;
            exit(EXIT_FAILURE);
        }

        return data[iIndex];
    }

private:
    vector<T> data;
};

template <class T>
HeapSimple<T>::HeapSimple(const vector<T>& inData)
    : data(inData) {
    heapify();
}

template <class T>
HeapSimple<T>::HeapSimple(vector<T>&& inData)
    : data(inData) {
    heapify();
}

// 堆化
template <class T>
void HeapSimple<T>::heapify() {
    for(int i = data.size() / 2 - 1; i >= 0; i--) {
        down(i, data.size());
    }
}

// 上浮
template <class T>
void HeapSimple<T>::up(int iIndex) {
    size_t iParent = (iIndex - 1) / 2;
    if(iParent >= data.size()) {
        return;
    }

    if(data[iParent] < data[iIndex]) {
        swap(data[iParent], data[iIndex]);
        up(iParent);
    }
}

// 下沉
template <class T>
void HeapSimple<T>::down(int iIndex, int iSize) {
    int iLNode = iIndex * 2 + 1;
    int iRNode = iLNode + 1;

    int iT = iIndex;
    if(0 <= iLNode && iLNode < iSize && data[iLNode] > data[iT]) {
        iT = iLNode;
    }

    if(0 <= iRNode && iRNode < iSize && data[iRNode] > data[iT]) {
        iT = iRNode;
    }

    if(iT != iIndex) {
        swap(data[iT], data[iIndex]);
        down(iT, iSize);
    }
}

// 插入数据
template <class T>
void HeapSimple<T>::insert(const T& val) {
    data.emplace_back(val);

    up(data.size() - 1);
}

// 获取最大值并删掉最大值
template <class T>
T HeapSimple<T>::popMax() {
    T max = data[0];
    data.pop_back();
    return max;
}

// 移除下标是iIndex的元素
template <class T>
void HeapSimple<T>::remove(int iIndex) {
    if(iIndex < 0 || iIndex >= data.size()) {
        cerr << "err index : " << iIndex << endl;
        return;
    }

    swap(data[iIndex], data.back());
    data.pop_back();

    down(iIndex, data.size());
}

template <class T>
void HeapSimple<T>::show() {
    for(auto t : data) {
        cout << t << "  ";
    }
    cout << endl;
}

// 堆排序 大根堆原地排序后是从小->大,无法实现原地排序后是从大->小
template <class T>
void HeapSimple<T>::heapSort() {
    if(data.empty()) {
        return;
    }

    for(int i = data.size() - 1; i >= 0; i--) {
        // 由于是大根堆,所以堆顶是最大值
        // 把最大值放在最后
        swap(data[i], data[0]);
        down(0, i);
    }
}

}  // namespace lw
