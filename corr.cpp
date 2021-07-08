#include "corr.h"

#include <iostream>


// рассчет АКФ из модели в MatLab
vec32_t corr(vec32_t seq)
{
    // преобразуем seq из полследовательности 0 и 1 в последовательность -1 и 1
    for (vec32_t::size_type i = 0; i < seq.size(); ++i) {
        seq[i] = seq[i] * 2 - 1;
    }

    // out - выходной вектор нужного размера, для АКФ
    vec32_t out(seq.size() * 2 - 1);

    // длина половинки АКФ
    int T = seq.size() - 1;

    // сдвиг
    int dt = 1;

    // собственно расчет АКФ
    for (int tau = -T; tau <= T; tau += dt) {
        for (int t = fmax(0, tau); t <= fmin(T, T + tau); t += dt) {
            out[tau + T] += (seq[t] * seq[t - tau]);
        }
    }

//    using namespace std;
//    coutVec32_t(out);
//    cout << endl;

    return out;
}


// рассчет АКФ из Cyberforum
// https://www.cyberforum.ru/cpp-beginners/thread1954497-page2.html
vec32_t corr1(vec32_t seq)
{
    // преобразуем seq из полследовательности 0 и 1 в последовательность -1 и 1
    for (vec32_t::size_type i = 0; i < seq.size(); ++i) {
        seq[i] = seq[i] * 2 - 1;
    }

    // out - выходной вектор нужного размера, для АКФ
    vec32_t out(seq.size() * 2 - 1);

    // подсчет половинки АКФ
    int seqSize = seq.size();
    for (int i = 0; i < seqSize; i++) {
        for (int j = 0; j < seqSize - i; j++) {
            out[seqSize - 1 + i] += seq[j] * seq[j + i];
            if (i > 0) { // зеркалим половинку
                out[seqSize - 1 - i] += seq[j] * seq[j + i];
            }
        }
    }

//    using namespace std;
//    coutVec32_t(out);
//    cout << endl;

    return out;
}


// поэлементное умножение вектора на целое число
void vec32_tMultiplication(vec32_t &vec, int multiplier)
{
    vec32_t::iterator it = vec.begin();

    while (it != vec.end()) {
//        std::cout << *it * 2 << " ";
        *it *= multiplier;
        it++;
    }
//    std::cout << std::endl;

}


// вывод содержимого вектора в cout
void coutVec32_t(vec32_t vec)
{
    using namespace std;
    char tabSymbol = ' '; // символ табуляции
    int tabNumber = 3; // количество символов табуляции (дб не меньше одного)

    for (auto d: vec) {
        int i = 0;
        if (d < 0) {
            i++;
        }
        for (; i < tabNumber; ++i) {
            cout << tabSymbol;
        }
        cout << d;
    }
}

// преобразование последовательности 0 и 1 в последовантельность -1 и 1
void seq01ToSeqMinus11(vec32_t &seq)
{
    for (vec32_t::size_type i = 0; i < seq.size(); ++i) {
        seq[i] = seq[i] * 2 - 1;
    }
}