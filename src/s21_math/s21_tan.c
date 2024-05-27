#include "../s21_math.h"

long double s21_tan(double x) {
  int s = 1;
  if (S21_isNAN(x) || S21_isPOS_INF(x) || S21_isNEG_INF(x)) s = 0;
  x = s21_fmod(x, S21_M_PI);
  return !s ? S21_NAN : s21_sin(x) / s21_cos(x);
}