#include <iostream>

#include <fstream>
//#include <sstream>
#include <string>

#include "acf.h"
#include "mlsdatafile.h"
#include "mlsdata.h"

using namespace std;

int main() {

    vec32_t v {1, -2, -1, 3, 0, 7, 0, 3, -1, -2, 1};

    vec32_t v1 {  9,  6, 15, 24, 21, 22, 19, -12,  1, 14,
                 11, -4, -3, 10, 11,  4,-11,  18,  3,  4,
                -15, 14, 11, 12,  9, 10,  7,   0,  9, 22,
                143, 22,  9,  0,  7, 10,  9,  12, 11, 14,
                -15,  4,  3, 18,-11,  4, 11,  10, -3, -4,
                 11, 14,  1,-12, 19, 22, 21,  24, 15,  6, 9};

    cout << v1.size() << endl;

    Acf a;
    a.setValue(v1);

    cout << a;



    return 0;
}
