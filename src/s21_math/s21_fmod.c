#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  int sign = 0;

  if (x <= 0) {
    sign = 1;
  }
  if (y == 0) {
    x = S21_NAN;
  } else if ((S21_isPOS_INF(x) && !S21_isNAN(y)) ||
             (S21_isNEG_INF(x) && !S21_isNAN(y)) ||
             (S21_isNAN(x) || S21_isNAN(y))) {
    x = S21_NAN;
  } else {
    x = s21_fabs(x);
    y = s21_fabs(y);
    while (x >= y) {
      x -= y;
    }
  }
  x = sign ? -x : x;

  return x;
}