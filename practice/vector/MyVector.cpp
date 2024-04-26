#include "MyVector.h"

namespace lw {

MyVector::MyVector(int iCap = iMinCapacity) : iCapacity(iCap > iMinCapacity ? iCap : iMinCapacity), iSize(0) {
    arr = new int[iCapacity];
}

MyVector::~MyVector() {
    if(arr != nullptr) {
        delete[] arr;
    }
}

int MyVector::getSize() const {
    return iSize;
}

int MyVector::getCapacity() const {
    return iCapacity;
}

bool MyVector::isEmpty() const {
    return iSize <= 0;
}

int MyVector::getValAt(int iIndex) const {
    return 0;
}

void MyVector::push(int val) {}

void MyVector::insert(int iIndex, int val) {}

void MyVector::prepend(int val) {}

int MyVector::pop() {
    return 0;
}

void MyVector::deleteAt(int iIndex) {}

// 删除所有这个值的元素
void MyVector::remove(int val) {}

// 查找第一个值是val的元素,返回下标
int MyVector::find(int val) const {
    return 0;
}

void MyVector::resize(int iNewCapacity) {}

// 计算实际需要的空间
int MyVector::calCapacity(int iCap) {

    while() {
    }
}

}  // namespace lw
