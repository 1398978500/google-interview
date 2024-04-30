#pragma once

#include "ListElement.h"

using std::cerr;
using std::cout;
using std::endl;

namespace lw {

template <class T>
class LinkedList {
public:
    explicit LinkedList()
        : head(nullptr) {}
    ~LinkedList();

    // 删除拷贝构造函数
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    int      getSize() const;
    int      isEmpty() const;
    int      getValAt(int iIndex) const;
    void     pushFront(const T& value);
    const T  popFront();
    void     pushBack(const T& value);
    const T  popBack();
    const T& front();
    const T& back();
    void     insert(int iIndex, const T& value);
    void     erase(int iIndex);
    const T& valueFromEnd(int iIndex);
    void     reverse();
    // 删除第一个值是value的节点
    void removeValue(const T& value);

    void show();

private:
    ListElement<T>* head;
};

//  注:模板类的声明和实现最好在同一文件中
// When you use templates, you have to write the code and the headers in the same file
// because the compiler needs to generate the code where it is used in the program

template <class T>
LinkedList<T>::~LinkedList() {
    ListElement<T>* cur = head;
    ListElement<T>* next = nullptr;

    while(cur) {
        next = cur->getNext();
        delete cur;
        cur = next;
    }
}

template <class T>
int LinkedList<T>::getSize() const {
    auto tmp = head;
    int  iSize = 0;

    while(tmp) {
        iSize++;
        tmp = tmp->next;
    }

    return iSize;
}

template <class T>
int LinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <class T>
int LinkedList<T>::getValAt(int iIndex) const {
    ListElement<T>* cur = head;
    for(int i = 0; i < iIndex && cur != nullptr; i++) {
        cur = cur->getNext();
    }

    if(cur == nullptr) {
        cerr << "LinkedList<T>::getValAt : index out of bounds" << endl;
        exit(EXIT_FAILURE);
    }

    return cur->getData();
}

template <class T>
void LinkedList<T>::pushFront(const T& value) {
    ListElement<T>* node = new ListElement<T>(value);
    node->setNext(head);
    head = node;
}

template <class T>
const T LinkedList<T>::popFront() {
    if(head == nullptr) {
        cerr << "LinkedList<T>::popFront : nothing to pop" << endl;
        exit(EXIT_FAILURE);
    }

    auto node = head;
    T    value = node->getData();

    head = head->getNext();

    delete node;

    return value;
}

template <class T>
void LinkedList<T>::pushBack(const T& value) {
    ListElement<T>* node = new ListElement<T>(value);

    if(head == nullptr) {
        head = node;
        return;
    }

    ListElement<T>* cur = head;
    while(cur->getNext()) {
        cur = cur->getNext();
    }

    cur->setNext(node);
}

template <class T>
const T LinkedList<T>::popBack() {
    if(head == nullptr) {
        cerr << "LinkedList<T>::popBack : nothing to pop" << endl;
        exit(EXIT_FAILURE);
    }

    ListElement<T>* cur = head;
    ListElement<T>* pre = head;
    while(cur->getNext()) {
        pre = cur;
        cur = cur->getNext();
    }

    T value = cur->getData();

    if(pre == nullptr) {
        head = pre;
    }
    else {
        pre->setNext(nullptr);
    }

    delete cur;

    return value;
}

template <class T>
const T& LinkedList<T>::front() {
    if(head == nullptr) {
        cerr << "LinkedList<T>::front : linked list is empty" << endl;
        exit(EXIT_FAILURE);
    }

    return head->getData();
}

template <class T>
const T& LinkedList<T>::back() {
    if(head == nullptr) {
        cerr << "LinkedList<T>::front : linked list is empty" << endl;
        exit(EXIT_FAILURE);
    }

    ListElement<T>* cur = head;
    while(cur->getNext()) {
        cur = cur->getNext();
    }

    return cur->getData();
}

template <class T>
void LinkedList<T>::insert(int iIndex, const T& value) {
    ListElement<T>* prev = nullptr;
    ListElement<T>* cur = head;

    int i = 0;
    for(i = 0; i < iIndex && cur; i++) {
        prev = cur;
        cur = cur->getNext();
    }

    if(i != iIndex) {
        cerr << "LinkedList<T>::insert : index out of bounds" << endl;
        exit(EXIT_FAILURE);
    }

    ListElement<T>* node = new ListElement<T>(value);
    if(prev == nullptr) {
        node->setNext(head);
        head = node;

        return;
    }

    prev->setNext(node);
    node->setNext(cur);
}

template <class T>
void LinkedList<T>::erase(int iIndex) {
    ListElement<T>* prev = nullptr;
    ListElement<T>* cur = head;

    int i = 0;
    for(i = 0; i < iIndex && cur; i++) {
        prev = cur;
        cur = cur->getNext();
    }

    if(i != iIndex) {
        cerr << "LinkedList<T>::erase : index out of bounds" << endl;
        exit(EXIT_FAILURE);
    }

    if(prev == nullptr) {
        head = cur->getNext();
    }
    else {
        prev->setNext(cur->getNext());
    }

    delete cur;
}

template <class T>
const T& LinkedList<T>::valueFromEnd(int iIndex) {
    if(head == nullptr || iIndex < 0) {
        cerr << "LinkedList<T>::valueFromEnd : list is null or err arg" << endl;
        exit(EXIT_FAILURE);
    }

    ListElement<T>* cur = head;
    ListElement<T>* match = head;

    int i = 0;
    for(i = 0; i < iIndex && cur; i++) {
        cur = cur->getNext();
    }

    if(i != iIndex) {
        cerr << "LinkedList<T>::valueFromEnd : index out of bounds" << endl;
        exit(EXIT_FAILURE);
    }

    while(cur) {
        cur = cur->getNext();
        match = match->getNext();
    }

    return match->getData();
}

template <class T>
void LinkedList<T>::reverse() {
    ListElement<T>* prev = nullptr;
    ListElement<T>* cur = nullptr;

    while(head) {
        prev = cur;
        cur = head;
        head = head->getNext();
        cur->setNext(prev);
    }

    head = cur;
}

template <class T>
void LinkedList<T>::removeValue(const T& value) {
    ListElement<T>* prev = nullptr;

    ListElement<T>* cur = head;

    while(cur) {
        // 找到了
        if(cur->getData() == value) {
            // 删头节点
            if(prev == nullptr) {
                head = cur->next;
            }
            else {
                prev->setNext(cur->getNext());
            }

            delete cur;
            break;
        }

        prev = cur;
        cur = cur->getNext();
    }
}

template <class T>
void LinkedList<T>::show() {
    auto cur = head;
    while(cur->getNext()) {
        cout << cur->getData() << "->";
        cur = cur->getNext();
    }

    if(cur) {
        cout << cur->getData();
    }

    cout << endl;
}

}  // namespace lw
