// Copyright 2020 <randypalusz>

#include "RBinaryTree.hpp"

#include <iostream>
#include <vector>

#include "RBinaryTree.cpp"
#include "RTreeElement.hpp"

template <typename T>
inline void LOG(T value) { std::cout << value << std::endl; }

int main() {
  std::cout << "RBinaryTree entry point" << std::endl;
  rp::BinaryTree<int> bt{};
  std::cout << "Calling exists on empty BinaryTree..." << std::endl;
  std::cout << bt.exists(0) << std::endl;
  std::cout << "Inserting 100..." << std::endl;
  bt.insert(100);
  std::cout << "Calling printInOrder on single element..." << std::endl;
  bt.printInOrder();
  LOG("Inserting 10, 105, 1, 15...");
  bt.insert(10);
  bt.insert(105);
  bt.insert(1);
  bt.insert(15);
  LOG("Printing BT in order...");
  bt.printInOrder();
  LOG("Adding 10 again, then printing BT...");
  bt.insert(10);
  bt.printInOrder();
  LOG("Checking if 10 exists...");
  std::cout << bt.exists(10) << std::endl;
  LOG("Checking if 23 exists...");
  std::cout << bt.exists(23) << std::endl;
  LOG("Adding some more elements before 2D print...");
  bt.insert(102);
  bt.insert(108);
  bt.insert(155);
  bt.insert(101);
  bt.insert(103);
  LOG("Insert vector of elements...");
  std::vector<int> v{160, 16, 2, 106};
  bt.insert(v);
  LOG("Insert array of elements...");
  int array[] = {156, 401, 124, 107};
  bt.insert(array, 4);
  LOG("Printing BT in order...");
  bt.printInOrder();
  LOG("Printing 2D...");
  bt.printInOrder2D();
  LOG("Removing 107...");
  bt.remove(107, true);
  bt.printInOrder2D();
  LOG("Removing 108...");
  bt.remove(108, true);
  bt.printInOrder2D();
  LOG("Removing 10 and keeping contents...");
  bt.remove(10, false);
  bt.printInOrder2D();
  LOG("Removing 102 and keeping contents...");
  bt.remove(102);
  bt.printInOrder2D();
  LOG("Removing 101 and keeping contents...");
  bt.remove(101);
  bt.printInOrder2D();
}
