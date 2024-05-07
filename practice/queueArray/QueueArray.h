#pragma once

#include <iostream>

#include "ListElement.h"

using std::cerr;
using std::cout;
using std::endl;

namespace lw {

// 数组模拟普通队列,只能用一次,想要空间重复利用,需要用循环队列
template <class T>
class QueueArray {
    static const int QUEUE_ARRAY_POSITIONS = 5;

public:
    explicit QueueArray()
        : head(0)
        , tail(0) {}
    ~QueueArray() = default;
    QueueArray(const QueueArray&) = delete;
    QueueArray& operator=(const QueueArray&) = delete;

    void enqueue(T value);
    T    dequeue();
    bool IsEmpty() const;
    bool IsFull() const;
    void show() const;

private:
    T   data[QUEUE_ARRAY_POSITIONS];
    int head;
    int tail;
};

template <class T>
void QueueArray<T>::enqueue(T value) {
    // 越界了
    if(tail >= QUEUE_ARRAY_POSITIONS) {
        cerr << "no space" << endl;
        exit(EXIT_FAILURE);
    }

    data[tail] = value;
    tail++;
}

template <class T>
T QueueArray<T>::dequeue() {
    if(IsEmpty()) {
        cerr << "queue is empty " << endl;
        exit(EXIT_FAILURE);
    }

    T ret = data[head];
    head++;
    return ret;
}

template <class T>
bool QueueArray<T>::IsEmpty() const {
    return head == tail;
}

template <class T>
bool QueueArray<T>::IsFull() const {
    return head == (tail + 1) % QUEUE_ARRAY_POSITIONS;
}

template <class T>
void QueueArray<T>::show() const {
    if(IsEmpty()) {
        cout << "empty" << endl;
        return;
    }

    for(int i = head; i < tail - 1; i++) {
        cout << data[i] << "<";
    }

    cout << data[tail - 1] << endl;
}

}  // namespace lw
