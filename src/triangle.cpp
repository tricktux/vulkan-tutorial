/// @file triangle.cpp
/// @brief Tutorial Triangle App
/// @author Reinaldo Molina
/// @version  0.0
/// @date Mar 29 2019
// Copyright © 2019 Reinaldo Molina

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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

	while (!window.should_close())
		window.get_poll_events();

	return 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
