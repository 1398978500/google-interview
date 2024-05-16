#include <iostream>

#include "Sort.h"

using namespace std;

namespace lw {

// 归并排序
void mergeSort(vector<int>& v, int l, int r) {
    if(l >= r) {
        return;
    }

    int iMid = l + (r - l >> 1);
    mergeSort(v, l, iMid);
    mergeSort(v, iMid + 1, r);

    // 将l-r这一段排好序放在vTmp
    vector<int> vTmp(r - l + 1);

    int i = l, j = iMid + 1;
    int iIndex = 0;

    while(i <= iMid && j <= r) {
        if(v[i] <= v[j]) {
            vTmp[iIndex++] = v[i++];
        }
        else {
            vTmp[iIndex++] = v[j++];
        }
    }

    while(i <= iMid) {
        vTmp[iIndex++] = v[i++];
    }

    while(j <= r) {
        vTmp[iIndex++] = v[j++];
    }

    // 将vTmp写回v数组
    for(i = l, j = 0; i <= r; i++, j++) {
        v[i] = vTmp[j];
    }
}

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

    // 此时i是较大区间第一个数的下标,j是较小区间最后一个数的下标
    // 最后数组被分为两个区间 [l, j], [j + 1, r]
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
