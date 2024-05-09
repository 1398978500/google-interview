#include <iostream>

#include "HashTable.h"

using namespace std;

namespace lw {

HashTable::HashTable(const int iSize)
    : iSize(iSize)
    , data(new HashObject[iSize]) {
    if(data == nullptr) {
        cerr << "error :data is nullptr" << endl;
    }

    for(int i = 0; i < iSize; i++) {
        data[i].setKey(HashObject::getNullKey());
    }
}

HashTable::~HashTable() {
    delete[] data;
}

void HashTable::add(HashObject& object) {
    int iIndex = hash(object.getKey());
    int iOriginalIndex = iIndex;
    int iDummyIndex = -1;

    bool bFound = false;

    // 开放寻址法
    while(data[iIndex].getKey() != HashObject::getNullKey()) {
        // key已经存在
        if(data[iIndex].getKey() == object.getKey()) {
            bFound = true;
            break;
        }
        // 需要确保key不存在,才会使用没使用过的key
        else if(data[iIndex].getKey() == HashObject::getDummyKey()) {
            iDummyIndex = iIndex;
        }

        iIndex = (iIndex + 1) % iSize;

        // 找到尽头了,并且没有空的了
        if(iIndex == iOriginalIndex) {
            if(iDummyIndex == -1) {
                // 没地方放了
                cerr << "error : no space to push new key" << object.getKey() << endl;
                return;
            }

            break;
        }
    }

    if(!bFound && iDummyIndex != -1) {
        iIndex = iDummyIndex;
    }

    data[iIndex].setKey(object.getKey());
    data[iIndex].setVal(object.getVal());
}

bool HashTable::isExists(const std::string key) {

    return findIndex(key) != -1;
}

const std::string HashTable::getVal(const std::string key) {
    int iIndex = findIndex(key);
    if(iIndex == -1) {
        return nullptr;
    }
    return data[iIndex].getVal();
}

void HashTable::remove(const std::string key) {
    int iIndex = findIndex(key);
    if(iIndex == -1) {
        cout << "message : not found key :" << key << endl;
        return;
    }

    data[iIndex].setKey(HashObject::getDummyKey());
    data[iIndex].setVal("");
}

void HashTable::show() {
    cout << "{\n";
    for(int i = 0; i < iSize; i++) {
        cout << "   {" << i << ":" << data[i].getKey() << ":" << data[i].getVal() << "}";
    }
    cout << "\n}" << endl;
}

int HashTable::hash(const std::string key) {
    int iHash = 0;
    for(int i = 0; i < key.length(); i++) {
        iHash = iHash * 31 + key[i];
    }

    return abs(iHash % iSize);
}

// 找到一个key当前所在下标
int HashTable::findIndex(const std::string key) {
    int iIndex = hash(key);
    int iOriginalIndex = iIndex;

    while(data[iIndex].getKey() != HashObject::getNullKey()) {
        if(data[iIndex].getKey() == key) {
            return iIndex;
        }

        iIndex = (iIndex + 1) % iSize;

        // 没找到
        if(iIndex == iOriginalIndex) {
            return -1;
        }
    }

    return iIndex;
}

}  // namespace lw
