#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include "../list_elements.hpp"

namespace list_elements {
    class List_Item {

    public:
        explicit List_Item(unsigned int level) {
            _level = level;
        }

        void set_level(unsigned int level) {
            _level = level;
        }

        void set_text(std::string text) {
            _text = text;
        }

        std::string get_text() {
            return _text;
        }

        unsigned int get_level() {
            return _level;
        }

        std::vector<std::shared_ptr<List_Item>> get_children() {
            return _children;
        }

        void add_child(std::shared_ptr<List_Item> child) {
            _children.push_back(child);
        }

        bool is_checked() {
            return _is_checked;
        }

        void set_checked(bool is_checked) {
            _is_checked = is_checked;
            if (!_children.empty()) {
                for (auto &child : _children) {
                    child->set_checked(is_checked);
                }
            }
        }

        void print() {
            for (int i = 0; i < _level; ++i) {
                std::cout << "\t";
            }

            if (_is_checked) {
                std::cout << _checked_sign << _text << std::endl;
            } else {
                std::cout << _unchecked_sign << _text << std::endl;
            }

            if (!_children.empty()) {
                for (auto &child : _children) {
                    child->print();
                }
            }
        }

    private:
        bool _is_checked = false;
        unsigned int _level = 0;
        std::string _text;
        std::string _checked_sign = "[x] ";
        std::string _unchecked_sign = "[ ] ";
        std::vector<std::shared_ptr<List_Item>> _children;

    };
}

#endif