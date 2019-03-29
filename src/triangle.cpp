/// @file triangle.cpp
/// @brief Tutorial Triangle App
/// @author Reinaldo Molina
/// @version  0.0
/// @date Mar 29 2019

#include <cstdlib>
#include <functional>
#include <iostream>
#include <stdexcept>

#include "triangle.hpp"

int main() {
  try {
		Window window("Triangle App");
		if (!window.init()) {
			std::cerr << "Failed to initialize glfw window" << std::endl;
			return 1;
		}

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
