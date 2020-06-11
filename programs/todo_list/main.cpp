#include <iostream>
#include <fstream>
#include "list_elements.hpp"
#include "io_elements.hpp"
#include <ncurses.h>

int main(int argc, char **argv) {

    io_elements::initialize_renderer();

    //io_elements::game_test();

    io_elements::print_line(10, "Hello World", io_elements::Color_Combination::WHITE_BLACK);
    io_elements::print_line(11, "Hello World Again", io_elements::Color_Combination::BLACK_WHITE);
    getch();
    io_elements::highlight_line(10, io_elements::Color_Combination::BLACK_WHITE);
    getch();



    /*
    printw("Hello, World!");
    refresh();
    getch();
    using namespace std;

    auto todo_list = std::make_shared<ToDo_List>();
    Command_Type command = None;

    cout << "Welcome to ToDo List" << endl;

    while(command != Exit) {
        command = process_input();

        process_command(todo_list, command);
    }

    // create a basic window that pops up
    // file reading class

    std::ofstream myfile;
    myfile.open ("../lists/example.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();
    */

    io_elements::close_renderer();

    return 0;
}
