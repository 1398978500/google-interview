#include <iostream>
#include <string>

#include "QueueArray.h"

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
    QueueArray<int> qa;

    char op = 0;
    int  val = 0;
    while(cin >> op) {
        switch(op) {
        case 'e':
            cin >> val;
            if(qa.isFull()) {
                cout << "full" << endl;
                break;
            }
            qa.enqueue(val);
            break;

        case 'd':
            if(qa.isEmpty()) {
                cout << "empty" << endl;
                break;
            }
            cout << qa.dequeue() << endl;
            break;

        case 's':
            qa.show();
            break;

        default:
            help();
            break;
        }
    }

    return 0;
}
