#include <iostream>
#include <string>

#include "QueueList.h"

using namespace std;
using namespace lw;

int main(int argc, char const* argv[]) {
    QueueList<int> ql;

    char op = 0;
    int  val = 0;
    while(cin >> op) {
        switch(op) {
        case 'e':
            cin >> val;
            ql.enQueue(val);
            break;

        case 'd':
            ql.deQueue();
            break;

        default:
            ql.show();
            break;
        }
    }

    return 0;
}
