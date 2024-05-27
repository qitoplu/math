#include "../s21_math.h"

long double s21_exp(double x) {
  double res;
  if (x == 0.0)
    res = 1.0;
  else if (S21_isNEG_INF(x))
    res = +0.0;
  else if (S21_isPOS_INF(x))
    res = POS_INF;
  else if (S21_isNAN(x))
    res = S21_NAN;
  else {
    double next_step = 1.0;
    res = next_step;

    for (int i = 1; i <= 100; i++) {
      next_step *= x / i;
      res += next_step;
    }
  }
  return res;
}
