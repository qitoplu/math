#include "../s21_math.h"

long double s21_ceil(double x) {
  long double ceil_x = (long long int)x;
  if (S21_isNAN(x))
    return S21_NAN;
  else if (S21_isPOS_INF(x))
    ceil_x = POS_INF;
  else if (S21_isNEG_INF(x))
    ceil_x = NEG_INF;
  else if (x > 0 && x != ceil_x)
    ceil_x += 1;
  return ceil_x;
}
