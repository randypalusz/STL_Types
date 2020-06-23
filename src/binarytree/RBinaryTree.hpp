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
    void insert(T data);
    void printAll();
  private:
    TreeElement<T>* root_;
};
}  // namespace rp

#endif  // RTreeElement
