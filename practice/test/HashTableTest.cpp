#include <iostream>
#include <string>

#include "HashTable.h"

using namespace std;
using namespace lw;

void help() {
    cout << "input :argv(mean)      \n\
            a key val   (add)       \n\
            ie key      (isExists)  \n\
            gv key      (getVal)    \n\
            rm key      (remove)    \n\
            s           (show)"
         << endl;
}

int main(int argc, char const* argv[]) {
    HashTable ht(10);

    string op;
    string key;
    string val;

    while(cin >> op) {
        if(op == "a") {
            cin >> key >> val;
            HashObject ho(key, val);
            ht.add(ho);
        }
        else if(op == "ie") {
            cin >> key;
            if(ht.isExists(key)) {
                cout << "find" << endl;
            }
            else {
                cout << "not found" << endl;
            }
        }
        else if(op == "gv") {
            cin >> key;

            cout << "the found result is:" << ht.getVal(key) << endl;
        }
        else if(op == "rm") {
            cin >> key;
            ht.remove(key);
        }
        else if(op == "s") {
            ht.show();
        }
        else {
            help();
        }
    }

    return 0;
}
