#include <iostream>

#include "Sort.h"

using namespace std;

namespace lw {

// 归并排序
void mergeSort(vector<int>& v, int l, int r) {}

// 快速排序
void quickSort(vector<int>& v, int l, int r) {
    if(l >= r) {
        return;
    }

    int num = v[l + (r - l >> 1)];
    int i = l - 1, j = r + 1;
    while(i < j) {
        while(v[++i] < num) {
            ;
        }
        while(v[--j] > num) {
            ;
        }

        if(i < j) {
            swap(v[i], v[j]);
        }
    }

    quickSort(v, l, j);
    quickSort(v, j + 1, r);
}

// 选择排序
void selectSort(vector<int>& v) {
    for(int i = 0; i < v.size(); i++) {
        // 最小的数的下标
        int iMinIndex = i;
        for(int j = i + 1; j < v.size(); j++) {
            if(v[j] < v[iMinIndex]) {
                iMinIndex = j;
            }
        }

        if(iMinIndex != i) {
            swap(v[i], v[iMinIndex]);
        }
    }
}

// 插入排序
void insertSort(vector<int>& v) {
    for(int i = 1; i < v.size(); i++) {
        int iTmp = v[i];  // 要插入的数
        int j = 0;        // 要插入位置的前一个数下标

        for(j = i - 1; j >= 0 && v[j] > iTmp; j--) {
            v[j + 1] = v[j];
        }

        // 插入要插入的数
        v[j + 1] = iTmp;
    }
}

// 冒泡排序优化版 其他优化可自行尝试
void bubbleSort(vector<int>& v) {
    for(int i = v.size() - 1; i >= 0; i--) {
        bool bIsSorted = true;

        for(int j = 1; j <= i; j++) {
            if(v[j - 1] > v[j]) {
                swap(v[j - 1], v[j]);
                bIsSorted = false;
            }
        }

        // 已经有序
        if(bIsSorted) {
            break;
        }
    }
}
}  // namespace lw
