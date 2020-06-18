#ifndef RListObject  //NOLINT
#define RListObject

// Copyright 2020 <randypalusz>

namespace rp {
template <typename T>
class ListObject {
 public:
  explicit ListObject(T data) {
    data_ = data;
    next_ = nullptr;
  }
  auto GetData() -> T { return data_; }
  auto GetNext() -> ListObject* { return next_; }
  void SetNext(ListObject* next) { next_ = next; }
  void SetData(T data) { data_ = data; }

 private:
  ListObject* next_;
  T data_;
};
}  // namespace rp

#endif  //RListObject //NOLINT
