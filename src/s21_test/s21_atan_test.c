#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(test_s21_math_atan_usual) {
  ck_assert_ldouble_eq_tol(s21_atan(1.0), atan(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.1), atan(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1.0), atan(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1000.0), atan(1000.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1000.0), atan(-1000.0), 1e-6);

  ck_assert_ldouble_eq_tol(s21_atan(-0.95), atan(-0.95), 1e-6);

  ck_assert_ldouble_eq_tol(s21_atan(NEG_INF), atan(NEG_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(POS_INF), atan(POS_INF), 1e-6);
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
}
END_TEST

Suite *s21_math_atan_suite() {
  Suite *s = suite_create("s21_atan");
  TCase *tc_atan_usual = tcase_create("s21_atan_usual");
  tcase_add_test(tc_atan_usual, test_s21_math_atan_usual);
  suite_add_tcase(s, tc_atan_usual);
  return s;
}

int main() {
  int fail_number = 0;
  Suite *s;
  s = s21_math_atan_suite();
  SRunner *runner;
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  fail_number = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (fail_number == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
