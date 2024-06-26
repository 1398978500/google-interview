#include <iostream>
#include <string>

#include "QueueList.h"

using namespace std;
using namespace lw;

void help() {

    cout << "input :argv(mean)      \n\
            e val       (enqueue)   \n\
            d           (dequeue)   \n\
            h           (help)      \n\
            s           (show)"
         << endl;
}

int main(int argc, char const* argv[]) {
    QueueList<int> ql;

    char op = 0;
    int  val = 0;
    while(cin >> op) {
        switch(op) {
        case 'e':
            cin >> val;
            ql.enqueue(val);
            break;

        case 'd':
            cout << ql.dequeue() << endl;
            break;

        case 's':
            ql.show();
            break;

        default:
            help();
            break;
        }
    }

    return 0;
}
