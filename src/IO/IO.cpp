// Copyright 2020 <randypalusz>

#include <string>
#include <iostream>
#include "IO.hpp"

auto Speaker::speak(std::string s) -> std::string {
  s.append("... plus this!");
  std::cout << s << std::endl;
  return s;
}
