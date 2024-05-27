#include "../s21_math.h"

long double unusual_cases_pow(double base, double exp) {
  long double res = USUAL;

  if (base == 0.0) {
    if (S21_isNAN(exp))
      res = S21_NAN;
    else if (S21_isNEG_INF(exp))
      res = POS_INF;
    else if (exp == 0.0)
      res = 1.0;
    else if (exp < 0)
      res = POS_INF;
  } else if (base == 1.0) {
    res = 1.0;
  } else if (base == -1.0) {
    if (S21_isPOS_INF(exp) || S21_isNEG_INF(exp)) res = 1.0;
  } else if (!S21_isINT(base) && !S21_isPOS_INF(base) && !S21_isNEG_INF(base)) {
    if (S21_isNEG_INF(exp)) res = POS_INF;
  } else if (S21_isINT(base)) {
    if (S21_isPOS_INF(exp) || S21_isNEG_INF(exp)) res = POS_INF;
  } else if (S21_isPOS_INF(base)) {
    if (exp == 0.0)
      res = 1.0;
    else if (exp > 0 && S21_isINT(exp))
      res = POS_INF;
    else if (S21_isPOS_INF(exp) || S21_isNAN(exp))
      res = POS_INF;
  } else if (S21_isNEG_INF(base)) {
    if (exp == 0.0)
      res = 1.0;
    else if (S21_isPOS_INF(exp) || S21_isNAN(exp))
      res = POS_INF;
  }
  return res;
}

long double s21_pow_int(double base, int exp) {
  long double res = 1.0;
  if (exp < 0) {
    base = 1.0 / base;
    exp = -exp;
  }
  for (int i = 0; i < exp; ++i) {
    res *= base;
  }
  return res;
}

long double s21_pow(double base, double exp) {
  long double res = 1.0;
  long double isUnusual = unusual_cases_pow(base, exp);

  if (isUnusual == 21.0) {
    if (S21_isINT(exp)) {
      res = s21_pow_int(base, (int)exp);
    } else {
      if (base < 0) {
        res = S21_NAN;
      } else {
        res = s21_exp(exp * s21_log(base));
      }
    }
  } else {
    res = isUnusual;
  }
  return res;
}
