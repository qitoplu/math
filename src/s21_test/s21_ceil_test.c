#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

// CEIL

START_TEST(test_s21_math_ceil_usual) {
  ck_assert_ldouble_eq_tol(s21_ceil(-7.7), ceil(-7.7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(0.1), ceil(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(11.1), ceil(11.1), 1e-6);
}
END_TEST

START_TEST(test_s21_math_ceil_unusual) {
  ck_assert_double_infinite(s21_ceil(POS_INF));
  ck_assert_double_nan(s21_ceil(S21_NAN));
  ck_assert_double_infinite(s21_ceil(NEG_INF));
}
END_TEST

Suite *s21_math_ceil_suite() {
  Suite *s;
  TCase *tc_ceil_usual, *tc_ceil_unusual;
  s = suite_create("s21_ceil");
  tc_ceil_usual = tcase_create("s21_ceil_usual");
  tcase_add_test(tc_ceil_usual, test_s21_math_ceil_usual);
  suite_add_tcase(s, tc_ceil_usual);
  tc_ceil_unusual = tcase_create("s21_ceil_unusual");
  tcase_add_test(tc_ceil_unusual, test_s21_math_ceil_unusual);
  suite_add_tcase(s, tc_ceil_unusual);
  return s;
}

int main(void) {
  Suite *s;
  int failed = 0;
  SRunner *runner;
  s = s21_math_ceil_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}