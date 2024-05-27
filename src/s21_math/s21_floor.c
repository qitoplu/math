#include "../s21_math.h"

long double s21_floor(double x) {
  long double floor_x = (long long int)x;
  if (S21_isNAN(x))
    return S21_NAN;
  else if (S21_isPOS_INF(x))
    floor_x = POS_INF;
  else if (S21_isNEG_INF(x))
    floor_x = NEG_INF;
  else if (x < 0 && x != floor_x)
    floor_x -= 1;
  return floor_x;
}