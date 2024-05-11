#pragma once

#include <iostream>
#include <queue>
#include <stack>

using std::cerr;
using std::cout;
using std::endl;
using std::queue;
using std::stack;

namespace lw {
// 一个二叉搜索树 (尽量不使用递归)
template <class T>
struct BSTNode {
    T        data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const T& data)
        : data(data)
        , left(nullptr)
        , right(nullptr) {}
};

template <class T>
struct BSTSimple {

public:
    BSTSimple()
        : root(nullptr) {}
    ~BSTSimple();

    // 插入新节点
    void addNew(const T& val);
    // 查找某节点是否在树中
    bool search(const T& val);

    // 返回最小值
    T* getMin();
    // 返回最大值
    T* getMax();
    // 返回树的高度
    int getHeight();
    // 层序遍历
    void printBFS();
    // 中序遍历
    void printInOrder();
    // 是否是二叉搜索树
    bool isBST();
    // 是否所有值都在min和max之间
    bool isBetween(const T& min, const T& max);
    // 删除特定节点
    void deleteValue(const T& val);
    // 获取最小节点
    BSTNode<T>* getMinNode();
    //
    BSTNode<T>* getSuccessor(const T& val);

private:
    BSTNode<T>* root;

    void deleteNode(BSTNode<T>* node);
    // 插入一个节点
    BSTNode<T>* insert(BSTNode<T>* node, const T& val);
};

template <class T>
BSTSimple<T>::~BSTSimple() {
    // 尽量不用递归
    // deleteNode(root);

    if(!root) {
        return;
    }

    queue<T> q;
    q.push(root);

    while(!q.empty()) {
        auto node = q.front;
        q.pop();

        if(node->left) {
            q.push(node->left);
        }

        if(node->right) {
            q.push(node->right);
        }

        delete node;
    }
}

// 插入新节点
template <class T>
void BSTSimple<T>::addNew(const T& val) {
    BSTNode<T>* node = new BSTNode<T>(val);
    if(!root) {
        root = node;
        return;
    }

    auto cur = root;
    while(cur) {
        // 应该插入到左节点
        if(val < cur->data) {
            if(!cur->left) {
                cur->left = node;
                break;
            }

            cur = cur->left;
        }
        // 插入到右节点
        else {
            if(!cur->right) {
                cur->right = node;
                break;
            }

            cur = cur->right;
        }
    }
}

// 查找某节点是否在树中
template <class T>
bool BSTSimple<T>::search(const T& val) {
    if(!root) {
        return false;
    }

    auto node = root;
    while(node) {
        if(node == val) {
            return true;
        }
        else if(val < node) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
}

// 返回最小值
template <class T>
T* BSTSimple<T>::getMin() {
    auto node = root;
    if(!root) {
        return nullptr;
    }

    while(node->left) {
        node = node->left;
    }

    return &node->data;
}

// 返回最大值
template <class T>
T* BSTSimple<T>::getMax() {
    auto node = root;
    if(!root) {
        return nullptr;
    }

    while(node->right) {
        node = node->right;
    }

    return &node->data;
}

// 返回树的高度
template <class T>
int BSTSimple<T>::getHeight() {
    if(!root) {
        return 0;
    }

    queue<T> que;
    que.push(root);
    int iHeight = 0;
    // 层序遍历
    while(!que.empty()) {
        int iLevelSize = que.size();
        while(iLevelSize--) {
            auto node = que.front();
            que.pop();

            if(node->left) {
                que.push(node->left);
            }
            if(node->right) {
                que.push(node->right);
            }
        }

        iHeight++;
    }

    return iHeight;
}

// 层序遍历
template <class T>
void BSTSimple<T>::printBFS() {
    if(!root) {
        return;
    }

    queue<T> que;
    que.push(root);

    while(!que.empty()) {
        int iLevelSize = que.size();
        while(iLevel--) {
            auto node = que.front();
            que.pop();

            if(node->left) {
                que.push(node->left);
            }
            if(node->right) {
                que.push(node->right);
            }

            cout << node->data << "  ";
        }

        cout << endl;
    }
}

// 前序遍历
template <class T>
void BSTSimple<T>::printInOrder() {
    if(!root) {
        return;
    }

    stack<T> st;
    st.push(root);

    while(!st.empty()) {

        // while() {
        // }
    }
}

// 是否是二叉搜索树
template <class T>
bool BSTSimple<T>::isBST() {}

// 是否所有值都在min和max之间
template <class T>
bool BSTSimple<T>::isBetween(const T& min, const T& max) {
    return getMin() >= min && getMax() <= max;
}

// 删除特定节点
template <class T>
void BSTSimple<T>::deleteValue(const T& val) {}

// 获取最小节点
template <class T>
BSTNode<T>* BSTSimple<T>::getMinNode() {
    auto node = root;
    if(!root) {
        return nullptr;
    }

    while(node->left) {
        node = node->left;
    }

    return node;
}

//
template <class T>
BSTNode<T>* BSTSimple<T>::getSuccessor(const T& val) {}

template <class T>
BSTNode<T>* BSTSimple<T>::insert(BSTNode<T>* node, const T& val) {
    if(node == nullptr) {
        node = new BSTNode<T>(val);
        return node;
    }

    if(val < node->data) {
        node->left = insert(node->left, val);
    }
    // 相等情况归到右节点
    else {
        node->right = insert(node->right, val);
    }

    return node;
}

template <class T>
void BSTSimple<T>::deleteNode(BSTNode<T>* node) {
    if(!node) {
        return;
    }

    deleteNode(node->left);
    deleteNode(node->right);

    delete node;
}

};  // namespace lw
