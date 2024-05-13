#include <iostream>

#include "BSTSimple.h"

using namespace std;
using namespace lw;

void help() {
    cout << "input: arg (mean)          \n\
        add val         (add)           \n\
        search val      (search)        \n\
        getmin          (getMin)        \n\
        getmax          (getmax)        \n\
        getheight       (getHeight)     \n\
        pbfs            (printBFS)      \n\
        pinorder        (printInOrder)  \n\
        isbst           (isBST)         \n\
        getminnode      (getMinNode)    \n\
        gets val        (getSuccessor)  \n\
        d val           (deleteValue)   \n\
        h               (help)          \n\
        " << endl;
}

int main(int argc, char const* argv[]) {
    BSTSimple<int> a;
    a.printInOrder();

    help();

    string op;
    int    val;
    while(cin >> op) {
        if(op == "add") {
            cin >> val;
            a.addNew(val);
        }
        else if(op == "search") {
            cin >> val;
            if(a.search(val)) {
                cout << "can found" << endl;
            }
            else {
                cout << "can not found" << endl;
            }
        }
        else if(op == "getmin") {
            cout << *(a.getMin()) << endl;
        }
        else if(op == "getmax") {
            cout << *(a.getMax()) << endl;
        }
        else if(op == "getheight") {
            cout << a.getHeight() << endl;
        }
        else if(op == "pbfs") {
            a.printBFS();
        }
        else if(op == "pinorder") {
            a.printInOrder();
        }
        else if(op == "isbst") {
            if(a.isBST()) {
                cout << "isBST" << endl;
            }
            else {
                cout << "is not BST" << endl;
            }
        }
        else if(op == "getminnode") {
            auto node = a.getMinNode();
            if(node) {
                cout << node->data << endl;
            }
            else {
                cout << "tree is empty" << endl;
            }
        }
        else if(op == "gets") {
            cin >> val;
            auto node = a.getSuccessor(val);
            if(node) {
                cout << node->data << endl;
            }
            else {
                cout << "no successor" << endl;
            }
        }
        else if(op == "d") {
            cin >> val;
            a.deleteValue(a.getRoot(), val);
        }
        else {
            help();
        }
    }

    return 0;
}
