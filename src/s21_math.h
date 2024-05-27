#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdio.h>
#include <stdlib.h>

#define S21_EPS 1e-7
#define S21_MAX 1e100
#define S21_M_E 2.718281828459045235360287471352662498L  /* e */
#define S21_M_PI 3.141592653589793238462643383279502884L /* pi */
#define POS_INF (1.0/0.0L)                       /* infinity */
#define NEG_INF (-1.0/0.0L)                       /* negative infinity */
#define S21_NAN (0.0/0.0)                     /* nan */
#define S21_isNAN(x) (x != x)                            /* nan check */
#define S21_isNEG_INF(x) (x == NEG_INF) /* negative infinity check */
#define S21_isPOS_INF(x) (x == POS_INF) /* positive infinity */
#define S21_isINT(x) (x == (int)x)      /* integer check */
#define TAYLOR_MAX 150
#define USUAL 21

int s21_abs(int x);
long double s21_acos(double x);               
long double s21_asin(double x);              
long double s21_atan(double x);              
long double s21_ceil(double x);             
long double s21_cos(double x);                
long double s21_exp(double x);                
long double s21_fabs(double x);             
long double s21_floor(double x);            
long double s21_fmod(double x, double y);  
long double s21_log(double x);              
long double s21_pow(double base, double exp); 
long double s21_sin(double x);          
long double s21_sqrt(double x);      
long double s21_tan(double x);               

long int s21_fact(int x);

#endif