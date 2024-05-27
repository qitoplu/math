#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(test_s21_math_fabs_usual) {
  double testValue1 = -6.5325;
  double testValue2 = 7.0;
  double testValue3 = 0;
  ck_assert_ldouble_eq(s21_fabs(testValue1), fabs(testValue1));
  ck_assert_ldouble_eq(s21_fabs(testValue2), fabs(testValue2));
  ck_assert_ldouble_eq(s21_fabs(testValue3), fabs(testValue3));
}
END_TEST

START_TEST(test_s21_math_fabs_unusual) {
  double testValue1 = -12.343452;
  double testValue2 = 23.6;
  double testValue3 = 0.0;
  ck_assert_ldouble_eq(s21_fabs(testValue1), fabs(testValue1));
  ck_assert_ldouble_eq(s21_fabs(testValue2), fabs(testValue2));
  ck_assert_ldouble_eq(s21_fabs(testValue3), fabs(testValue3));
}
END_TEST

Suite *s21_math_fabs_suite() {
  Suite *s = suite_create("s21_fabs");
  TCase *tc_fabs_usual = tcase_create("s21_fabs_usual");
  tcase_add_test(tc_fabs_usual, test_s21_math_fabs_usual);
  suite_add_tcase(s, tc_fabs_usual);
  TCase *tc_fabs_unusual = tcase_create("s21_fabs_unusual");
  tcase_add_test(tc_fabs_unusual, test_s21_math_fabs_unusual);
  suite_add_tcase(s, tc_fabs_unusual);
  return s;
}

int main() {
  int fail_number = 0;
  Suite *s = s21_math_fabs_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  fail_number = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (fail_number == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}