#pragma once

namespace lw {
static const int iMinCapacity = 16;  // 最小容量
static const int iGrowFactor = 2;    // 增长因子
static const int iShrinkFactor = 4;  // 收缩因子

class MyVector {
public:
    MyVector(int iCap = iMinCapacity);
    MyVector(const MyVector& other) = default;
    ~MyVector();

    int  getSize() const;
    int  getCapacity() const;
    bool isEmpty() const;
    int  getValAt(int iIndex) const;

    void push(int val);
    void insert(int iIndex, int val);
    void prepend(int val);
    int  pop();
    void deleteAt(int iIndex);
    void remove(int val);  // 删除所有这个值的元素

    int find(int val) const;  // 查找第一个值是val的元素,返回下标

private:
    void resize(int iNewCapacity);

private:
    // 计算实际需要的capacity 返回最终的capacity
    int calCapacity(int iCap);

private:
    int  iCapacity;
    int* arr;
    int  iSize;
};

}  // namespace lw
