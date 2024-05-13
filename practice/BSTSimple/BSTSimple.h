#pragma once

#include <iostream>
#include <limits.h>
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
    // 删除特定节点
    BSTNode<T>* deleteValue(BSTNode<T>*& node, const T& val);
    // 获取最小节点
    BSTNode<T>* getMinNode();
    //
    BSTNode<T>* getSuccessor(const T& val);

    BSTNode<T>*& getRoot() {
        return root;
    }

private:
    BSTNode<T>* root;

    void deleteNode(BSTNode<T>* node);
    // 插入一个节点
    BSTNode<T>* insert(BSTNode<T>* node, const T& val);
    // 是否所有值都在min和max之间
    bool isBetween(BSTNode<T>* node, const T& min, const T& max);

    BSTNode<T>* getMinNode(BSTNode<T>* node);
};

template <class T>
BSTSimple<T>::~BSTSimple() {
    // 尽量不用递归
    // deleteNode(root);

    if(!root) {
        return;
    }

    queue<BSTNode<T>*> q;
    q.push(root);

    while(!q.empty()) {
        BSTNode<T>* node = q.front();
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
        if(node->data == val) {
            return true;
        }
        else if(val < node->data) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }

    return false;
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

    queue<BSTNode<T>*> que;
    que.push(root);
    int iHeight = 0;
    // 层序遍历
    while(!que.empty()) {
        int iLevelSize = que.size();
        while(iLevelSize--) {
            BSTNode<T>* node = que.front();
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

    queue<BSTNode<T>*> que;
    que.push(root);

    while(!que.empty()) {
        int iLevelSize = que.size();
        while(iLevelSize--) {
            BSTNode<T>* node = que.front();
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

// 中序遍历
template <class T>
void BSTSimple<T>::printInOrder() {
    if(!root) {
        return;
    }

    stack<BSTNode<T>*> st;

    auto cur = root;

    while(!st.empty() || cur) {
        // 找左子树
        if(cur) {
            st.push(cur);
            cur = cur->left;
        }
        else {
            cur = st.top();
            st.pop();
            cout << cur->data << " ";
            cur = cur->right;
        }
    }
}

// 是否是二叉搜索树
template <class T>
bool BSTSimple<T>::isBST() {
    return isBetween(root, INT_MIN, INT_MAX);
}

// 是否所有值都在min和max之间
template <class T>
bool BSTSimple<T>::isBetween(BSTNode<T>* node, const T& min, const T& max) {
    if(!node) {
        return true;
    }

    if(min <= node->data && node->data <= max && isBetween(node->left, min, node->data)
       && isBetween(node->right, node->data, max)) {
        return true;
    }

    return false;
}

// 删除特定节点
template <class T>
BSTNode<T>* BSTSimple<T>::deleteValue(BSTNode<T>*& node, const T& val) {
    if(val < node->data) {
        deleteValue(node->left, val);
    }
    else if(val > node->data) {
        deleteValue(node->right, val);
    }
    // 找到要删除的节点
    else {
        if(!node->left && !node->right) {

            delete node;
            node = nullptr;
        }
        else if(!node->left) {
            auto tmp = node;
            node = node->right;
            delete tmp;
        }
        else if(!node->right) {
            auto tmp = node;
            node = node->left;
            delete tmp;
        }
        else {
            // 把要删除的节点改成右边最小的节点
            auto tmp = getMinNode(node->right);
            node->data = tmp->data;
            // 然后删除右子树中节点最小的节点
            node->right = deleteValue(node->right, tmp->data);
        }
    }

    return node;
}

// 获取最小节点
template <class T>
BSTNode<T>* BSTSimple<T>::getMinNode() {
    return getMinNode(root);
}

// 定义：所谓predecessor即在BST的中序遍历中，其中某一非首序节点的前一节点.
// 特殊地，首序节点的predecessor不存在
// 寻找一个节点的predecessor有两种情况：
// 1. 节点x存在左子树
//      找到这个predecessor节点的方法很简单，只需要找到A的左子树中最大的（最右边的）节点即可。
// 2. 节点x不存在左子树
//      找到这个predecessor节点，需要从节点B开始向上，直到遇到第一个是其父节点right
//      child的节点为止，记这个节点为F，则节点B的predecessor就是这是这个节点的父节点，即F.parent。

// 定义：所谓successor即在BST的中序遍历中，其中某一非末序节点的后一节点。
// 特殊地，末序节点的successor不存在。(其实successor的定义与predecessor恰好镜像)
// 根据定义，寻找一个节点的successor有两种情况：
// 1. 节点x存在右子树
//      到这个successor节点的方法很简单，只需要找到A的右子树中最小的（最左边的）那个节点即可。
// 2.节点x不存在右子树
//      要找到这个successor节点，需要从节点B开始向上，直到遇到第一个是其父节点left
//      child的节点为止，记这个节点为F，则节点B的successor就是这是这个节点的父节点，即F.parent。
template <class T>
BSTNode<T>* BSTSimple<T>::getSuccessor(const T& val) {
    if(!root) {
        return root;
    }

    // 找到val对应的节点
    auto targetNode = root;
    while(targetNode != nullptr) {
        if(targetNode->data == val) {
            break;
        }

        if(targetNode->data < val) {
            targetNode = targetNode->left;
        }
        else {
            targetNode = targetNode->right;
        }
    }

    // val不存在
    if(!targetNode) {
        cerr << val << " is not     exist" << endl;
        return nullptr;
    }

    if(root->right) {
        return getMinNode(root->right);
    }

    // 没有右子树
    BSTNode<T>* successor = nullptr;
    BSTNode<T>* ancestor = root;
    while(ancestor) {
        if(val < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else if(val > ancestor->data) {
            ancestor = ancestor->right;
        }
        // 到val就结束了
        else {
            break;
        }
    }
    return successor;
}

template <class T>
BSTNode<T>* BSTSimple<T>::insert(BSTNode<T>* node, const T& val) {
    if(!node) {
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

template <class T>
BSTNode<T>* BSTSimple<T>::getMinNode(BSTNode<T>* node) {
    if(!node) {
        return nullptr;
    }

    while(node->left) {
        node = node->left;
    }

    return node;
}

};  // namespace lw
