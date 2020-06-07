#ifndef RLinkedList  // NOLINT
#define RLinkedList

// Copyright 2020 <randypalusz>

#include "RListObject.hpp"

namespace rp {
template <typename T>
class LinkedList {
 public:
  // : head_(nullptr) is an easy way to assign
  // a basic initialized value instead of typing in the {}
  LinkedList() : head_(nullptr) {}
  ~LinkedList();
  auto Size() -> const int;
  // Adds object to the front, replacing the list head
  void AddFront(const T& data);
  // Adds object to the tail
  void AddBack(const T& data);
  // Inserts object at the specified index
  // If position > #objects, adds to tail
  void Insert(T data, int position);
  // Removes the head object
  auto RemoveFront() -> const T;
  // Removes the tail object
  auto RemoveBack() -> const T;
  // Removes object at the passed index
  auto RemoveAtIndex(int index) -> const T;
  // Removes first element that matches the passed value
  void RemoveWithValue(const T value);
  void PrintList();
  void PrintListVerbose();
  // Returns value in head
  auto Front() -> const T;
  // Returns value at tail
  auto Back() -> const T;
  // Returns value at index
  auto ValueAt(int index) -> const T;
  // Reverses list
  void Reverse();

 private:
  ListObject<T>* head_;
};
}  // namespace rp

#endif  //RLinkedList //NOLINT