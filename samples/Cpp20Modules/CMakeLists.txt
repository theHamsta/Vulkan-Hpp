cmake_minimum_required(VERSION 3.26)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
add_executable(CppModules)
target_sources(CppModules
	PUBLIC
	FILE_SET cxx_modules TYPE CXX_MODULES FILES
	CppModules.cpp)
vulkan_hpp__setup_vulkan_include(NAME CppModules)

set_target_properties(CppModules PROPERTIES
	CXX_STANDARD 20
	CXX_EXTENSIONS OFF)

target_link_libraries(CppModules PRIVATE
	VulkanHppModule)

if( NOT (VULKAN_HPP_SAMPLES_BUILD_ONLY_DYNAMIC AND VULKAN_HPP_SAMPLES_BUILD_WITH_LOCAL_VULKAN_HPP) )
	find_package(Vulkan REQUIRED)
	target_link_libraries(CppModules PRIVATE
		Vulkan::Vulkan)
endif()
