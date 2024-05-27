#include "../s21_math.h"

long double s21_asin(double x) {
  long double res;

  if (x == 1.0)
    res = S21_M_PI / 2.0;
  else if (x == -1.0)
    res = -S21_M_PI / 2.0;
  else if (x > -1.0 && x < 1.0) {
    return 2.0 * s21_atan(x / (1.0 + s21_sqrt(1.0 - (x * x))));
  } else {
    res = S21_NAN;
  }
  return res;
}
