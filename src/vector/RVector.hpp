// Copyright 2020 <randypalusz>

#ifndef _R_VECTOR_HPP_  // NOLINT
#define _R_VECTOR_HPP_

#include <memory>

namespace rp {
class RVector {
 public:
  explicit RVector(int capacity);
  // Overloaded constructor
  RVector() : RVector(10) {}
  ~RVector();
  auto getSize() -> int;
  auto getCapacity() -> int;
  void pushBack(int*, int numElementsBeingPushed);
  void pushBack(int);
  auto popFront() -> int;
  auto popBack() -> int;
  void printAll();
  // Public access operator
  auto operator()(int) -> int;
  // Also can use this
  auto at(int) -> int;

 private:
  int size_;
  int capacity_;
  std::unique_ptr<int[]> data_;
  void resize(int);
  // Expands data by one element
  void expand();
  // Reduce data by one element at the back
  void reduceBack();
  // Reduce data by one element at the front
  void reduceFront();
};
}  // namespace rp

#endif  // _R_VECTOR_HPP_ // NOLINT