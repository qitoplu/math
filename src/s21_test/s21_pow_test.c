#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"
#include "test_cases.h"

#define size_a(x) (sizeof(x) / sizeof((x)[0]))

START_TEST(test_s21_math_pow_usual) {
  ck_assert_ldouble_eq_tol(s21_pow(15, 5), pow(15, 5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-15, 5), pow(-15, 5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(15, -5), pow(15, -5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2, -2), pow(2, -2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 6), pow(0, 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(12.456, -5), pow(12.456, -5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(75, 0.5), pow(75, 0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(30, 1.7), pow(30, 1.7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(30, -1.7), pow(30, -1.7), 1e-6);
  ck_assert_double_nan(s21_pow(-3, 1.4));
  for (double i = 0.0; i < 10.0; i += 0.1) {
    for (double j = 0.0; j < 10.0; j += 0.1) {
      ck_assert_ldouble_eq_tol(s21_pow(i, j), pow(i, j), 1e-4);
    }
  }
}
END_TEST

START_TEST(test_s21_math_pow_big) {
  int base = 87652;
  double exp1 = 0.0005;
  int exp3 = 0;
  int exp5 = -4;
  double exp6 = S21_NAN;
  double exp7 = S21_NAN;

  ck_assert_ldouble_eq_tol(s21_pow(base, exp1), pow(base, exp1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base, exp3), pow(base, exp3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base, exp5), pow(base, exp5), 1e-6);
  ck_assert_ldouble_nan(s21_pow(base, exp6));
  ck_assert_ldouble_nan(s21_pow(base, exp7));

  ck_assert_ldouble_nan(s21_pow(0.0, exp6));
}
END_TEST

START_TEST(test_s21_math_pow_small) {
  double base = 0.045555632057;
  double exp1 = 0.0005;
  int exp2 = 439;
  int exp3 = 0;
  int exp4 = 44;

  ck_assert_ldouble_eq_tol(s21_pow(base, exp1), pow(base, exp1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base, exp2), pow(base, exp2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base, exp3), pow(base, exp3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base, exp4), pow(base, exp4), 1e-6);
}
END_TEST

START_TEST(test_s21_math_pow_cases_should_return_inf) {
  for (size_t i = 0; i < size_a(cases_pow_return_inf); i++) {
    double base = cases_pow_return_inf[i][0];
    double exp = cases_pow_return_inf[i][1];
    ck_assert_ldouble_infinite(s21_pow(base, exp));
  }
}
END_TEST

START_TEST(test_s21_math_pow_cases_should_return_one) {
  for (size_t i = 0; i < size_a(cases_pow_return_one); i++) {
    double base = cases_pow_return_one[i][0];
    double exp = cases_pow_return_one[i][1];
    ck_assert_double_eq(s21_pow(base, exp), 1.0);
  }
}
END_TEST

Suite *s21_math_pow_suite() {
  Suite *s = suite_create("pow");
  TCase *tc_pow_usual = tcase_create("pow_usual");
  tcase_add_test(tc_pow_usual, test_s21_math_pow_usual);
  suite_add_tcase(s, tc_pow_usual);
  TCase *tc_pow_big = tcase_create("pow_big");
  tcase_add_test(tc_pow_big, test_s21_math_pow_big);
  suite_add_tcase(s, tc_pow_big);
  TCase *tc_pow_small = tcase_create("pow_small");
  tcase_add_test(tc_pow_small, test_s21_math_pow_small);
  suite_add_tcase(s, tc_pow_small);
  TCase *tc_pow_unusual = tcase_create("pow_unusual");
  tcase_add_test(tc_pow_unusual, test_s21_math_pow_cases_should_return_inf);
  tcase_add_test(tc_pow_unusual, test_s21_math_pow_cases_should_return_one);
  suite_add_tcase(s, tc_pow_unusual);
  return s;
}

int main() {
  int fail_number = 0;
  Suite *s = s21_math_pow_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  fail_number = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (fail_number == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
