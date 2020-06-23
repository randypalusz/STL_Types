// Copyright 2020 <randypalusz>

#include <iostream>
#include "RBinaryTree.hpp"
#include "RTreeElement.hpp"

namespace rp {

template <typename T>
BinaryTree<T>::BinaryTree(T data){
  root_->updateData(data);
}

}  // namespace rp
