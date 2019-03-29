/// @file vulkan.cpp
/// @brief Source file for Vulkan Instance
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

#include "vulkan.hpp"

int Vulkan::get_extensions_info(VkInstanceCreateInfo &create_info) {
	uint32_t glfw_extension_count = 0;
	const char **glfw_extensions = nullptr;

	glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

	if ((glfw_extensions == nullptr) || (glfw_extension_count == 0))
		return -1;
	create_info.enabledExtensionCount = glfw_extension_count;
	create_info.ppEnabledExtensionNames = glfw_extensions;
	return 1;
}

int Vulkan::create_instance() {
	VkResult rc;
	VkApplicationInfo app_info = {};
	VkInstanceCreateInfo create_info = {};

	app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	app_info.pApplicationName = "Hello Triangle";
	app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.pEngineName = "No Engine";
	app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.apiVersion = VK_API_VERSION_1_0;

	create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	create_info.pApplicationInfo = &app_info;

	if (get_extensions_info(create_info) < 1)
		return -1;
	if ((rc = vkCreateInstance(&create_info, nullptr, &instance)) !=
			VK_SUCCESS) {
		return -2;
	}

	return 1;
}
