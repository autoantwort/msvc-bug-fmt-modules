cmake_minimum_required(VERSION 3.31)

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "4.0.0")
    set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444") # 4.0.3
else()
    set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508") # 3.31.0
endif()
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

project(vs-bug LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_MODULE_STD 1)

find_package(fmt CONFIG REQUIRED)

add_library(error STATIC)

target_link_libraries(error PUBLIC fmt::fmt)

target_sources(
    error
    PUBLIC
        FILE_SET CXX_MODULES
            FILES #
                "lib.ixx"
)

add_executable(test_exe main.cpp )
target_link_libraries(test_exe PRIVATE error)
