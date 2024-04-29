#pragma once

#include "ListElement.h"

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
    int      getValAt() const;
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
    void     removeValue(const T& value);

private:
    ListElement<T>* head;
};

}  // namespace lw
