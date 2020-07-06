// Copyright 2020 <randypalusz>

#include "RBinaryTree.hpp"

#include <iostream>
#include <vector>

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
void BinaryTree<T>::insert(T* data, int size) {
  for (int i = 0; i < size; i++) {
    insert(data[i]);
  }
}

template <typename T>
void BinaryTree<T>::insert(const std::vector<T>& data) {
  for (auto& element : data) {
    insert(element);
  }
}

template <typename T>
void BinaryTree<T>::remove(T data, bool deleteChildren) {
  TreeElement<T>* node = getParent(data);
  if (node == nullptr) {
    return;
  }
  if (data < node->getData()) {
    if (deleteChildren) {
      removeRecursive(node->getLeft());
      node->setLeft(nullptr);
    } else {
      removeAndKeep(node->getLeft(), true);
    }
  } else if (data > node->getData()) {
    if (deleteChildren) {
      removeRecursive(node->getRight());
      node->setRight(nullptr);
    } else {
      removeAndKeep(node->getRight(), true);
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
auto BinaryTree<T>::getParent(T val) -> TreeElement<T>* {
  TreeElement<T>* traverse = root_;
  TreeElement<T>* parent = nullptr;
  while (traverse) {
    if (traverse->getData() == val) {
      return parent;
    } else if (val < traverse->getData()) {
      parent = traverse;
      traverse = traverse->getLeft();
    } else {
      parent = traverse;
      traverse = traverse->getRight();
    }
  }
  return nullptr;
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
void BinaryTree<T>::removeRecursive(TreeElement<T>* node) {
  if (!node) {
    return;
  }

  removeRecursive(node->getRight());
  removeRecursive(node->getLeft());

  delete node;
}

template <typename T>
T BinaryTree<T>::removeAndKeep(TreeElement<T>* node, bool firstEnter) {
  T replacementValue;

  if (firstEnter) {
    if (!node->getRight() && !node->getLeft()) {
      replacementValue = swapNodesAndDeleteLeaf(node);
      return replacementValue;
    }
    replacementValue = removeAndKeep(node->getRight(), false);
    node->updateData(replacementValue);
    return replacementValue;
  }

  // condition if left-most leaf is found
  if (!node->getRight() && !node->getLeft()) {
    replacementValue = swapNodesAndDeleteLeaf(node);
    return replacementValue;
  } else if (node->getLeft()) {
    replacementValue = removeAndKeep(node->getLeft(), false);
  } else {
    replacementValue = removeAndKeep(node->getRight(), false);
  }

  return replacementValue;

  std::cout << "removeAndKeep for data: " << node->getData() << std::endl;
}

template <typename T>
T BinaryTree<T>::swapNodesAndDeleteLeaf(TreeElement<T>* node) {
  T replacementValue = node->getData();
  TreeElement<T>* parent = getParent(replacementValue);
  if (replacementValue > parent->getData()) {
    parent->setRight(nullptr);
  } else {
    parent->setLeft(nullptr);
  }
  delete node;
  return replacementValue;
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
