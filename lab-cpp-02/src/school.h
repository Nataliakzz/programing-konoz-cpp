#ifndef __SCHOOL_H__
#define __SCHOOL_H__
#include "school.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <fstream>
#include <string>
/*#include "school.h"
#include <cstdlib>
#include <cstdio>
#include <cstdbool>
#include <cstring>
#include <cerrno>*/
using std :: ofstream;
using std :: ifstream;
using std :: string;

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
    string last_name; /**< Прізвище         */
    string name;      /**< Ім'я             */
    string mail;      /**< Електронна пошта */
};

/**
 * Школи
 */
class School {
    bool IsEducationFree;                       /**< Безкоштовне навчання чи ні */
    string Name;                            /**< Назва закладу              */
    size_t Amount_of_students;                  /**< Кількість студентів        */
    struct Head_of_the_institution head;        /**< Голова закладу             */
    enum The_beginning_of_the_school_day Begin; /**< Початок занять             */
   public:
School() : IsEducationFree(false), Name("No"), Amount_of_students(0), head({"No", "No", "No"}), Begin(standard) { }

    School(const School& other) : IsEducationFree(other.IsEducationFree), Name (other.Name), Amount_of_students(other.Amount_of_students),
                                  head(other.head), Begin(other.Begin){
    }

    School(bool IsEducationFree, string Name, size_t Amount_of_students, Head_of_the_institution head, The_beginning_of_the_school_day Begin) :
IsEducationFree(IsEducationFree), Name(std :: move(Name)),  Amount_of_students(Amount_of_students), head(head), Begin(Begin){
    }
    ~School() = default;
    size_t getAmount_of_students() const;
    bool getIsEducationFree() const;
    void setAmount_of_students (size_t number);
    void setIsEducationFree (bool true_or_false);
    void Write_To_File (ofstream &of) const;
    string To_string ();
};
string Get_next_token (string& line, const string& delimiter);
School * Parse_School (const string &lineRaw);
#endif
