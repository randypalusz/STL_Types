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
void BinaryTree<T>::printInOrder(TreeElement<T>* node) {
  if (node->getLeft()) {
    printInOrder(node->getLeft());
  }

  std::cout << node->getData() << std::endl;

  if (node->getRight()) {
    printInOrder(node->getRight());
  }
}

}  // namespace rp
