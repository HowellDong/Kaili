#include "kaili.h"

#include <iostream>
#include <vulkan/vulkan.h>
#include <vector>

glm::vec3 add(const glm::vec3& l, const glm::vec3& r)
{
	return l + r;
}

void print_vk_extension_and_layer()
{
	VkApplicationInfo app_info{};
	app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	app_info.pNext = nullptr;
	app_info.pApplicationName = "create_instance";
	app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.pEngineName = "vulkan_example";
	app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.apiVersion = VK_API_VERSION_1_3;

	VkInstanceCreateInfo instance_create_info{};
	instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instance_create_info.pNext = nullptr;
	instance_create_info.flags = 0;
	instance_create_info.pApplicationInfo = &app_info;
	instance_create_info.enabledLayerCount = 0;
	instance_create_info.ppEnabledLayerNames = nullptr;
	instance_create_info.enabledExtensionCount = 0;
	instance_create_info.ppEnabledExtensionNames = nullptr;

	VkInstance vk_instance = VK_NULL_HANDLE;
	VkResult vk_res = vkCreateInstance(&instance_create_info, nullptr, &vk_instance);
	if (vk_res != VK_SUCCESS)
	{
		std::cerr << "failed to create vulkan instance " << std::endl;
	}

	uint32_t extension_count = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extension_count, nullptr);
	std::vector<VkExtensionProperties> extension_properties{ extension_count };
	vkEnumerateInstanceExtensionProperties(nullptr, &extension_count, extension_properties.data());

	std::cout << "instance extensions: " << std::endl;
	for (const auto& extension : extension_properties)
	{
		std::cout << extension.extensionName << std::endl;
	}
	std::cout << std::endl;

	uint32_t layer_count = 0;
	vkEnumerateInstanceLayerProperties(&layer_count, nullptr);
	std::vector<VkLayerProperties> layer_properties{ layer_count };
	vkEnumerateInstanceLayerProperties(&layer_count, layer_properties.data());

	std::cout << "instance layer" << std::endl;
	for (const auto& layer : layer_properties)
	{
		std::cout << layer.layerName << std::endl;
	}
	std::cout << std::endl;
}
