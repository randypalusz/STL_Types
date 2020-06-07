#include "RVector.hpp"
#include "iostream"

int main() {
  int cap = 3;
  rp::RVector vec(cap);
  std::cout << "Created RVector of capacity: " << cap << std::endl;

  std::cout << "Returned capacity: " << vec.getCapacity() << std::endl;

  vec.pushBack(1);
  std::cout << "Size: " << vec.getSize() << std::endl;
  vec.pushBack(2);
  std::cout << "Size: " << vec.getSize() << std::endl;
  vec.pushBack(3);
  std::cout << "Size: " << vec.getSize() << std::endl;

  std::cout << "Pushed back 1, 2, 3" << std::endl;

  std::cout << "Access using ()..." << std::endl;
  std::cout << "Position 0: " << vec(0) << std::endl;
  std::cout << "Position 1: " << vec(1) << std::endl;
  std::cout << "Position 2: " << vec(2) << std::endl;

  std::cout << "Access using 'at'..." << std::endl;
  std::cout << "Position 0: " << vec.at(0) << std::endl;
  std::cout << "Position 1: " << vec.at(1) << std::endl;
  std::cout << "Position 2: " << vec.at(2) << std::endl;

  vec.pushBack(new int[3] {7, 4, 2}, 3);
  std::cout << "Size: " << vec.getSize() << std::endl;
  vec.printAll();

  std::cout << "Accessing outside size..." << std::endl;
  vec(6);

  std::cout << "Popping last element..." << std::endl;
  std::cout << vec.popBack() << std::endl;

  std::cout << "Popping last element..." << std::endl;
  std::cout << vec.popBack() << std::endl;

  std::cout << "Popping first element..." << std::endl;
  std::cout << vec.popFront() << std::endl;

  vec.printAll();

  std::cout << "Popping first element..." << std::endl;
  std::cout << vec.popFront() << std::endl;

  std::cout << "Popping last element..." << std::endl;
  std::cout << vec.popBack() << std::endl;

  std::cout << "Popping first element..." << std::endl;
  std::cout << vec.popFront() << std::endl;

  std::cout << "Popping first element..." << std::endl;
  std::cout << vec.popFront() << std::endl;


  vec.printAll();
}
