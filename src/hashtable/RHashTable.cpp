// Copyright 2020 <randypalusz>

#include "RHashTable.hpp"

#include <iostream>
#include <vector>

#include "RHashObject.hpp"

namespace rp {
HashTable::HashTable(int capacity) {
  data_ = new HashObject[capacity];
  for (int i = 0; i < capacity; i++) {
    // Not using HashTable::Put here because that looks
    // to update duplicates...
    data_[i].SetEmpty();
  }
  capacity_ = capacity;
}

HashTable::HashTable(HashObject* o, int numElements) {
  int capacity = numElements * 5;
  data_ = new HashObject[capacity];
  for (int i = 0; i < capacity; i++) {
    // Not using HashTable::Put here because that looks
    // to update duplicates...
    data_[i].SetEmpty();
  }
  capacity_ = capacity;
  for (int i = 0; i < numElements; i++) {
    Put(&o[i]);
  }
}

HashTable::~HashTable() { delete[] data_; }

auto HashTable::Hash(std::string key) -> int {
  int keyLen = static_cast<int>(key.length());
  int sum = 0;
  for (int i = 0; i < keyLen; i++) {
    sum += static_cast<int>(key.at(i));
  }
  return sum % capacity_;
}

void HashTable::Put(HashObject* o) {
  auto index = Hash(o->GetKey());
  auto originalIndex = index;
  auto val = o->GetValue();
  int existsIndex = _Exists(o->GetKey());
  // if found, will overwrite value at index
  if (existsIndex != -1) {
    data_[existsIndex].SetValue(o->GetValue());
    return;
  }
  while (data_[index].GetValue() != HashObject::GetEmptyValue()) {
    index = (index + 1) % capacity_;
    if (index == originalIndex) {
      // wrapped around, no empty slots
      exit(EXIT_FAILURE);
    }
  }
  data_[index].SetKey(o->GetKey());
  data_[index].SetValue(o->GetValue());
}

void HashTable::Put(std::string key, std::string value) {
  // Create HashObject, pass to overload
  HashObject o{};
  o.SetKey(key);
  o.SetValue(value);
  Put(&o);
}

void HashTable::Remove(std::string key) {
  // if not found, nothing to remove
  int existsIndex = _Exists(key);
  if (existsIndex == -1) {
    return;
  }
  data_[existsIndex].SetEmpty();
}

void HashTable::Update(std::string key, std::string value) {
  int existsIndex = _Exists(key);
  // if not found, do not update
  if (existsIndex == -1) {
    std::cout << "not found, not updating" << std::endl;
    return;
  }
  data_[existsIndex].SetValue(value);
}

auto HashTable::Get(std::string key) -> std::string {
  auto index = Hash(key);
  auto originalIndex = index;
  while (data_[index].GetKey() != key) {
    index = (index + 1) % capacity_;
    if (index == originalIndex) {
      exit(EXIT_FAILURE);
    }
  }
  return data_[index].GetValue();
}

auto HashTable::GetKeys() -> std::vector<std::string> {
  std::vector<std::string> returnList;
  for (int i = 0; i < capacity_; i++) {
    if (data_[i].GetKey() != HashObject::GetEmptyKey()) {
      returnList.push_back(data_[i].GetKey());
    }
  }
  return returnList;
}

auto HashTable::GetValues() -> std::vector<std::string> {
  std::vector<std::string> returnList;
  for (int i = 0; i < capacity_; i++) {
    if (data_[i].GetKey() != HashObject::GetEmptyKey()) {
      returnList.push_back(data_[i].GetValue());
    }
  }
  return returnList;
}

auto HashTable::_Exists(std::string key) -> int {
  auto index = Hash(key);
  auto originalIndex = index;
  while (data_[index].GetKey() != key) {
    index = (index + 1) % capacity_;
    if (index == originalIndex) {
      return -1;
    }
  }
  return index;
}
}  // namespace rp
