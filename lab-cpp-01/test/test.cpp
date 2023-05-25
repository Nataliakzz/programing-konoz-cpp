#include "gtest/gtest.h"
#include "../src/school.h"
#include "../src/list.h"

TEST(Programing01cpp, Sort_by_Amount_of_students) {
    size_t N = 3;
    List *list = new List();
    list->schools = new School*[N];
    for (size_t i = 0; i < N; i++) {
        list->schools[i] = new School();
    }
    list->size = N;
    list->schools[0]->setAmount_of_students(1250);
    list->schools[1]->setAmount_of_students(1330);
    list->schools[2]->setAmount_of_students(360);
    list->Sort_by_Amount_of_students();
    EXPECT_EQ(list->schools[0]->getAmount_of_students(), 360);
    EXPECT_EQ(list->schools[1]->getAmount_of_students(), 1250);
    EXPECT_EQ(list->schools[2]->getAmount_of_students(), 1330);
    delete list;
}

TEST(Programing01cpp, Look_for_school_with_free_education) {
    size_t N = 3;
    List* list = new List();
    list->schools = new School*[N];
    
    for (size_t i = 0; i < N; i++) {
        list->schools[i] = new School();
    }
    
    list->size = N;
    list->schools[0]->setIsEducationFree(false);
    list->schools[1]->setIsEducationFree(true);
    list->schools[2]->setIsEducationFree(true);
    
    School* school_1 = list->schools[1];
    School* school_2 = list->schools[2];
    
    List* school_with_free_education = new List();
    school_with_free_education->size = 0;
    school_with_free_education->Look_for_school_with_free_education();
    
    ASSERT_EQ(school_with_free_education->size, 2);
    EXPECT_EQ(school_with_free_education->schools[0], school_1);
    EXPECT_EQ(school_with_free_education->schools[1], school_2);
    
    delete school_with_free_education;

    for (size_t i = 0; i < N; i++) {
        delete list->schools[i];
    }
    delete[] list->schools;
    delete list;
}
