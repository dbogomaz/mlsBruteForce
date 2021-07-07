#include <iostream>

#include <fstream>
//#include <sstream>
#include <string>

#include "acf.h"
#include "mlsdatafile.h"
#include "mlsdata.h"
#include "corr.h"

using namespace std;

int main() {

    vec32_t v {1, 0, -3, 2, -1, -2, 7, -2, -1, 2, -3, 0, 1};

    vec32_t v1 {  9,  6, 15, 24, 21, 22, 19, -12,  1, 14,
                 11, -4, -3, 10, 11,  4,-11,  18,  3,  4,
                -15, 14, 11, 12,  9, 10,  7,   0,  9, 22,
                143, 22,  9,  0,  7, 10,  9,  12, 11, 14,
                -15,  4,  3, 18,-11,  4, 11,  10, -3, -4,
                 11, 14,  1,-12, 19, 22, 21,  24, 15,  6, 9};

    vec32_t v2 {0, 0, 0, 1, 0, 0, 1};

//    Acf a;
//    a.setValue(v1);
//    cout << a << endl;

//    cout << "main corr()" << endl;
//    for (auto e : corr(v2)) {
//        cout << e << ' ';
//    }
//    cout << endl;

//    cout << "main corr()" << endl;
//    corr(v2);
    cout << "main corr1()" << endl;
    corr1(v2);

    return 0;
}
