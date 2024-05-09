#include <iostream>

#include "HashTableLinked.h"

using namespace std;

namespace lw {

HashTableLinked::HashTableLinked(const int iSize)
    : iSize(iSize)
    , data(new HashObject*[iSize]) {}

HashTableLinked::~HashTableLinked() {
    // 删除每一个节点
    for(int i = 0; i < iSize; i++) {
        auto tmp = data[i];
        while(tmp) {
            auto node = tmp;
            tmp = tmp->getNext();
            delete node;
        }
    }

    // 删除指针数组
    delete[] data;
}

void HashTableLinked::add(HashObject& object) {
    int iIndex = hash(object.getKey());
    cout << object.getKey() << "hash is " << iIndex << endl;

    HashObject* node = new HashObject(object);

    // 为空
    if(data[iIndex] == nullptr) {
        data[iIndex] = node;
        return;
    }

    auto        cur = data[iIndex];
    HashObject* prev = nullptr;

    while(cur) {
        // key已存在
        if(object.getKey() == cur->getKey()) {
            cur->setVal(object.getVal());
            return;
        }
        prev = cur;
        cur = cur->getNext();
    }

    prev->setNext(node);
}

bool HashTableLinked::isExists(const std::string key) {
    int iIndex = hash(key);

    auto cur = data[iIndex];
    while(cur) {
        if(cur->getKey() == key) {
            return true;
        }

        cur = cur->getNext();
    }

    return false;
}

const std::string HashTableLinked::getVal(const std::string key) {
    int iIndex = hash(key);

    auto cur = data[iIndex];
    while(cur) {
        if(cur->getKey() == key) {
            return cur->getVal();
        }

        cur = cur->getNext();
    }

    return nullptr;
}

void HashTableLinked::remove(const std::string key) {
    int iIndex = hash(key);

    auto        cur = data[iIndex];
    HashObject* prev = nullptr;

    while(cur) {
        // 找到了
        if(cur->getKey() == key) {
            // 要删除的是头
            if(prev == nullptr) {
                data[iIndex] = cur->getNext();
            }
            else {
                prev->setNext(cur->getNext());
            }

            delete cur;
            break;
        }

        prev = cur;
        cur = cur->getNext();
    }
}

void HashTableLinked::show() {
    cout << "{\n";
    for(int i = 0; i < iSize; i++) {
        cout << "   {" << i << ":";
        auto cur = data[i];
        while(cur) {
            cout << "{" << cur->getKey() << ":" << cur->getVal() << "}, ";
            cur = cur->getNext();
        }
        cout << "}," << endl;
    }
    cout << "}" << endl;
}

int HashTableLinked::hash(const std::string key) {
    int iHash = 0;
    for(int i = 0; i < key.length(); i++) {
        iHash = iHash * 31 + key[i];
    }

    return abs(iHash % iSize);
}

}  // namespace lw
