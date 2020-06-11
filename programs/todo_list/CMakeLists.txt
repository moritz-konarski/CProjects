cmake_minimum_required(VERSION 3.16)
project(todo_list)

set(CMAKE_CXX_STANDARD 20)

find_package(Curses REQUIRED)

include_directories(
        "list_elements"
        "./lists"
        ${CURSES_INCLUDE_DIR}
)

set(SOURCES
        list_elements/list_item.hpp
        list_elements/list_section.hpp
        list_elements/todo_list.hpp
        list_elements.hpp

        io_elements/cli_io.hpp
        io_elements.hpp
        )

add_executable(todo_list ${SOURCES} main.cpp)
target_link_libraries(todo_list ${CURSES_LIBRARIES})

#add_executable(10_game_test ${AUR_SOURCES} tests/10_game_test.cpp)
#target_link_libraries(
#       10_game_test
#      ${SDL2_LIBRARIES}
#       ${SDL2-IMAGE_LIBRARIES}
#       ${GL_LIBRARIES}
#       ${GLEW_LIBRARIES}
#       ${GLM_LIBRARIES}
#)

