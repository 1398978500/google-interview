#include <iostream>

#include "MyVector.h"

using namespace std;
using namespace lw;

void showMyVector(MyVector& v) {
    cout << "size == " << v.getSize() << endl;
    cout << "capacity == " << v.getCapacity() << endl;
    cout << "member == [";
    for(int i = 0; i < v.getSize(); i++) {
        cout << v[i] << ",";
    }
    cout << "]" << endl;
}

void help() {
    cout << "g index: getValAt index" << endl;
    cout << "p val: push val to back" << endl;
    cout << "i index val: insert val to index" << endl;
    cout << "a val: insert val to head" << endl;
    cout << "b: pop back" << endl;
    cout << "d index: delete index" << endl;
    cout << "r val: remove all val" << endl;
    cout << "f val: find first val" << endl;
    cout << "s : show vector info " << endl;

    cout << "input your command:" << endl;
}

int main(int argc, char const* argv[]) {
    MyVector a(1);
    showMyVector(a);

    char op;

    int iIndex = 0;
    int iVal = 0;

    help();

    while((cin >> op)) {
        switch(op) {
        case 'g': {
            cin >> iIndex;
            int iRet = a.getValAt(iIndex);
            cout << "get num is " << iRet;
        } break;

        case 'p': {
            cin >> iVal;
            a.push(iVal);
        } break;

        case 'i': {
            cin >> iIndex >> iVal;
            a.insert(iIndex, iVal);
        } break;

        case 'a': {
            cin >> iVal;
            a.prepend(iVal);
        } break;

        case 'b': {
            int iRet = a.pop();
            cout << "pop num is " << iRet << endl;
        } break;

        case 'd': {
            cin >> iIndex;
            a.deleteAt(iIndex);
        } break;

        case 'r': {
            cin >> iVal;
            a.remove(iVal);
        } break;

        case 'f': {
            cin >> iVal;
            int iRet = a.find(iVal);
            cout << "find first num at " << iRet;
        } break;

        case 's': {
            showMyVector(a);
        } break;

        default:
            help();
            break;
        }
    }

    return 0;
}
