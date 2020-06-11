#ifndef LIST_HPP
#define LIST_HPP

#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include "../list_elements.hpp"

namespace list_elements {
    class List_Section {
    public:

        static List_Section read_list(std::string name) {

        }

        static List_Section create_list(std::string name) {

        }

        void create_item(std::string text) {
            auto item = std::make_shared<List_Item>(0);
            item->set_text(std::move(text));
            _items.push_back(item);
        }

        void
        create_sub_item(const std::shared_ptr<List_Item> &parent, std::string text) {
            auto item = std::make_shared<List_Item>(parent->get_level() + 1);
            item->set_text(std::move(text));
            parent->add_child(item);
        }

        void set_name(std::string name) {
            _name = name;
        }

        std::string get_name() {
            return _name;
        }

        std::vector<std::shared_ptr<List_Item>> get_items() {
            return _items;
        }

        unsigned int get_line_count() {
            return _items.size();
        }

        void print() {
            std::cout << _name << std::endl;

            for (auto &item : _items) {
                item->print();
            }
        }

    private:
        std::string _name;
        std::vector<std::shared_ptr<List_Item>> _items;
    };
}

#endif
