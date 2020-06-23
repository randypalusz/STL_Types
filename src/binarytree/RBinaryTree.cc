// Copyright 2020 <randypalusz>

#include "RBinaryTree.hpp"
#include <iostream>

#include "RBinaryTree.cpp"
#include "RTreeElement.hpp"

int main(){
  std::cout << "RBinaryTree entry point" << std::endl;
  rp::BinaryTree<int> bt{};
  bt.insert(100);
  bt.printInOrder();
  bt.insert(10);
  bt.insert(105);
  bt.insert(1);
  bt.insert(15);
  bt.printInOrder();
}
