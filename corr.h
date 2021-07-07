// Класс расчета АКФ

#ifndef CORR_H
#define CORR_H

#include "defines.h"
#include <cmath>

vec32_t corr(vec32_t seq); // рассчет АКФ из модели в MatLab
vec32_t corr1(vec32_t seq); // рассчет АКФ из Cyberforum
// https://www.cyberforum.ru/cpp-beginners/thread1954497-page2.html

#endif // CORR_H
