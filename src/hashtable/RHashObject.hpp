#ifndef RHashObject  // NOLINT
#define RHashObject

// Copyright 2020 <randypalusz>

#include <string>

namespace rp {
class HashObject {
 public:
  // using strings for now
  HashObject() {}
  ~HashObject() {}
  void SetKey(std::string key) { key_ = key; }
  void SetValue(std::string value) { value_ = value; }
  void SetKeyValue(std::string key, std::string value) {
    key_ = key;
    value_ = value;
  }
  static auto GetEmptyKey() -> std::string { return "K_EMPTY"; }
  static auto GetEmptyValue() -> std::string { return "V_EMPTY"; }
  void SetEmpty() {
    key_ = GetEmptyKey();
    value_ = GetEmptyValue();
  }
  // public method to return this instance's value for the spec'd key
  auto GetValue() -> std::string { return value_; }
  auto GetKey() -> std::string { return key_; }

 private:
  std::string key_;
  std::string value_;
};

}  // namespace rp

#endif  // RHashObject NOLINT