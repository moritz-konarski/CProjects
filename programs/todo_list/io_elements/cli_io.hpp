#ifndef CLI_IO_HPP
#define CLI_IO_HPP

#include <ncurses.h>
#include <regex>
#include <string>
#include "../list_elements.hpp"

// to turn on attributes: attron(), to turn off attroff
// mvaddch(row, cow, ch) moves and then prints the character
// mvprintw(row, cow, char[])
// getch() for single characters
// getstr() for strings
// attributes: A_BOLD, A_UNDERLINE
// mvchgat(row, col, <n chars, -1 to eol>, <attribute(s)>, <color index from init_pair(), NULL)
// for color: start_color(), then init_pair for a pair of foreground and background colors

namespace io_elements {

    enum Color_Combination {
        WHITE_BLACK,
        BLACK_WHITE
    };

    void define_color_pairs() {
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_BLACK, COLOR_WHITE);
    }

    NCURSES_COLOR_T convert_enum_to_color_type(Color_Combination color_combination) {
        switch (color_combination) {
            case WHITE_BLACK:
                return COLOR_PAIR(1);
                break;
            case BLACK_WHITE:
                return COLOR_PAIR(2);
                break;
        }
    }

    int row, col;

    void initialize_renderer() {
        initscr();
        noecho();
        cbreak();
        keypad(stdscr, TRUE);
        getmaxyx(stdscr, row, col);
        if (has_colors() == FALSE) {
            endwin();
            printf("Your terminal does not support color\n");
            exit(1);
        }
        start_color();
        define_color_pairs();
    }

    void print_line(int line, std::string text, Color_Combination color) {
        attron(convert_enum_to_color_type(color));
        mvprintw(line, 0, text.c_str());
        mvhline(line, text.length(), ' ', COLS);
        attroff(convert_enum_to_color_type(color));
        refresh();
    }

    void highlight_line(int line, Color_Combination color) {
        char string[100];
        mvgetstr(line, 0, string);
        attron(convert_enum_to_color_type(color));
        //mvchgat(line, 0, -1, A_BOLD, convert_enum_to_color_type(color), NULL);
        mvprintw(line, 0, string);
        attroff(convert_enum_to_color_type(color));
        refresh();
    }

    void game_test() {
        attron(COLOR_PAIR(1));
        for (int i = 0; i < row; ++i) {
            mvhline(i, 0, '-', COLS);
        }
        attroff(COLOR_PAIR(1));
        getch();
    }


    void close_renderer() {
        endwin();
    }

    enum Command_Type {
        None,
        New_List_Section,
        Delete_List_Section,
        Increase_Level,
        Decrease_Level,
        Print_List,
        Print_All_Lists,
        Exit,
        Help,
        Show_Environment,
        Write,
        Modify
    };

    const static std::string command_list[]{
            "mklst",
            "rm",
            "inc",
            "dec",
            "ls",
            "la",
            "exit",
            "h",
            "pwd",
            "w",
            "m"
    };
    const static std::string command_list_help[]{
            "create new list, mklst <name>",
            "delete element",
            "increase indentation",
            "decrease indentation",
            "show current list",
            "show all lists",
            "exit program",
            "show help",
            "show current environment",
            "write changes",
            "modify environment"
    };
    const static Command_Type command_type_list[]{
            New_List_Section,
            Delete_List_Section,
            Increase_Level,
            Decrease_Level,
            Print_List,
            Print_All_Lists,
            Exit,
            Help,
            Show_Environment,
            Write,
            Modify
    };

    bool is_match(const std::string input, const std::string regex) {
        return std::regex_match(input, std::regex(regex));
    }

    void process_command(std::shared_ptr<list_elements::ToDo_List> list,
                         Command_Type command) {
        using namespace std;
        switch (command) {
            case New_List_Section: {
                string name;
                cin >> name;
                list->create_new_section(name);
                break;
            }
            case Exit:
                break;
            case Help:
                for (int i = 0; i < size(command_list); ++i) {
                    printf("%5s : %s\n", command_list[i].c_str(),
                           command_list_help[i].c_str());
                }
                break;
            case Print_All_Lists:
                list->print();
                break;
            default:
                cout << "Command not supported\nType h for help" << endl;
                break;
        }
    }

    Command_Type process_input() {
        using namespace std;
        Command_Type command = None;
        cout << "$> ";
        string input;
        cin >> input;
        std::transform(input.begin(), input.end(), input.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        for (int i = 0; i < size(command_list); ++i)
            if (is_match(input, command_list[i]))
                command = command_type_list[i];

        return command;
    }

    class Renderer {

    };
}

#endif
