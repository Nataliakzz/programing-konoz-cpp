#include "school.h"
#include "list.hpp"
#include <iostream>
#include <string>
#include <fstream>
int main() {
    using std::endl;
    List<School>* list = new List<School>();
    list->Add_Element(0, new School(true, "Gryffindor", 1250,
        {"Gryffindor", "Godric", "school_gryffindor@gmail.com"}, later_than_standard));
    list->Add_Element(1, new School(false, "Slytherin", 1330,
        {"Slytherin", "Salvador", "school_slytherin@gmail.com"}, standard));
    list->Add_Element(2, new School(true, "Ravenclaw", 360,
        {"Ravenclaw", "Rowan", "school_ravenclaw@gmail.com"}, second_shift));
    list->Print();

    list->Sort_by_Amount_of_students();
    std::cout << std::endl << std::endl << "Schools in ascending order: " << std::endl;
    list->Print();
    delete list;
    return 0;
}
