#ifndef LIST_HPP
#define LIST_HPP

#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include "item.hpp"

class List {
public:

    static List read_list(std::string name) {

    }

    static List create_list(std::string name) {

    }

    void create_item(std::string text) {
        auto item = std::make_shared<Item>(0);
        item->set_text(std::move(text));
        _items.push_back(item);
    }

    void create_sub_item(const std::shared_ptr<Item>& parent, std::string text) {
        auto item = std::make_shared<Item>(parent->get_level() + 1);
        item->set_text(std::move(text));
        parent->add_child(item);
    }

    void set_name(std::string name) {
        _name = name;
    }

    std::string get_name() {
        return _name;
    }

    std::vector<std::shared_ptr<Item>> get_items() {
        return _items;
    }

    void print() {
        std::cout << _name << std::endl;

        for (auto &item : _items) {
            item->print();
        }
    }


private:
    std::string _name;
    std::vector<std::shared_ptr<Item>> _items;
};

#endif
