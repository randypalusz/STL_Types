// Copyright 2020 <randypalusz>

#include <gtest/gtest.h>
#include "../src/Example/Example.hpp"

class ExampleTests : public::testing::Test{
 protected:
  ExampleTests() {}
};

TEST_F(ExampleTests, DemonstrateGTestMacros) {
  Example ex{};
  int i = ex.test_method();
  EXPECT_EQ(i, 3);
}

TEST_F(ExampleTests, AnotherOne) {
  EXPECT_EQ("that", "that");
}
