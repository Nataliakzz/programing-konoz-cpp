#include "gtest/gtest.h"
#include "../src/school.h"
#include "../src/warehouse.h"

#define N 3

START_TEST(test_Sort_by_Amount_of_students)
{
struct Warehouse *warehouse = malloc(sizeof(struct Warehouse));
warehouse->schools = malloc(N * sizeof(struct School));
for (size_t i = 0; i < N; i++) {
    warehouse->schools[i] = malloc(sizeof(struct School));
}
warehouse->size = N;
warehouse->schools[0]->Amount_of_students = 1250;
warehouse->schools[1]->Amount_of_students = 1330;
warehouse->schools[2]->Amount_of_students = 360;
Sort_by_Amount_of_students(warehouse);
ck_assert_msg(warehouse->schools[0]->Amount_of_students == 360, "Incorrect sorting");
ck_assert_msg(warehouse->schools[1]->Amount_of_students == 1250, "Incorrect sorting");
ck_assert_msg(warehouse->schools[2]->Amount_of_students == 1330, "Incorrect sorting");
for (size_t i = 0; i < N; i++) {
    free(warehouse->schools[i]);
}
free(warehouse->schools);
free(warehouse);
}
END_TEST

START_TEST(test_Look_for_school_with_free_education)
{
  struct Warehouse *warehouse = malloc(sizeof(struct Warehouse));
    warehouse->schools = malloc(N * sizeof(struct School));
    for (size_t i = 0; i < N; i++) {
        warehouse->schools[i] = malloc(sizeof(struct School));
    }
    warehouse->size = N;
    warehouse->schools[0]->IsEducationFree = false;
    warehouse->schools[1]->IsEducationFree = true;
    warehouse->schools[2]->IsEducationFree = true;
    struct School* school_1 = warehouse->schools [1];
    struct School* school_2 = warehouse->schools [2];
    struct Warehouse *school_with_free_education = Look_for_school_with_free_education(warehouse);
    ck_assert_int_eq(school_with_free_education->size, 2);
    ck_assert_ptr_eq(school_with_free_education->schools[0], school_1);
    ck_assert_ptr_eq(school_with_free_education->schools[1], school_2);
    for (size_t i = 0; i < N; i++) {
        free(warehouse->schools[i]);
    }
    free(warehouse->schools);
    free(warehouse);
}
END_TEST

#undef N

int main(void)
{
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("lab13");

	tcase_add_test(tc_core, test_Sort_by_Amount_of_students);
    tcase_add_test(tc_core, test_Look_for_school_with_free_education);
	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
