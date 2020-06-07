// Copyright 2020 <randypalusz>

#include "RLinkedList.hpp"

#include <iostream>

#include "RListObject.hpp"

namespace rp {

template <typename T>
LinkedList<T>::~LinkedList() {
  ListObject<T> *current = head_;
  ListObject<T> *temp = nullptr;
  while (current != nullptr) {
    temp = current->GetNext();
    delete current;
    current = temp;
  }
}

template <typename T>
auto LinkedList<T>::Size() -> const int {
  int listSize = 0;
  ListObject<T> *traverse = head_;
  while (traverse != nullptr) {
    traverse = traverse->GetNext();
    listSize++;
  }
  return listSize;
}

template <typename T>
void LinkedList<T>::AddFront(const T &data) {
  ListObject<T> *n = new ListObject<T>{data};
  n->SetNext(head_);
  head_ = n;
}

template <typename T>
void LinkedList<T>::AddBack(const T &data) {
  ListObject<T> *n = new ListObject<T>{data};
  ListObject<T> *traverse = head_;

  while (traverse->GetNext() != nullptr) {
    traverse = traverse->GetNext();
  }

  traverse->SetNext(n);
}

template <typename T>
auto LinkedList<T>::RemoveFront() -> const T {
  T returnData = head_->GetData();
  ListObject<T> *temp = head_;
  temp = head_->GetNext();
  delete head_;
  head_ = temp;
  return returnData;
}

template <typename T>
auto LinkedList<T>::RemoveBack() -> const T {
  ListObject<T> *traverse = head_;
  while (traverse->GetNext()->GetNext() != nullptr) {
    traverse = traverse->GetNext();
  }
  // traverse is not nullptr, but the one after next is
  T retValue = traverse->GetNext()->GetData();
  delete traverse->GetNext()->GetNext();
  traverse->SetNext(nullptr);
  return retValue;
}

template <typename T>
void LinkedList<T>::PrintList() {
  ListObject<T> *temp = head_;
  std::cout << "Printing List Data From Front -> Back..." << std::endl;
  std::cout << "<";
  while (temp != nullptr) {
    std::cout << temp->GetData();
    temp = temp->GetNext();
    if (temp != nullptr) {
      std::cout << ", ";
    }
  }
  std::cout << ">" << std::endl;
}

template <typename T>
void LinkedList<T>::PrintListVerbose() {
  ListObject<T> *traverse = head_;
  // std::cout << "Printing List Data From Front -> Back..." << std::endl;
  std::cout << "[Address] --> <Data, Next Address>" << std::endl;
  while (traverse != nullptr) {
    std::cout << "[" << traverse
              << "] --> <" << traverse->GetData()
              << ", " << traverse->GetNext()
              << ">" << std::endl;
    traverse = traverse->GetNext();
  }
  std::cout << std::endl;
}

template <typename T>
auto LinkedList<T>::Front() -> const T {
  return head_->GetData();
}

template <typename T>
auto LinkedList<T>::Back() -> const T {
  ListObject<T> *traverse = head_;
  while (traverse->GetNext() != nullptr) {
    traverse = traverse->GetNext();
  }
  return traverse->GetData();
}

template <typename T>
void LinkedList<T>::Reverse() {
  // traverse will simply go through the current list
  // from head_ to the tail
  ListObject<T> *traverse = head_;
  // temp will follow traverse, following by one position
  // and will set the next_ field of itself to the pointer, 'previous'
  ListObject<T> *temp = head_;
  // previous will hold the memory address of temp before temp
  // is updated to the position of traverse
  ListObject<T> *previous = nullptr;

  while (traverse->GetNext() != nullptr) {
    traverse = traverse->GetNext();
    temp->SetNext(previous);
    previous = temp;
    temp = traverse;
  }
  // set head_ to the value of traverse as the next field
  // of traverse is a nullptr
  head_ = traverse;
  // and set its next field to previous
  head_->SetNext(previous);
}

}  // namespace rp
