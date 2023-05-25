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
    FILE *file = fopen("schools.txt", "w");
    for (size_t i = 0; i < N; i++) {
        schools [i]->Print_Me();
        schools[i]->Write_To_File(file);
    }
    fclose(file);
    FILE* file_r = fopen("schools.txt", "r");
    List *read_list = Read_To_File(file_r);
    List *new_list_with_free_education = new List();
    new_list_with_free_education->Look_for_school_with_free_education();
    new_list_with_free_education->Print();
    List *new_list_with_Sort_by_Amount_of_students = new List();
    new_list_with_Sort_by_Amount_of_students->Sort_by_Amount_of_students();
    printf("--------------------------------------------------------------------------\n");
    printf("\n\nSchools with free education in ascending order:\n");
    new_list_with_free_education->Print();
    delete new_list_with_Sort_by_Amount_of_students;    
    delete new_list_with_free_education;    
    for (size_t i = 0; i < N; i++) {
        delete schools[i];
    }
    delete[] schools;
    fclose(file_r);
    return 0;
}
