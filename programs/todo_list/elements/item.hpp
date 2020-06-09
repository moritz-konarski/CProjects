#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <memory>
#include <vector>
#include <iostream>

class Item {
public:

    explicit Item(unsigned int level) {
        _level = level;
        switch (_level) {
            case 0:
                _enumeration_sign = "- ";
                break;
            case 1:
                _enumeration_sign = "+ ";
                break;
            case 2:
                _enumeration_sign = "* ";
                break;
            default:
                _enumeration_sign = ". ";
                break;
        }
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

    std::vector<std::shared_ptr<Item>> get_children() {
        return _children;
    }

    void add_child(std::shared_ptr<Item> child) {
        _children.push_back(child);
    }

    bool is_checked() {
        return _is_checked;
    }

    void set_checked(bool is_checked) {
        _is_checked = is_checked;
    }

    void print() {
        for (int i = 0; i < _level; ++i) {
            std::cout << "\t";
        }

        std::cout << _enumeration_sign << _text << std::endl;

        if (!_children.empty()) {
            for (auto &child : _children) {
                child->print();
            }
        }
    }

private:
    bool _is_checked = false;
    unsigned int _level;
    std::string _text;
    std::string _enumeration_sign;
    std::vector<std::shared_ptr<Item>> _children;
};

#endif