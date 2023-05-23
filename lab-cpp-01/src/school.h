#ifndef __SCHOOL_H__
#define __SCHOOL_H__
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

/**
 * Коли починається навчання standard (8:00), later_than_standard (8:30), second_shift (14:30)
 */
enum The_beginning_of_the_school_day {
    standard, later_than_standard, second_shift
};

/**
 * Голова інституту
 */
struct Head_of_the_institution {
    char last_name[20]; /**< Прізвище         */
    char name[20];      /**< Ім'я             */
    char mail[50];      /**< Електронна пошта */
};

/**
 * Школи
 */
class School {
    bool IsEducationFree;                       /**< Безкоштовне навчання чи ні */
    char Name [100];                            /**< Назва закладу              */
    size_t Amount_of_students;                  /**< Кількість студентів        */
    struct Head_of_the_institution head;        /**< Голова закладу             */
    enum The_beginning_of_the_school_day Begin; /**< Початок занять             */
public:
    School() : IsEducationFree(false), Name("No"), Amount_of_students(0), head({"No", "No", "No"}), Begin(standard) { }

    School(const School& other) : IsEducationFree(other.IsEducationFree), Amount_of_students(other.Amount_of_students),
                                  head(other.head), Begin(other.Begin){
        strcpy (Name, other.Name);
    }

    School(bool IsEducationFree, const char* Name, size_t Amount_of_students, Head_of_the_institution head, The_beginning_of_the_school_day Begin) :
IsEducationFree(IsEducationFree), Amount_of_students(Amount_of_students), head(head), Begin(Begin){
        strcpy (this->Name, Name);
    }
    ~School(){

    }
    size_t getAmount_of_students() const;
    bool getIsEducationFree() const;
    void Print_Me () const;
    void Write_To_File (FILE *file) const;
};
School * Parse_School (char *line);
#endif