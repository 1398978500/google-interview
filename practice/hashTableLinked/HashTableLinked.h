#pragma once

#include "HashObject.h"

// 使用拉链法实现的函数table
namespace lw {
class HashTableLinked {
public:
    explicit HashTableLinked(const int iSize);
    ~HashTableLinked();
    HashTableLinked(const HashTableLinked&) = delete;
    HashTableLinked& operator=(const HashTableLinked&) = delete;

    void add(HashObject& object);

    bool isExists(const std::string key);

    const std::string getVal(const std::string key);

    void remove(const std::string key);

    void show();

private:
    int hash(const std::string key);

private:
    int          iSize;
    HashObject** data;
};

}  // namespace lw
