#pragma once

#include <vector>

using std::swap;
using std::vector;

namespace lw {

// 归并排序
void mergeSort(vector<int>& v, int l, int r);

// 快速排序
void quickSort(vector<int>& v, int l, int r);

// 选择排序
void selectSort(vector<int>& v);

// 插入排序
void insertSort(vector<int>& v);

// 冒泡排序
void bubbleSort(vector<int>& v);

}  // namespace lw
