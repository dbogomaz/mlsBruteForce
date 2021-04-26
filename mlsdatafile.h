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
    MlsDataFile(const MlsDataFile &mls_data_file); // constructor of copy
    ~MlsDataFile();

    // getters
    string  fileName() const;
    string  filePath() const;
    string  fullName() const;
    MLSData readLastData();

    // setters
    void setFileName(const string &file_name);
    void setFilePath(const string &file_path);
    void writeData(const MLSData &data);

    // overload operations
    MlsDataFile &operator= (const MlsDataFile &mdf);
    //std::ostream &operator<< (std::ostream &osr, MlsDataFile &mdf);

    // inside functions
private:
    void initialize(const MlsDataFile &mdf);

    // inside members
private:
    string     _file_name {""};
    string     _file_path {""};
    const char _sep {' '};     // separator разделитель данных в файле (например пробел)
    MLSData    _data;          // структура для хранения промежуточных данных (чтобы каждый раз при чтении память не выделять)

};

#endif // MLSDATAFILE_H
