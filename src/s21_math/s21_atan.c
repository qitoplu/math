#include "../s21_math.h"

long double s21_atan(double x) {
  long double res = 0.0;
  if (x == 0.0)
    res = 0.0;
  else if (S21_isNEG_INF(x))
    res = -S21_M_PI / 2;
  else if (S21_isPOS_INF(x))
    res = S21_M_PI / 2;
  else if (x == -1.0)
    res = -S21_M_PI / 4.0;
  else if (x == 1.0)
    res = S21_M_PI / 4.0;
  else if (S21_isNAN(x))
    res = S21_NAN;
  else {
    int in_range = (x > -1 && x < 1);
    res = in_range ? x : 1.0 / x;
    long double next_step;
    int precision = TAYLOR_MAX;

    if (x > 0.9 && x < 1.1) precision = 10000;

    if (x < -1.1 && x > -0.9) precision = 10000;

    for (int i = 1; i < precision; i++) {
      next_step = i & 1 ? -1 : 1;
      next_step *= s21_pow(x, (1 + 2 * i) * (in_range ? 1 : -1));
      next_step /= 1 + 2 * i;
      res += next_step;
    }

    if (!in_range) res = (S21_M_PI * s21_fabs(x) / (2.0 * x)) - res;
  }
  return res;
}
