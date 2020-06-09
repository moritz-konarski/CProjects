#include <iostream>
#include <fstream>
#include "elements.hpp"

int main(int argc, char **argv) {

    using namespace std;

    // create a basic window that pops up
    // file reading class

    /*
    std::ofstream myfile;
    myfile.open ("../lists/example.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();
     */

    auto todo_list = make_shared<ToDo_List>();
    string name;

    cout << "Enter list name: ";
    cin >> name;
    cout << endl;

    auto list = todo_list->create_new_section("test _section");

    list->set_name(name);
    list->create_item("First List_Item");
    list->create_item("Second List_Item");
    list->create_sub_item(list->get_items().at(0), "First Sub List_Item");
    list->create_sub_item(list->get_items().at(0), "Second Sub List_Item");
    list->create_sub_item(list->get_items().at(0)->get_children().at(0), "First Sub Sub List_Item");

    list->get_items().at(0)->get_children().at(0)->set_checked(true);

    todo_list->print();

    return 0;
}
