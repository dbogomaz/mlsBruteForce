#include "corr.h"

#include <iostream>


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

    //
    int dt = 1;

    for (int tau = -T; tau <= T; tau += dt) {
        for (int t = fmax(0, tau); t <= fmin(T, T + tau); t += dt) {
            out[tau + T] += (seq[t] * seq[t - tau]);
        }
    }

    using namespace std;
    coutVec32_t(out);
    cout << endl;

    return out;
}


// рассчет АКФ из Cyberforum
// https://www.cyberforum.ru/cpp-beginners/thread1954497-page2.html
vec32_t corr1(vec32_t seq)
{
    using namespace std;

    cout << "seq" << endl;
    coutVec32_t(seq);

    // преобразуем seq из полследовательности 0 и 1 в последовательность -1 и 1
    for (vec32_t::size_type i = 0; i < seq.size(); ++i) {
        seq[i] = seq[i] * 2 - 1;
    }

    // out - выходной вектор нужного размера, для АКФ
    vec32_t out(seq.size() * 2 - 1);

    vec32_t::iterator it = seq.end() - 1;

    vec32_t s_x = seq;
    vec32_t s_y;

//   for (auto d: s) {
//       s1.push_back(d);
//   }

//   it -= 2;

    while (it >= seq.begin()) {
        s_y.push_back(*it);
//       cout << *it << " ";
        --it;
   }
//   cout << endl;

    cout << endl;
    cout << "s_x" << endl;
    coutVec32_t(s_x);

    cout << endl;
    cout << "s_y" << endl;
    coutVec32_t(s_y);

    cout << endl;

    std::vector<vec32_t> m;

    for (vec32_t::size_type y = 0; y < s_y.size(); ++y) {
        vec32_t v_temp = seq;
        vec32_tMultiplication(v_temp, s_y[y]);
        cout << endl;
        coutVec32_t(v_temp);
//        cout << endl;
   }

    cout << endl;
    cout << "out" << endl;
    coutVec32_t(out);
    cout << endl;

    return out;
}
