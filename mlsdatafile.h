/* Класс для работы с файлом, где будут храниться данные М-последовательностей
 *
 */
#ifndef MLSDATAFILE_H
#define MLSDATAFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "mlsdata.h"

using namespace std;

class MlsDataFile
{
public:
    // construtors (destructors)
    MlsDataFile();
    MlsDataFile(const MlsDataFile &mdf); // constructor of copy
    ~MlsDataFile();

    // getters
    string fileName() const;
    string filePath() const;
    string fullName() const;
    MLSData readLastData();

    // setters
    void setFileName(const string &fileName);
    void setFilePath(const string &filePath);
    void writeData(const MLSData &data);

    // overload operations
    MlsDataFile &operator= (const MlsDataFile &mdf);
    //std::ostream &operator<< (std::ostream &osr, MlsDataFile &mdf);

private:
    string _fileName {""};
    string _filePath {""};
    const char _sep {' '}; // separator разделитель данных в файле (например пробел)
    MLSData _data; // структура для хранения промежуточных данных (чтобы каждый раз при чтении память не выделять)

};

#endif // MLSDATAFILE_H
