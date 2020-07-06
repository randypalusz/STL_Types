#ifndef RBinaryTree
#define RBinaryTree

// Copyright 2020 <randypalusz>

#include <vector>

#include "RTreeElement.hpp"

namespace rp {
template <typename T>
class BinaryTree {
 public:
  explicit BinaryTree(T data);
  BinaryTree() { root_ = nullptr; }
  ~BinaryTree();
  void insert(T data);
  void insert(T* data, int size);
  void insert(const std::vector<T>& data);
  void remove(T data, bool deleteChildren = false);
  void printInOrder();
  void printInOrder2D();
  auto exists(T val) -> bool;

 private:
  TreeElement<T>* root_;
  auto getParent(T val) -> TreeElement<T>*;
  void Destroy(TreeElement<T>* node);
  void removeRecursive(TreeElement<T>* node);
  T removeAndKeep(TreeElement<T>* node, bool);
  T swapNodesAndDeleteLeaf(TreeElement<T>* node);
  void printInOrder(TreeElement<T>* node);
  void printInOrder2D(TreeElement<T>* node, int level);
};
}  // namespace rp

#endif  // RTreeElement
