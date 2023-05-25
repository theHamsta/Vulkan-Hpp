module;
#include <vulkan/vulkan.hpp>

export module vulkan;

export namespace vk
{
  using vk::ApplicationInfo;
  using vk::createInstance;
  using vk::InstanceCreateInfo;
  using vk::Instance;
  using vk::SystemError;
}  // namespace vk
