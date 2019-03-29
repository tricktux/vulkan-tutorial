/// @file triangle.hpp
/// @brief Header file for application
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

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

/// Wrapper around glfw window
class Window {
  /// Default window height and width
  const unsigned int HEIGHT = 800;
  const unsigned int WIDTH = 600;
  const char *TITLE = "Window Title";

  unsigned int _height = {HEIGHT};
  unsigned int _width = {WIDTH};
  bool _resizable = {false}; /// Defaults to false
  GLFWwindow *_window = nullptr;
  std::string _title = {TITLE};

public:
  /// Default constructor
  Window() {}
  Window(const std::string title) : _title(title) {}
  /// Explicit constructor
  Window(unsigned int height, unsigned int width, bool resizable,
         const std::string &title)
      : _height(height), _width(width), _resizable(resizable), _title(title) {}
  ~Window() {
    if (_window == nullptr)
      return;
    glfwDestroyWindow(_window);
    glfwTerminate();
  }

  /// Initializes window with the given properties
  bool init() {
    if (_window != nullptr)
      return true;

    glfwInit();

    /// Ensure that this is a Vulkan type of window
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    if (!_resizable)
      glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    _window =
        glfwCreateWindow(_width, _height, _title.c_str(), nullptr, nullptr);
    return (_window != nullptr);
  }

  /// Returns event that we should close
  bool should_close() const {
    if (_window == nullptr)
      return false;
    return glfwWindowShouldClose(_window);
  }

  /// Returns poll events
  auto get_poll_events() const {
    if (_window != nullptr)
      glfwPollEvents();
  }
};

#endif
