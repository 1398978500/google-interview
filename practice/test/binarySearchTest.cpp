#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 找到val在v中最左边的下标
int binarySearchL(vector<int> &v, int val) {
    int i = 0, j = v.size() - 1;

    while(i < j) {
        int mid = i + j >> 1;
        if(v[mid] >= val) {
            j = mid;
        } else {
            i = mid + 1;
        }

    }

    if(v[i] != val) {
        return -1;
    }

    return i;
}

// 找到val在v中最右边的下标
int binarySearchR(vector<int> &v, int val) {
    int i = 0, j = v.size() - 1;

    while(i < j) {
        int mid = i + j + 1 >> 1;
        if(v[mid] <= val) {
            i = mid;
        } else {
            j = mid - 1;
        }

    }

    if(v[i] != val) {
        return -1;
    }

    return i;
}


int main(int argc, char* argv[]) {
    vector<int> v{2,2,3,3,4,4,4,5,5};
    sort(v.begin(), v.end());

    for(int i : v) {
        cout << i <<" < ";
    }
    cout << endl;

    int num = 0;
    while(cin >> num) {
        cout << binarySearchL(v,num) << "      " << binarySearchR(v,num) << endl;
    }

    return 0;
}


