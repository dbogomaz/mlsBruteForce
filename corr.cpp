#include "corr.h"

#include <iostream>


// вывод содержимого вектора в cout
void coutVec32_t(vec32_t vec)
{
    for (auto d: vec) {
        std::cout << d << "\t";
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
   for (int i = 0; i < seq.size(); ++i) {
        seq[i] = seq[i] * 2 - 1;
    }

    vec32_t out(seq.size() * 2 - 1);

    int T = seq.size() - 1;

    int dt = 1;

    for (int tau = -T; tau <= T; tau += dt) {
        for (int t = fmax(0, tau); t <= fmin(T, T + tau); t += dt) {
            out[tau + T] += (seq[t] * seq[t - tau]);
        }
    }

    return out;
}


// рассчет АКФ из Cyberforum
vec32_t corr1(vec32_t s)
{
    using namespace std;

   for (int i = 0; i < s.size(); ++i) {
        s[i] = s[i] * 2 - 1;
    }

   vec32_t out(s.size() * 2 - 1);

   vec32_t::iterator it = s.end() - 1;

   vec32_t s_x = s;
   vec32_t s_y;

//   for (auto d: s) {
//       s1.push_back(d);
//   }

//   it -= 2;

   while (it >= s.begin()) {
       s_y.push_back(*it);
//       cout << *it << " ";
       --it;
   }
   cout << endl;

   coutVec32_t(s_x);
   cout << endl;
   coutVec32_t(s_y);
   cout << endl;

   std::vector<vec32_t> m;

   for (int y = 0; y < s_y.size(); ++y) {
       vec32_t v_temp = s;
       vec32_tMultiplication(v_temp, s_y[y]);
       cout << endl;
       coutVec32_t(v_temp);
       cout << endl;

   }



    return out;
}
