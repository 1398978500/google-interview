#include <iostream>

#include "MyVector.h"

using std::cout;
using std::endl;
using std::unique_ptr;

namespace lw {

MyVector::MyVector(int iCap)
    : iCapacity(calCapacity(iCap))
    , iSize(0) {
    vData = unique_ptr<int[]>(new int[iCapacity]);
}

MyVector::~MyVector() {}

// 获取大小
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
    if(iIndex < 0 || iIndex >= iSize) {
        cout << "getValAt index out of bounds " << iIndex << endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}

void MyVector::push(int val) {
    resize(iSize + 1);

    vData[iSize] = val;
    iSize++;
}

void MyVector::insert(int iIndex, int val) {
    if(iIndex < 0 || iIndex > iSize) {
        cout << "Insert index out of bounds " << iIndex << endl;
        exit(EXIT_FAILURE);
    }

    resize(iSize + 1);

    for(int i = iSize; i > iIndex; i--) {
        vData[i] = vData[i - 1];
    }

    vData[iIndex] = val;
    iSize++;
}

void MyVector::prepend(int val) {
    insert(0, val);
}

int MyVector::pop() {
    if(iSize <= 0) {
        cout << "Nothing to pop " << endl;
        exit(EXIT_FAILURE);
    }

    resize(iSize - 1);

    int iRet = vData[iSize - 1];
    iSize--;

    return iRet;
}

void MyVector::deleteAt(int iIndex) {
    if(iIndex < 0 || iIndex >= iSize) {
        cout << "deleteAt index out of bounds " << iIndex << endl;
        exit(EXIT_FAILURE);
    }

    resize(iSize - 1);

    for(int i = iIndex; i < iSize - 1; i++) {
        vData[i] = vData[i + 1];
    }

    iSize--;
}

// 删除所有这个值的元素
void MyVector::remove(int val) {
    for(int i = 0; i < iSize; i++) {
        if(vData[i] == val) {
            deleteAt(i);
            i--;
        }
    }
}

// 查找第一个值是val的元素,返回下标
int MyVector::find(int val) const {
    int iRet = -1;
    for(int i = 0; i < iSize; i++) {
        if(vData[i] == val) {
            iRet = i;
            break;
        }
    }

    return iRet;
}

int& MyVector::operator[](int iIndex) {
    if(iIndex < 0 || iIndex >= iSize) {
        cout << "operator[] index out of bounds " << iIndex << endl;
        exit(EXIT_FAILURE);
    }

    return vData[iIndex];
}

void MyVector::resize(int iNewCapacity) {
    if(iSize < iNewCapacity && iCapacity == iSize) {
        // 容量不够了再扩大
        increaseCapacity();
    }
    else if(iSize > iNewCapacity && iSize < iCapacity / iShrinkFactor) {
        decreaseCapacity();
    }
}

// 计算实际需要的空间
int MyVector::calCapacity(int iCap) {
    int iTrueCapacity = iMinCapacity;
    while(iTrueCapacity / iGrowFactor < iCap) {
        iTrueCapacity *= iGrowFactor;
    }

    return iTrueCapacity;
}

// 扩大容量
void MyVector::increaseCapacity() {
    int iOldCap = iCapacity;
    int iNewCap = calCapacity(iOldCap);

    // 无需扩容
    if(iNewCap == iOldCap) {
        return;
    }

    changeCapacty(iNewCap);
}

// 缩小容量
void MyVector::decreaseCapacity() {

    int iOldCap = iCapacity;
    int iNewCap = iOldCap / (iShrinkFactor / 2);

    if(iNewCap < iMinCapacity) {
        iNewCap = iMinCapacity;
    }

    // 无需缩小
    if(iNewCap == iOldCap) {
        return;
    }

    changeCapacty(iNewCap);
}

// 实际改变容量
void MyVector::changeCapacty(int iNewCap) {
    if(iCapacity == iNewCap) {
        return;
    }

    unique_ptr<int[]> vNewData(new int[iNewCap]);
    for(int i = 0; i < iSize; i++) {
        vNewData[i] = vData[i];
    }

    vData = std::move(vNewData);
    iCapacity = iNewCap;
}

}  // namespace lw
