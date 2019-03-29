/// @file vulkan.hpp
/// @brief Handler for Vulkan objects
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

#ifndef VULKAN_HPP
#define VULKAN_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class Vulkan {
  /// Connection between application and Vulkan library
  VkInstance instance;
  VkApplicationInfo app_info = {};
  VkInstanceCreateInfo create_info = {};

  int get_extensions_info(VkInstanceCreateInfo &create_info);

public:
  Vulkan() {}
  ~Vulkan() { vkDestroyInstance(instance, nullptr); }

  int create_instance();
};

#endif
