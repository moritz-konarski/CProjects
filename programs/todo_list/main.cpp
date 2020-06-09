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

    auto list = make_shared<List>();
    string name;

    cout << "Enter list name: ";
    cin >> name;
    cout << endl;

    list->set_name(name);
    list->create_item("First Item");
    list->create_item("Second Item");
    list->create_sub_item(list->get_items().at(0), "First Sub Item");
    list->create_sub_item(list->get_items().at(0), "Second Sub Item");
    list->create_sub_item(list->get_items().at(0)->get_children().at(0), "First Sub Sub Item");

    list->print();

    return 0;
}
