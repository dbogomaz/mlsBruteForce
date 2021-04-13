/* Класс для работы с файлом, где будут храниться данные М-последовательностей
 *
 */
#ifndef MLSDATAFILE_H
#define MLSDATAFILE_H

#include<iostream>
#include <fstream>
#include <string>
#include<vector>
//#include<ostream>

using namespace std;

struct s
{
    s() {}
    int val1;
    double val2;
    string val3;
};


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
    s readLastData() const;

    // setters
    void setFileName(const string &fileName);
    void setFilePath(const string &filePath);
    void writeData(const s &data);

    // overload operations
    MlsDataFile &operator= (const MlsDataFile &mdf);
    //std::ostream &operator<< (std::ostream &osr, MlsDataFile &mdf);

private:
    string m_fileName {""};
    string m_filePath {""};

};

#endif // MLSDATAFILE_H
