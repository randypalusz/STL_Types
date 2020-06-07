// Copyright 2020 <randypalusz>

#include "RVector.hpp"

#include <iostream>
#include <memory>
#include <utility>

rp::RVector::RVector(int capacity) : size_(0) {
  if (capacity < 1) {
    std::cout << "Can't construct RVector with capacity < 1" << std::endl;
    exit(EXIT_FAILURE);
  }
  capacity_ = capacity;
  data_ = std::unique_ptr<int[]>(new int[capacity_]);
}

rp::RVector::~RVector() {}

auto rp::RVector::getSize() -> int { return size_; }

auto rp::RVector::getCapacity() -> int { return capacity_; }

void rp::RVector::pushBack(int value) {
  resize(size_ + 1);
  data_[size_] = value;
  size_++;
}

void rp::RVector::pushBack(int *vals, int numElements) {
  for (int i = 0; i < numElements; i++) {
    pushBack(vals[i]);
  }
}

auto rp::RVector::popBack() -> int {
  if (size_ <= 0) {
    std::cout << "Attempt to pop with empty RVector" << std::endl;
    exit(EXIT_FAILURE);
  }
  int poppedValue = data_[size_ - 1];
  resize(size_ - 1);
  size_--;
  return poppedValue;
}

auto rp::RVector::popFront() -> int {
  if (size_ <= 0) {
    std::cout << "Attempt to pop with empty RVector" << std::endl;
    exit(EXIT_FAILURE);
  }
  int poppedValue = data_[0];
  reduceFront();
  size_--;
  return poppedValue;
}

void rp::RVector::printAll() {
  std::cout << "Printing entire RVector..." << std::endl;
  std::cout << "<";
  for (int i = 0; i < size_; i++) {
    std::cout << at(i);
    if (i != (size_ - 1)) {
      std::cout << ", ";
    }
  }
  std::cout << ">" << std::endl;
}

auto rp::RVector::operator()(int position) -> int {
  if (position > (size_ - 1)) {
    std::cout << "Invalid position, access outside RVector" << std::endl;
    exit(EXIT_FAILURE);
  }
  return data_[position];
}

auto rp::RVector::at(int position) -> int {
  if (position > (size_ - 1)) {
    std::cout << "Invalid position, access outside RVector" << std::endl;
    exit(EXIT_FAILURE);
  }
  return (*this)(position);
}

void rp::RVector::resize(int size) {
  if (size < size_) {
    if (size >= capacity_) {
      expand();
    }
    if (size < capacity_) {
      reduceBack();
    }
  }
}

void rp::RVector::expand() {
  int newCapacity = capacity_ * 2;

  std::unique_ptr<int[]> newData(new int[newCapacity]);

  for (int i = 0; i < size_; i++) {
    newData[i] = data_[i];
  }

  data_ = std::move(newData);
  capacity_ = newCapacity;
}

void rp::RVector::reduceBack() {
  int newCapacity = capacity_ - 1;
  int newSize = size_ - 1;

  std::unique_ptr<int[]> newData(new int[newCapacity]);

  for (int i = 0; i < newSize; i++) {
    newData[i] = data_[i];
  }

  data_ = std::move(newData);
  capacity_ = newCapacity;
}

void rp::RVector::reduceFront() {
  int newCapacity = capacity_ - 1;
  int newSize = size_ - 1;

  std::unique_ptr<int[]> newData(new int[newCapacity]);

  // Copy elements of data_ to newData, skipping first
  // element of data_
  for (int i = 1; i < size_; i++) {
    newData[i - 1] = data_[i];
  }

  data_ = std::move(newData);
  capacity_ = newCapacity;
}
