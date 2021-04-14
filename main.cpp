#include <iostream>

#include <fstream>
#include <sstream>
#include <string>

#include "acf.h"
#include "mlsdatafile.h"
#include "mlsdata.h"

using namespace std;

int main() {

    MlsDataFile *file = new MlsDataFile();

    file->setFileName("name.txt");
    file->setFilePath("../");

    cout << endl;
    cout << "************" << endl;
    cout << file->fullName() << endl;
    cout << endl;

    MLSData data;
    data.init_seq = 1;
    data.polynominal = 1;
    data.length = 2;
    data.sequence = 3;
    data.acf = 4;
    data.acf_peak_side_lobe = 5;

    file->writeData(data);

    cout << endl;
    data = file->readLastData();

    const char Separator {' '};


    cout << data.init_seq << Separator <<
            data.polynominal << Separator <<
            data.length << Separator <<
            data.sequence << Separator <<
            data.acf << Separator <<
            data.acf_peak_side_lobe << '\n';

    cout << endl;

    delete file;

    return 0;
}
