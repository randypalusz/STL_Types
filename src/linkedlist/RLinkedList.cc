// Copyright 2020 <randypalusz>

#include "RLinkedList.hpp"

#include <iostream>

#include "RLinkedList.cpp"  // NOLINT
#include "RListObject.hpp"

int main() {
  // ListObject Testing
  rp::ListObject<char> one{'c'};
  rp::ListObject<char> two('a');
  rp::ListObject<char> three('r');

  one.SetNext(&two);
  two.SetNext(&three);

  std::cout << "Printing elements of ListObject until nullptr..." << std::endl;
  std::cout << "<" << one.GetData() << ", "
            << one.GetNext()->GetData() << ", "
            << one.GetNext()->GetNext()->GetData() << ">" << std::endl;

  // LinkedList Testing
  rp::LinkedList<int> li{};
  li.AddFront(1);
  li.AddFront(5);
  li.AddBack(6);
  li.AddBack(7);
  li.PrintList();
  li.PrintListVerbose();

  std::cout << "Front: " << li.Front() << std::endl;
  std::cout << "Back: " << li.Back() << std::endl;

  std::cout << "---------------------------------------" << std::endl;

  // Another List
  rp::LinkedList<char> charList{};

  std::cout << "Add 'l' to front..." << std::endl;
  // system("read");
  charList.AddFront('l');
  charList.PrintListVerbose();

  std::cout << "Add 'e' to front..." << std::endl;
  // system("read");
  charList.AddFront('e');
  charList.PrintListVerbose();

  std::cout << "Add 'h' to front..." << std::endl;
  // system("read");
  charList.AddFront('h');
  charList.PrintListVerbose();

  std::cout << "Add 'l' to back..." << std::endl;
  // system("read");
  charList.AddBack('l');
  charList.PrintListVerbose();

  std::cout << "Add 'o' to back..." << std::endl;
  // system("read");
  charList.AddBack('o');
  charList.PrintListVerbose();

  std::cout << "Remove front element..." << std::endl;
  // system("read");
  charList.RemoveFront();
  charList.PrintListVerbose();

  std::cout << "Remove back element..." << std::endl;
  // system("read");
  charList.RemoveBack();
  charList.PrintListVerbose();

  std::cout << "Remove back element..." << std::endl;
  // system("read");
  charList.RemoveBack();
  charList.PrintListVerbose();

  std::cout << "Reconstructing 'hello'..." << std::endl;
  charList.AddFront('h');
  charList.AddBack('l');
  charList.AddBack('o');
  charList.PrintListVerbose();

  std::cout << "Reversing LinkedList..." << std::endl;
  charList.Reverse();
  charList.PrintListVerbose();

  std::cout << "Size of List: " << charList.Size() << std::endl;
}
