#ifndef RHashTable  // NOLINT
#define RHashTable

// Copyright 2020 <randypalusz>

#include <string>
#include <vector>

#include "RHashObject.hpp"

namespace rp {
class HashTable {
 public:
  // constructor that takes number of entries as input
  explicit HashTable(int capacity);
  // constructor override that allows initialization
  // defaults to 5*numelements passed as capacity
  explicit HashTable(HashObject *, int numElements);
  HashTable(const HashTable &) = delete;
  HashTable &operator=(const HashTable &) = delete;
  ~HashTable();
  void Put(HashObject *);
  // override that calls above
  void Put(std::string key, std::string value);
  auto Get(std::string key) -> std::string;
  auto GetKeys() -> std::vector<std::string>;
  auto GetValues() -> std::vector<std::string>;
  void Remove(std::string key);
  void Update(std::string key, std::string value);

 private:
  // array of HashObjects as data
  HashObject *data_;
  // number of elements in table
  int capacity_;
  // hash function to estimate the index
  auto Hash(std::string key) -> int;
  // return internal index of key if found, -1 otherwise
  auto _Exists(std::string key) -> int;
};

}  // namespace rp

#endif  // RHashTable NOLINT
