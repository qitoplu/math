#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(test_s21_math_asin_usual) {
  ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.32323), asin(0.32323), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.32323), asin(-0.32323), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.0003), asin(0.0003), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.0003), asin(-0.0003), 1e-6);
  ck_assert_ldouble_nan(s21_asin(3.0));
}
END_TEST

Suite *s21_math_asin_suite() {
  Suite *s = suite_create("s21_asin");
  TCase *tc_asin_usual = tcase_create("s21_asin_usual");
  tcase_add_test(tc_asin_usual, test_s21_math_asin_usual);
  suite_add_tcase(s, tc_asin_usual);
  return s;
}

int main() {
  int fail_number = 0;
  Suite *s = s21_math_asin_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  fail_number = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (fail_number == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
