// Copyright 2020 <randypalusz>

#include <gtest/gtest.h>

#include <RVector.hpp>

class VectorTests : public ::testing::Test {
  void SetUp() override {
  }
  void TearDown() override {
  }
};

TEST_F(VectorTests, InitlalizeWithCapacity) {
  rp::RVector v{3};
  EXPECT_EQ(3, v.getCapacity());
  EXPECT_EQ(0, v.getSize());
}

TEST_F(VectorTests, InitializeWithoutCapcity) {
  rp::RVector v;
  EXPECT_EQ(10, v.getCapacity());
  EXPECT_EQ(0, v.getSize());
}

TEST_F(VectorTests, AccessOverload) {
  rp::RVector v;
  v.pushBack(56);
  EXPECT_EQ(56, v(0));
}

TEST_F(VectorTests, AccessAt) {
  rp::RVector v;
  v.pushBack(57);
  EXPECT_EQ(57, v.at(0));
}

TEST_F(VectorTests, AccessOutsideAt) {
  rp::RVector v;
  v.pushBack(58);
  EXPECT_EXIT(v.at(1), ::testing::ExitedWithCode(EXIT_FAILURE), "");
}

TEST_F(VectorTests, AccessOutsideOverload) {
  rp::RVector v;
  v.pushBack(58);
  EXPECT_EXIT(v(1), ::testing::ExitedWithCode(EXIT_FAILURE), "");
}

TEST_F(VectorTests, PushBackSingle) {
  rp::RVector v;
  v.pushBack(2);
  v.pushBack(3);
  v.pushBack(4);
  EXPECT_EQ(v(0), 2);
  EXPECT_EQ(v(1), 3);
  EXPECT_EQ(v(2), 4);
}

TEST_F(VectorTests, PushBackArray) {
  rp::RVector v;
  v.pushBack(new int[4]{2, 3, 4, 5}, 4);
  EXPECT_EQ(v(0), 2);
  EXPECT_EQ(v(1), 3);
  EXPECT_EQ(v(2), 4);
  EXPECT_EQ(v(3), 5);
}

TEST_F(VectorTests, PopBack) {
  rp::RVector v;
  v.pushBack(new int[5]{1, 5, 4, 2, 3}, 5);
  EXPECT_EQ(v.popBack(), 3);
  EXPECT_EQ(v.popBack(), 2);
  EXPECT_EQ(v.popBack(), 4);
  EXPECT_EQ(v.popBack(), 5);
  EXPECT_EQ(v.popBack(), 1);
  EXPECT_EXIT(v.popBack(), ::testing::ExitedWithCode(EXIT_FAILURE), "");
}

TEST_F(VectorTests, PopFront) {
  rp::RVector v;
  v.pushBack(new int[5]{1, 5, 4, 2, 3}, 5);
  EXPECT_EQ(v.popFront(), 1);
  EXPECT_EQ(v.popFront(), 5);
  EXPECT_EQ(v.popFront(), 4);
  EXPECT_EQ(v.popFront(), 2);
  EXPECT_EQ(v.popFront(), 3);
  EXPECT_EXIT(v.popFront(), ::testing::ExitedWithCode(EXIT_FAILURE), "");
}
