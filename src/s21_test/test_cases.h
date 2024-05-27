#include "../s21_math.h"

double cases_pow_zeros[][2] = {{0, 5},        {0, -5},      {0, S21_NAN},
                               {0, -S21_NAN},     {0, 0},       {0, NEG_INF},
                               {-1, POS_INF}, {-1, NEG_INF}};

double cases_pow_exp[][2] = {{1, S21_NAN}, {1, POS_INF}, {1, 0},  {1, -5},  {1, 5},
                             {1, 1.5}, {-1, 3},      {-1, 2}, {-1, 1.5}};

double cases_pow_base[][2] = {{S21_NAN, 0}, {POS_INF, 0}, {5, 0}};

double cases_pow_base_fractional[][2] = {
    {0.1, POS_INF}, {-0.1, POS_INF}, {0.1, NEG_INF}, {-0.1, NEG_INF},
    {5, POS_INF},   {-5, POS_INF},   {5, NEG_INF},   {-5, NEG_INF}};

double cases_pow_INF_exp[][2] = {
    {POS_INF, 0}, {POS_INF, 5}, {POS_INF, POS_INF}, {POS_INF, S21_NAN},
    {NEG_INF, 0}, {NEG_INF, 5}, {NEG_INF, POS_INF}, {NEG_INF, S21_NAN},
};

double cases_pow_nan[][2] = {{S21_NAN, S21_NAN}, {S21_NAN, -S21_NAN}, {-S21_NAN, -S21_NAN}};
double cases_pow_usual[][2] = {{5, S21_NAN}, {5, -S21_NAN}, {5, POS_INF}, {5, NEG_INF}};

double cases_pow_return_nan[][2] = {
    {0.00, S21_NAN},  {POS_INF, S21_NAN}, {NEG_INF, S21_NAN}, {S21_NAN, S21_NAN},    {S21_NAN, -S21_NAN},
    {-S21_NAN, -S21_NAN}, {0.00, -S21_NAN},   {0.00, -S21_NAN},   {-1.00, 1.50}, {-S21_NAN, -S21_NAN}};

double cases_pow_return_inf[][2] = {
    {0.00, -5.00},    {0.00, NEG_INF},    {0.10, NEG_INF},
    {-0.10, NEG_INF}, {5.00, POS_INF},    {-5.00, POS_INF},
    {POS_INF, 5.00},  {POS_INF, POS_INF}, {NEG_INF, POS_INF}};

double cases_pow_return_one[][2] = {
    {-1.00, POS_INF}, {-1.00, NEG_INF}, {1.00, S21_NAN},     {1.00, POS_INF},
    {1.00, 0.00},     {1.00, -5.00},    {1.00, 5.00},    {1.00, 1.50},
    {-1.00, 2.00},    {S21_NAN, 0.00},      {POS_INF, 0.00}, {5.00, 0.00},
    {NEG_INF, 0.00}};