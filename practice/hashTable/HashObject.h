#pragma once

#include <string>

namespace lw {
class HashObject {
public:
    HashObject(std::string key = "", std::string val = "")
        : key(key)
        , val(val) {}
    ~HashObject() {}
    HashObject(const HashObject&) = delete;
    HashObject& operator=(const HashObject&) = default;

    std::string& getKey() {
        return key;
    }

    std::string& getVal() {
        return val;
    }

    void setDummy() {
        key = "";
        val = "";
    }

    void setKey(const std::string& key) {
        this->key = key;
    }

    void setVal(const std::string& val) {
        this->val = val;
    }

    static std::string getDummyKey() {
        return "<DUMMY>";
    }

    static std::string getNullKey() {
        return "<NULL>";
    }

private:
    std::string key;
    std::string val;
};
}  // namespace lw
