cmake_minimum_required(VERSION 3.25)

project(
    factory
)

set(CMAKE_BUILD_TYPE Debug)
set(ROOT_DIR ${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 20)

set(RAYLIB_DIR raylib)
add_subdirectory(${RAYLIB_DIR})

add_executable(${PROJECT_NAME}
		code/main.cpp
		code/state.cpp
		code/state.h
)

target_link_libraries(${PROJECT_NAME} 
raylib
)

set_property(TARGET factory PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")