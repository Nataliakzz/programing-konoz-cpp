#include "school.h"

void School :: Print_Me() const{
    char symbol = '+';
    if (this->IsEducationFree){
        symbol = '+';
    } else { symbol = '-';}
    printf("--------------------------------------------------------------------------\n");
    printf(" Name of the institution: %s\n", this -> Name);
    printf(" Head of the institution: %s %s, %s\n", this ->head.name, this ->head.last_name, this ->head.mail);
    printf(" Free education: %c\n", symbol);
    printf(" Amount of students:%lu\n", this -> Amount_of_students);
    printf(" What time do classes start: %s\n", this -> Begin == standard ? "8:00" : this -> Begin == second_shift ? "14:00" : "8:30");
    printf("--------------------------------------------------------------------------\n\n");
}


void School :: Write_To_File(FILE *file) const{
    fprintf(file, "%s, %d, %lu, %s, %s, %s, %d\n", this->Name, this->IsEducationFree,
            this->Amount_of_students, this ->head.name, this ->head.last_name, this ->head.mail, this->Begin);
}

School * Parse_School (char *line) {
    char name [50];
    Head_of_the_institution Head;
    The_beginning_of_the_school_day Begin;

    char *token = strtok(line, ",");
    strcpy(name, token);
    token = strtok(0, ",");
    bool is_education_free = strtol(token, NULL, 10);
    token = strtok(0, ",");
    size_t amount_of_students = static_cast<size_t>(strtol(token, NULL, 10));
    token = strtok(0, ",");
    strcpy(Head.name, token);
    token = strtok (0, ",");
    strcpy(Head.last_name, token);
    token = strtok(0, ",");
    strcpy(Head.mail, token);
    token = strtok(0, ",");
    Begin = static_cast<The_beginning_of_the_school_day>(strtol(token, NULL, 10));
    School *school = new School (is_education_free,name,amount_of_students,Head, Begin);
    return school;
}

size_t School :: getAmount_of_students() const{
    return this->Amount_of_students;
}

bool School :: getIsEducationFree() const {
    return this->IsEducationFree;
}