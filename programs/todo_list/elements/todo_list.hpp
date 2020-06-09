//TODO: implement some kind of state switching system that can be used
//      to take the focus on different list sections and levels within them
#ifndef TODO_LIST_HPP
#define TODO_LIST_HPP

#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include "../elements.hpp"

class ToDo_List {
public:
    std::shared_ptr<List_Section> create_new_section(std::string name) {
        auto list_section = std::make_shared<List_Section>();
        list_section->set_name(name);
        _list_sections.push_back(list_section);
        return list_section;
    }

    void print() {
        for (auto &list_section : _list_sections) {
            list_section->print();
        }
    }

private:
    std::vector<std::shared_ptr<List_Section>> _list_sections;
    unsigned int _list_state;
};

#endif
