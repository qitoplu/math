#include "../s21_math.h"

long int s21_fact(int x) {
  long int res = 1;
  for (int k = 2; k <= x; k++) res *= k;
  return res;
}