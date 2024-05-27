#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(test_s21_math_tan) {
  int testValue1 = 1000;
  int testValue2 = -1000;
  double testValue3 = 0.0005;
  double testValue4 = 0.693792572975;
  double testValue5 = S21_M_PI;

  ck_assert_ldouble_eq_tol(s21_tan(testValue1), tan(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(testValue2), tan(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(testValue3), tan(testValue3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(testValue4), tan(testValue4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(testValue5), tan(testValue5), 1e-6);
}
END_TEST

Suite *s21_math_tan_suite() {
  Suite *s = suite_create("s21_tan");
  TCase *tc_tan = tcase_create("s21_tan");
  tcase_add_test(tc_tan, test_s21_math_tan);
  suite_add_tcase(s, tc_tan);
  return s;
}

int main() {
  int fail_number = 0;
  Suite *s;
  s = s21_math_tan_suite();
  SRunner *runner;
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  fail_number = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (fail_number == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
