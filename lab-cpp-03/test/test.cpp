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
