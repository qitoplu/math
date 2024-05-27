#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(test_s21_math_sqrt_usual) {
  double testValue1 = 1024;
  double testValue2 = 6889;
  double testValue3 = 0;
  ck_assert_ldouble_eq_tol(s21_sqrt(testValue1), sqrt(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(testValue2), sqrt(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(25), sqrt(25), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(testValue3), sqrt(testValue3), 1e-6);
}
END_TEST

START_TEST(test_s21_math_sqrt_unusual) {
  double testValue1 = -100;
  double testValue2 = 1e6;
  double testValue3 = 0.01;
  ck_assert_double_nan(s21_sqrt(testValue1));
  ck_assert_ldouble_eq_tol(s21_sqrt(testValue2), sqrt(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(testValue3), sqrt(testValue3), 1e-6);
}
END_TEST

int main() {
  int fail_number = 0;
  Suite *s = suite_create("s21_sqrt");
  TCase *tc_sqrt_usual = tcase_create("s21_sqrt_usual");
  tcase_add_test(tc_sqrt_usual, test_s21_math_sqrt_usual);
  suite_add_tcase(s, tc_sqrt_usual);
  TCase *tc_sqrt_unusual = tcase_create("s21_sqrt_unusual");
  tcase_add_test(tc_sqrt_unusual, test_s21_math_sqrt_unusual);
  suite_add_tcase(s, tc_sqrt_unusual);
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  fail_number = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (fail_number == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}