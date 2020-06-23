#ifndef RBinaryTree
#define RBinaryTree

// Copyright 2020 <randypalusz>

#include "RTreeElement.hpp"

namespace rp {
template <typename T>
class BinaryTree {
  public:
    explicit BinaryTree(T data);
    BinaryTree(){ root_ = nullptr; }
    ~BinaryTree();
    void insert(T data);
    void printInOrder();
  private:
    TreeElement<T>* root_;
    void Destroy(TreeElement<T>* node);
    void printInOrder(TreeElement<T>* node);
};
}  // namespace rp

#endif  // RTreeElement
