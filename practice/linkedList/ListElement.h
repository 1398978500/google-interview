#pragma once

namespace lw {

template <class T>
class ListElement {
public:
    ListElement(const T& val)
        : data(val)
        , next(nullptr) {}

    ~ListElement() {}
    ListElement(const ListElement&) = delete;

private:
    T               data;
    ListElement<T>* next;
};

}  // namespace lw
