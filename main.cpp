#include <iostream>

#include <fstream>
//#include <sstream>
#include <string>

#include "acf.h"
#include "mlsdatafile.h"
#include "mlsdata.h"
#include "corr.h"

#include "/Users/bgm/QtProjects/!BClasses/Btimer/btimer.h"

using namespace std;

int main() {

    BTimer fullTime;

    vec32_t v {1, 0, -3, 2, -1, -2, 7, -2, -1, 2, -3, 0, 1};

    vec32_t v1 {  9,  6, 15, 24, 21, 22, 19, -12,  1, 14,
                 11, -4, -3, 10, 11,  4,-11,  18,  3,  4,
                -15, 14, 11, 12,  9, 10,  7,   0,  9, 22,
                143, 22,  9,  0,  7, 10,  9,  12, 11, 14,
                -15,  4,  3, 18,-11,  4, 11,  10, -3, -4,
                 11, 14,  1,-12, 19, 22, 21,  24, 15,  6, 9};

    vec32_t v2 {0, 0, 0, 1, 0, 0, 1};
    vec32_t v3 {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, };

    BTimer t;
    double tSumma = 0.0;
    double tSumma1 = 0.0;

    int  iterationsNumber = 10000000;

    for (int i = 0; i < iterationsNumber; ++i) {
        t.reset();
        corr(v3);
        tSumma += t.elapsed();

        t.reset();
        corr1(v3);
        tSumma1 += t.elapsed();
    }

    cout << "corr()   - " << tSumma << endl;
    cout << "corr1()  - " << tSumma1 << endl;
    cout << endl;
    cout << "fullTime - " << fullTime.elapsed() << endl;


    return 0;
}
