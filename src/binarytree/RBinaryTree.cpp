// Copyright 2020 <randypalusz>

#include "RBinaryTree.hpp"

#include <iostream>

#include "RTreeElement.hpp"

namespace rp {

template <typename T>
BinaryTree<T>::BinaryTree(T data) {
  root_ = new TreeElement<T>(data);
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
  Destroy(root_);
}

template <typename T>
void BinaryTree<T>::Destroy(TreeElement<T>* node) {
  if (node != nullptr) {
    Destroy(node->getLeft());
    Destroy(node->getRight());
    delete node;
  }
}

template <typename T>
void BinaryTree<T>::insert(T data) {
  TreeElement<T>* node = root_;
  if (root_ == nullptr) {
    root_ = new TreeElement<T>(data);
  } else {
    while (node != nullptr) {
      if (data < node->getData()) {
        if (node->getLeft()) {
          node = node->getLeft();
        } else {
          TreeElement<T>* temp = new TreeElement<T>(data);
          node->setLeft(temp);
          return;
        }
      } else if (data > node->getData()) {
        if (node->getRight()) {
          node = node->getRight();
        } else {
          TreeElement<T>* temp = new TreeElement<T>(data);
          node->setRight(temp);
          return;
        }
      } else {
        return;
      }
    }
  }
}

template <typename T>
auto BinaryTree<T>::exists(T val) -> bool {
  TreeElement<T>* traverse = root_;
  while (traverse) {
    if (traverse->getData() == val) {
      return true;
    } else if (val < traverse->getData()) {
      traverse = traverse->getLeft();
    } else {
      traverse = traverse->getRight();
    }
  }
  return false;
}

template <typename T>
void BinaryTree<T>::printInOrder() {
  printInOrder(root_);
}

template <typename T>
void BinaryTree<T>::printInOrder2D() {
  printInOrder2D(root_, 0);
}

template <typename T>
void BinaryTree<T>::printInOrder(TreeElement<T>* node) {
  if (node->getLeft()) {
    printInOrder(node->getLeft());
  }

  std::cout << node->getData() << std::endl;

  if (node->getRight()) {
    printInOrder(node->getRight());
  }
}

template <typename T>
void BinaryTree<T>::printInOrder2D(TreeElement<T>* node, int level) {
  int spaces = 5;
  if (node->getRight()) {
    printInOrder2D(node->getRight(), level + 1);
  }
  for (int i = 0; i < (level * spaces); i++) {
    std::cout << " ";
  }
  std::cout << node->getData() << std::endl;

  if (node->getLeft()) {
    printInOrder2D(node->getLeft(), level + 1);
  }
}
}  // namespace rp