#include "../s21_math.h"

long double s21_acos(double x) {
  long double res;

  if (x == 1)
    res = 0.0;
  else if (x == -1)
    res = S21_M_PI;
  else if (x > -1 && x < 1) {
    res = 2 * s21_atan(s21_sqrt(1.0 - (x * x)) / (1.0 + x));
  } else {
    res = S21_NAN;
  }
  return res;
}
