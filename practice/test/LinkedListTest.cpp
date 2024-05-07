#include <iostream>
#include <string>

#include "LinkedList.h"

using namespace lw;
using namespace std;

void help() {
    cout << "input: arg (mean)      \n\
        gva index   (getValAt)      \n\
        pushf val   (pushFront)     \n\
        popf        (popFront)      \n\
        pushb val   (pushBack)      \n\
        popb        (popBack)       \n\
        f           (front)         \n\
        b           (back)          \n\
        i index val (insert)        \n\
        e index     (erase)         \n\
        vfe index   (valueFromEnd)  \n\
        r           (reverse)       \n\
        rv val      (removeValue)   \n\
        s           (show)          \n\
        " << endl;
}

int main(int argc, char const* argv[]) {
    LinkedList<int> a;
    a.show();

    help();

    string op;
    int    index = 0, val = 0;
    while(cin >> op) {
        if(op == "gva") {
            cin >> index;
            cout << a.getValAt(index) << endl;
        }
        else if(op == "pushf") {
            cin >> val;
            a.pushFront(val);
        }
        else if(op == "popf") {
            cout << a.popFront() << endl;
        }
        else if(op == "pushb") {
            cin >> val;
            a.pushBack(val);
        }
        else if(op == "popb") {
            cout << a.popBack() << endl;
        }
        else if(op == "f") {
            cout << a.front() << endl;
        }
        else if(op == "b") {
            cout << a.back() << endl;
        }
        else if(op == "i") {
            cin >> index >> val;
            a.insert(index, val);
        }
        else if(op == "e") {
            cin >> index;
            a.erase(index);
        }
        else if(op == "vfe") {
            cin >> index;
            cout << a.valueFromEnd(index) << endl;
        }
        else if(op == "r") {
            a.reverse();
        }
        else if(op == "rv") {
            cin >> val;
            a.removeValue(val);
        }
        else if(op == "s") {
            a.show();
        }
        else {
            help();
        }
    }

    return 0;
}
