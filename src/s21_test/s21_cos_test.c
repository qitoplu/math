#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(test_s21_math_cos_unusual) {
  int testValue1 = -100;
  int testValue2 = 1000;
  double testValue3 = 0.0001;
  double testValue4 = 0.73029579057;
  double testValue5 = S21_M_PI;
  double testValue6 = -S21_M_PI;

  ck_assert_ldouble_eq_tol(s21_cos(testValue1), cos(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(testValue2), cos(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(testValue3), cos(testValue3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(testValue4), cos(testValue4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(testValue5), cos(testValue5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(testValue6), cos(testValue6), 1e-6);
}

START_TEST(test_s21_math_cos_usual) {
  double step = 0.01;
  for (double i = -5 * S21_M_PI; i <= 5 * S21_M_PI; i += step) {
    ck_assert_ldouble_eq_tol(s21_cos(i), cos(i), 1e-6);
  }
}
END_TEST

Suite *s21_math_cos_suite() {
  Suite *s = suite_create("s21_cos");
  TCase *tc_cos = tcase_create("s21_cos");
  tcase_add_test(tc_cos, test_s21_math_cos_unusual);
  tcase_add_test(tc_cos, test_s21_math_cos_usual);
  suite_add_tcase(s, tc_cos);
  return s;
}

int main() {
  int fail_number = 0;
  Suite *s = s21_math_cos_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  fail_number = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (fail_number == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
