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
    ListElement& operator=(const ListElement&) = default;

    const T& getData() const {
        return data;
    }

    ListElement<T>* getNext() {
        return next;
    }

    void setData(const T& t) {
        data = t;
    }

    void setNext(const ListElement<T>* elem) {
        next = elem;
    }

private:
    T               data;
    ListElement<T>* next;
};

}  // namespace lw
