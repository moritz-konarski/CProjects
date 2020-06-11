//TODO: implement some kind of state switching system that can be used
//      to take the focus on different list sections and levels within them
#ifndef TODO_LIST_HPP
#define TODO_LIST_HPP

#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include "../list_elements.hpp"

namespace list_elements {

    struct Environment_Struct {
        unsigned int list_section_number;
        unsigned int section_line_number;
    };

    class ToDo_List {
    public:
        void create_new_section(std::string name) {
            auto list_section = std::make_shared<List_Section>();
            list_section->set_name(name);
            _list_sections.push_back(list_section);
            _environment.list_section_number = _list_sections.size();
            _environment.section_line_number = 1;
        }

        void switch_to_section(unsigned int section_number) {
            // TODO: check if exists
            _environment.list_section_number = section_number;
        }

        void switch_to_line_number(unsigned int section_line_number) {
            // TODO: check if exists
            _environment.section_line_number = section_line_number;
        }

        void print() {
            for (auto &list_section : _list_sections) {
                list_section->print();
            }
        }

    private:
        std::vector<std::shared_ptr<List_Section>> _list_sections;
        Environment_Struct _environment;

        bool _section_exists(unsigned int section_number) {
            return section_number <= _list_sections.size();
        }

        bool _line_exists(unsigned int line_number) {
            auto list_section = _list_sections.at(_environment.list_section_number);
            return line_number <= list_section->get_line_count();
        }
    };
}

#endif
