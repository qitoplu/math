#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

// ABS

START_TEST(test_s21_math_abs_usual) {
  ck_assert_int_eq(s21_abs(-1), abs(-1));
  ck_assert_int_eq(s21_abs(10), abs(10));
  ck_assert_int_eq(s21_abs(0), abs(0));
}
END_TEST

START_TEST(test_s21_math_abs_unusual) {
  ck_assert_int_eq(s21_abs(POS_INF), abs((int)POS_INF));
  ck_assert_int_eq(s21_abs(S21_NAN), abs((int)S21_NAN));
  ck_assert_int_eq(s21_abs(NEG_INF), abs((int)NEG_INF));
}
END_TEST

Suite *s21_math_abs_suite() {
  Suite *s;
  TCase *tc_tan_usual, *tc_tan_unusual;
  s = suite_create("s21_abs");
  tc_tan_usual = tcase_create("s21_abs_usual");
  tcase_add_test(tc_tan_usual, test_s21_math_abs_usual);
  suite_add_tcase(s, tc_tan_usual);
  tc_tan_unusual = tcase_create("s21_abs_unusual");
  tcase_add_test(tc_tan_unusual, test_s21_math_abs_unusual);
  suite_add_tcase(s, tc_tan_unusual);
  return s;
}

int main(void) {
  Suite *s;
  int failed = 0;
  SRunner *runner;
  s = s21_math_abs_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}