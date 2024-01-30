# CMakeList.txt : CMake project for vulkan_example, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library(kaili STATIC "src/kaili.cpp")

target_link_libraries(kaili PUBLIC glm::glm Vulkan::Vulkan)
target_include_directories(kaili PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_compile_definitions(GLM_FORCE_AVX2 GLM_FORCE_ALIGNED_GENTYPES)

set_property(TARGET kaili PROPERTY CXX_STANDARD 23)

# TODO: Add tests and install targets if needed.