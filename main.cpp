#include <iostream>

#include <fstream>
#include <sstream>
#include <string>

#include "acf.h"
#include "mlsdatafile.h"

using namespace std;

int main() {

    MlsDataFile *file = new MlsDataFile();

    file->setFileName("name.txt");
    file->setFilePath("../");

    cout << endl;
    cout << "************" << endl;
    cout << file->fullName() << endl;
    cout << endl;

    s dd;
//    dd.val1 = 5;
//    dd.val2 = 0.5;
//    dd.val3 = "ee5";

//    file->writeData(dd);

    cout << endl;
    dd = file->readLastData();


    cout << dd.val1 << " " <<
            dd.val2 << " " <<
            dd.val3;

    cout << endl;

    delete file;

    return 0;
}
