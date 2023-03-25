// Функция расчета АКФ

#ifndef CORR_H
#define CORR_H

#include <iostream>

#include "defines.h"
//#include <cmath>

vec32_t corr(vec32_t seq); // рассчет АКФ из Cyberforum
// https://www.cyberforum.ru/cpp-beginners/thread1954497-page2.html

void coutVec32_t(vec32_t vec); // вывод содержимого вектора в cout

#endif // CORR_H
