// Copyright 2020 <randypalusz>

#include "RHashTable.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "RHashObject.hpp"

int main() {
  {
    rp::HashTable t{2};
    t.Put("hello", "goodbye");
    t.Put("one", "two");
    std::cout << t.Get("hello") << std::endl;
    std::cout << t.Get("one") << std::endl;
  }

  {
    rp::HashObject o[4]{};
    o[0].SetKeyValue("one", "1");
    o[1].SetKeyValue("two", "2");
    o[2].SetKeyValue("three", "3");
    std::cout << "Adding 'one, 1', 'two, 2', "
                 "'three, 3' to HashTable... "
              << std::endl;
    rp::HashTable t{o, 3};
    std::cout << "Retreiving values from HashTable... " << std::endl;
    std::cout << t.Get("one") << std::endl;
    std::cout << t.Get("two") << std::endl;
    std::cout << t.Get("three") << std::endl;
    std::cout << "Updating 'three, 3' -> 'three, 4'"
                 " in HashTable using HashTable::Add... "
              << std::endl;
    t.Put("three", "4");
    std::cout << "Retreiving 'three' from HashTable... " << std::endl;
    std::cout << t.Get("three") << std::endl;
    std::cout << "Retreiving all keys from HashTable... " << std::endl;
    for (auto key : t.GetKeys()) {
      std::cout << key << std::endl;
    }
    std::cout << "Removing 'one' from HashTable..." << std::endl;
    t.Remove("one");
    std::cout << "Retreiving all keys from HashTable... " << std::endl;
    for (auto key : t.GetKeys()) {
      std::cout << key << std::endl;
    }
    std::cout << "Updating 'two, 1' -> 'two, 55' "
                 "in HashTable using HashTable::Update... "
              << std::endl;
    t.Update("two", "55");
    std::cout << "Retreiving 'two' from HashTable... " << std::endl;
    std::cout << t.Get("two") << std::endl;
  }
}
