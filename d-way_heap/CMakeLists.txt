cmake_minimum_required(VERSION 3.27)

project(a)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,cppcoreguidelines-*)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_BUILD_TYPE DEBUG)

link_directories(/opt/homebrew/lib)
include_directories(/opt/homebrew/include)

add_executable(a d-way_heap.cpp)

target_link_libraries(a PRIVATE fmt)
