#ifndef __LIST_H__
#define __LIST_H__
#include "school.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

/*#include "school.h"
#include <cstdlib>
#include <cstdio>
#include <cstdbool>
#include <cstring>
#include <cerrno>*/

class List {
public:
    School ** schools;
    size_t size;
    List() : schools(nullptr), size(0) { }
    List(const List& copy) : schools(new School * [copy.size]), size(copy.size)  {
        for (size_t i = 0; i < size; i++){
            schools[i] = new School(*(copy.schools[i]));
        }
    }
    ~List(){
        for (size_t i = 0; i < size; i++){
            delete schools[i];
        }
        if (size > 0) {
            delete[] schools;
        }
    }
    void Print () const;
    void Add_Element (size_t pos, const School *school);
    void Delete_Element (size_t pos);
    void Write__File (const char * filename) const;
    void Sort_by_Amount_of_students ();
    const List* Look_for_school_with_free_education() const;
};

List * Read_To_File (const char* Name_file);

#endif
