#pragma once

#include "HashObject.h"

namespace lw {
class HashTable {
public:
    explicit HashTable(const int iSize);
    ~HashTable();
    HashTable(const HashTable&) = delete;
    HashTable& operator=(const HashTable&) = delete;

    void add(HashObject& object);

    bool isExists(const std::string key);

    const std::string getVal(const std::string key);

    void remove(const std::string key);

    void show();

private:
    int hash(const std::string key);
    int findIndex(const std::string key);

private:
    int         iSize;
    HashObject* data;
};

}  // namespace lw
