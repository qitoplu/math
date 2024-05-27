#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

START_TEST(test_s21_math_fmod_usual) {
  double testValueX1 = -5;
  double testValueY1 = 2;
  double testValueX2 = -24;
  double testValueY2 = 1;
  double testValueX3 = 134.2;
  double testValueY3 = 0.7;
  ck_assert_ldouble_eq_tol(s21_fmod(testValueX1, testValueY1),
                           fmod(testValueX1, testValueY1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(testValueX2, testValueY2),
                           fmod(testValueX2, testValueY2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(testValueX3, testValueY3),
                           fmod(testValueX3, testValueY3), 1e-6);

  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
}
END_TEST

START_TEST(test_s21_math_fmod_unusual) {
  double testValueX1 = 0;
  double testValueY1 = 0;
  double testValueX2 = 1;
  double testValueY2 = 0;
  double testValueX3 = 100;
  double testValueY3 = -100;
  double testValueX4 = 4;
  double testValueY4 = S21_NAN;
  ck_assert_double_nan(s21_fmod(testValueX1, testValueY1));
  ck_assert_double_nan(s21_fmod(testValueX2, testValueY2));
  ck_assert_ldouble_eq_tol(s21_fmod(testValueX3, testValueY3),
                           fmod(testValueX3, testValueY3), 1e-6);
  ck_assert_double_nan(s21_fmod(testValueX4, testValueY4));
}
END_TEST

Suite *s21_math_fmod_suite() {
  Suite *s = suite_create("s21_fmod");
  TCase *tc_fmod_usual = tcase_create("s21_fmod_usual");
  tcase_add_test(tc_fmod_usual, test_s21_math_fmod_usual);
  suite_add_tcase(s, tc_fmod_usual);
  TCase *tc_fmod_unusual = tcase_create("s21_fmod_unusual");
  tcase_add_test(tc_fmod_unusual, test_s21_math_fmod_unusual);
  suite_add_tcase(s, tc_fmod_unusual);
  return s;
}

int main() {
  int fail_number = 0;
  Suite *s = s21_math_fmod_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  fail_number = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (fail_number == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
