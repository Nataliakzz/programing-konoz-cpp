#include "gtest/gtest.h"
#include "../src/school.h"
#include "../src/list.h"


#define N 3

TEST(Programing01cpp, Sort_by_Amount_of_students) {
List *list = new List();
list->schools = new School[N];
for (size_t i = 0; i < N; i++) {
    list->schools[i] = new School;
}list->size = N;
list->schools[0]->Amount_of_students = 1250;
list->schools[1]->Amount_of_students = 1330;
list->schools[2]->Amount_of_students = 360;
list->Sort_by_Amount_of_students;
EXPECT_EQ(list->schools[0]->Amount_of_students, 360);
EXPECT_EQ(list->schools[1]->Amount_of_students, 1250);
EXPECT_EQ(list->schools[2]->Amount_of_students, 1330);
for (size_t i = 0; i < N; i++) {
    delete list->schools[i];
}
delete[] list->schools;
delete list;
}

TEST(Programing01cpp ,Look_for_school_with_free_education)
{
  List *list = new List();
    list->schools = new School[N];
    for (size_t i = 0; i < N; i++) {
        list->schools[i] = new School;
    }
    list->size = N;
    list->schools[0]->IsEducationFree = false;
    list->schools[1]->IsEducationFree = true;
    list->schools[2]->IsEducationFree = true;
    School* school_1 = list->schools [1];
    School* school_2 = list->schools [2];
    List *school_with_free_education->Look_for_school_with_free_education;
    ASSERT_EQ(school_with_free_education->size, 2);
    EXPECT_EQ(school_with_free_education->schools[0], school_1);
    EXPECT_EQ(school_with_free_education->schools[1], school_2);    
    for (size_t i = 0; i < N; i++) {
    delete warehouse->schools[i];
}
delete[] warehouse->schools;
delete warehouse;}
END_TEST

#undef N

