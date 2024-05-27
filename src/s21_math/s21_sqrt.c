#include "../s21_math.h"

long double s21_sqrt(double x) {
  if (x < 0) return -S21_NAN;
  if (x == 0) return 0;
  double res = x / 2;
  double p;
  do {
    p = res;
    res = (p + (x / p)) / 2;
  } while ((p - res) != 0);
  return res;
}
