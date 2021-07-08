// Класс расчета АКФ

#ifndef CORR_H
#define CORR_H

#include "defines.h"
#include <cmath>

vec32_t corr(vec32_t seq); // рассчет АКФ из модели в MatLab
vec32_t corr1(vec32_t seq); // рассчет АКФ из Cyberforum
// https://www.cyberforum.ru/cpp-beginners/thread1954497-page2.html
//vec32_t corr2(vec32_t seq); // рассчет АКФ из Cyberforum

void vec32_tMultiplication(vec32_t &vec, int multiplier); // поэлементное умножение вектора на целое число
void coutVec32_t(vec32_t vec); // вывод содержимого вектора в cout
void seq01ToSeqMinus11(vec32_t &seq); // преобразование последовательности 0 и 1 в последовантельность -1 и 1

#endif // CORR_H
