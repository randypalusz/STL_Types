// Copyright 2020 <randypalusz>

#include <gtest/gtest.h>
#include <IO.hpp>

class IOTests : public::testing::Test{
  void SetUp() override {

  }
  void TearDown() override {

  }
};

TEST_F(IOTests, SpeakTest) {
  Speaker s{};
  auto str = s.speak("Test, ");
  EXPECT_EQ(str, "Test, ... plus this!");
}

TEST_F(IOTests, AnotherOne) {
  EXPECT_EQ("this", "this");
}
