#ifndef RTreeElement  //NOLINT
#define RTreeElement 

// Copyright 2020 <randypalusz>

namespace rp {
template <typename T>
class TreeElement {
 public:
  explicit TreeElement(T data) {
		data_ = data;
		left_ = nullptr;
		right_ = nullptr;
		parent_ = nullptr;
	}
  TreeElement() { 
    data_ = 0;
    left_ = nullptr;
    right_ = nullptr;
    parent_ = nullptr;  
  }
	~TreeElement() = default;
	auto getData() -> T { return data_; }
	auto getLeft() -> TreeElement* { return left_; }
	auto getRight() -> TreeElement* { return right_; }
	void setLeft(TreeElement* left) { left_ = left; }
  void setRight(TreeElement* right) { right_ = right; }
	void updateData(T data) { data_ = data; }	
 private:
	 TreeElement* left_;
	 TreeElement* right_;
	 TreeElement* parent_;
	 T data_;
};
}  // namespace rp

#endif  // RTreeElement //NOLINT
