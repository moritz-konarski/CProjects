cmake_minimum_required(VERSION 3.16)
project(todo_list)

set(CMAKE_CXX_STANDARD 20)

#include(FindPkgConfig)
#pkg_search_module(SDL2-IMAGE REQUIRED SDL2_image)

include_directories(
#        ${SDL2-IMAGE_INCLUDE_DIRS}
        "./elements"
        "./lists"
)

set(SOURCES
        elements/list_item.hpp
        elements/list_section.hpp
        elements/todo_list.hpp
        elements.hpp
        )

add_executable(todo_list ${SOURCES} main.cpp)

#add_executable(10_game_test ${AUR_SOURCES} tests/10_game_test.cpp)
#target_link_libraries(
 #       10_game_test
 #      ${SDL2_LIBRARIES}
 #       ${SDL2-IMAGE_LIBRARIES}
 #       ${GL_LIBRARIES}
 #       ${GLEW_LIBRARIES}
 #       ${GLM_LIBRARIES}
#)

