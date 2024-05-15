#include <iostream>

#include "Sort.h"

using namespace lw;
using namespace std;

void showVec(const vector<int>& v) {
    for(int i : v) {
        cout << i << "  ";
    }
    cout << endl;
}

int main(int argc, char const* argv[]) {
    vector<int> v{ 7, 6, 4, 5, 3 };

    quickSort(v, 0, v.size() - 1);

    showVec(v);

    return 0;
}
