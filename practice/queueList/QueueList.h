#pragma once

#include <cstdlib>
#include <iostream>

#include "ListElement.h"

using std::cerr;
using std::cout;
using std::endl;

namespace lw {
template <class T>
class QueueList {
public:
    explicit QueueList()
        : head(nullptr)
        , tail(nullptr) {}
    ~QueueList();
    QueueList(const QueueList&) = delete;
    QueueList& operator=(const QueueList&) = delete;

    void    enqueue(T value);
    const T dequeue();
    bool    isEmpty() const;
    void    show() const;

private:
    ListElement<T>* head;
    ListElement<T>* tail;
};

template <class T>
QueueList<T>::~QueueList() {
    ListElement<T>* tmp = head;
    while(tmp) {
        head = head->getNext();
        delete tmp;
        tmp = head;
    }
}

template <class T>
void QueueList<T>::enqueue(T value) {
    ListElement<T>* node = new ListElement<T>(value);
    if(tail == nullptr) {
        tail = head = node;
    }
    else {
        tail->setNext(node);
        tail = node;
    }
}

template <class T>
const T QueueList<T>::dequeue() {
    if(head == nullptr) {
        cerr << "queue is empty" << endl;
        exit(EXIT_FAILURE);
    }

    auto value = head->getData();
    auto tmp = head;

    if(head == tail) {
        head = tail = nullptr;
    }
    else {
        head = head->getNext();
    }

    delete tmp;

    return value;
}

template <class T>
bool QueueList<T>::isEmpty() const {
    return head == nullptr;
}

template <class T>
void QueueList<T>::show() const {
    if(head == nullptr) {
        cout << "empty" << endl;
        return;
    }

    auto cur = head;
    while(cur->getNext()) {
        cout << cur->getData() << "<";
        cur = cur->getNext();
    }

    if(cur) {
        cout << cur->getData();
    }

    cout << endl;
}

}  // namespace lw
