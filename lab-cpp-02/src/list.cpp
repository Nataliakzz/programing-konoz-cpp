#include "list.h"
#include <iostream>
#include <fstream>
using std :: cout;
using std :: ofstream;
using std :: ifstream;
using std :: cerr;
using std :: endl;
using std :: string;

void List :: Add_Element (size_t pos, const School *school) {
    School** New_Array = new School*[this->size + 1];
    if (pos > this->size) {
        pos = this->size;
    }
    memcpy(New_Array, this->schools, pos * sizeof(School*));
    New_Array [pos] = new School(*school);
    memcpy(New_Array + pos +1, this->schools + pos, (this->size - pos) * sizeof(School*));
    if (this->size > 0) {
        delete[] this->schools;
    }
    this->schools = New_Array;
    this->size++;
}

void List :: Delete_Element (size_t pos) {
    if (this->size == 0) 
return;
    School** New_Array = new School*[this->size - 1];
    if (pos >= this->size) {
        pos = this->size - 1;
    }
    delete this->schools[pos];
    memcpy( New_Array, this->schools, pos * sizeof(School*));
    memcpy(New_Array + pos, this->schools + pos +1, (this->size - pos -1) * sizeof(School*));
    delete[] this->schools;
    this->schools = New_Array;
    this->size--;
}

int Sort_By_Amount_of_Students_Asc(const void *a, const void *b) {
    const School *school_1 = *(const School **)a;
    const School *school_2 = *(const School **)b;

    if (school_1->getAmount_of_students() < school_2->getAmount_of_students()) {
        return -1;
    } else if (school_1->getAmount_of_students() > school_2->getAmount_of_students()) {
        return 1;
    } else {
        return 0;
    }
}

void List :: Print() const{
    cout << "List schools:" << endl;
    for (size_t i = 0; i < this->size; i++) {
        cout << this->schools [i]->To_string();
    }
}

class List* Read_To_File(const string& Name_file) {
	ifstream is (Name_file);
    if (!is.is_open()) {
        cerr << "Can't open file '" << Name_file << "' for read: " << strerror(errno) << endl;
        exit(1);
    }    
    List* list = new List();
    while (!is.eof()){
    string line;
    std :: getline (is, line);
        if (line.empty()){
        continue;
        }
    
    School* school = Parse_School(line);
    list -> Add_Element (0,school);
    delete school;
    }
   /* char* line = nullptr;
    size_t line_len = 0;
    while (getline(&line, &line_len, file) != -1) {
        if (strlen(line) == 0) {
            continue;
        }
        School* school = Parse_School(line);
        list->Add_Element(static_cast<size_t>(-1), school);
	delete school;
    }
    fclose(file);
   // delete list;*/
    return list;
}
void List :: Write__File (const string& filename) const{
	ofstream of (filename);
    if (!of.is_open()) {
        cerr << "Can't open file '" << filename << "' for write: " << strerror(errno) << endl;
        exit(1);
    }
    for (size_t i = 0; i < this->size; i++){
        this->schools[i]->Write_To_File(of);
    }
    of.close();
}

const List* List::Look_for_school_with_free_education() const {
    List* new_list = new List();

    for (size_t i = 0; i < this->size; i++) {
        School* school = this->schools[i];
        if (school->getIsEducationFree()) {
            new_list->schools[new_list->size++] = school;
        }
    }

    return new_list;

}void List :: Sort_by_Amount_of_students() {
    int (*pFunction)(const void*, const void*);
    pFunction = &Sort_By_Amount_of_Students_Asc;
    qsort(this->schools, this->size, sizeof(School *), pFunction);
}
