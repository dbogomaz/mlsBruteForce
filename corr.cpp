#include "corr.h"

// рассчет АКФ из Cyberforum
// https://www.cyberforum.ru/cpp-beginners/thread1954497-page2.html
vec32_t corr(vec32_t seq)
{
    // преобразуем seq из полследовательности 0 и 1 в последовательность -1 и 1
    for (vec32_t::size_type i = 0; i < seq.size(); ++i) {
        seq[i] = seq[i] * 2 - 1;
    }

    int seqSize = seq.size();

    // out - выходной вектор нужного размера, для АКФ
    vec32_t out(seqSize);

    // подсчет половинки АКФ
    for (int i = 0; i < seqSize; i++) {
        for (int j = 0; j < seqSize - i; j++) {
            out[i] += seq[j] * seq[j + i];
        }
    }

//    using namespace std;
//    coutVec32_t(out);
//    cout << endl;

    return out;
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

