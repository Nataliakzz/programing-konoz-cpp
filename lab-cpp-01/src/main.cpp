#include "school.h"
#include "list.h"
int main() {
    const size_t N = 3;
    School** schools = new School*[N];
    schools[0] = new School(true, "Gryffindor", 1250,
                            {"Gryffindor", "Godric", "school_gryffindor@gmail.com"}, later_than_standard);
    schools[1] = new School(false, "Slytherin", 1330,
                            {"Slytherin", "Salvador", "school_slytherin@gmail.com"}, standard);
    schools[2] = new School(true, "Ravenclaw", 360,
                            {"Ravenclaw", "Rowan", "school_ravenclaw@gmail.com"}, second_shift);
    for (size_t i = 0; i < N; i++) {
        schools [i]->Print_Me();
	FILE *file = fopen ("schools.txt", "a");
	if (file != nullptr) {
        schools[i]->Write_To_File(file);
	fclose(file);
	}
    }
    List *list = new List();
    list->schools = schools;
    list->size = N;
    const char Name_file[] = "schools.txt";
    list->Write__File(Name_file);
    List *read_list = Read_To_File(Name_file);
    read_list->Print();
    const List* new_list_with_free_education = read_list->Look_for_school_with_free_education();
    new_list_with_free_education->Print();
    List *new_list_with_Sort_by_Amount_of_students = new List();
    new_list_with_Sort_by_Amount_of_students = read_list;
    new_list_with_Sort_by_Amount_of_students->Sort_by_Amount_of_students();
    printf("--------------------------------------------------------------------------\n");
    printf("\n\nSchools with free education in ascending order:\n");
    new_list_with_free_education->Print();

    delete new_list_with_Sort_by_Amount_of_students;    
    delete new_list_with_free_education;    
    delete list;
    return 0;
}
