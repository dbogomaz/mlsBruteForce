#include "mlsdatafile.h"

// constutions
// ********************************************************************************
MlsDataFile::MlsDataFile()
    : _file_name("")
    , _file_path("")
    , _sep(' ')
{

}

MlsDataFile::MlsDataFile(const MlsDataFile &mls_data_file)
{
    initialize(mls_data_file);
}

MlsDataFile::~MlsDataFile()
{
//    cout << "Деструктор " << this->fileName() << endl;
}


// getters
// ********************************************************************************
string MlsDataFile::fileName() const
{
    return _file_name;
}

string MlsDataFile::filePath() const
{
    return _file_path;
}

string MlsDataFile::fullName() const
{
    return _file_path + _file_name;
}

MLSData MlsDataFile::readLastData()
{
    ifstream fin;

    fin.open(this->fullName());

    if(!fin.is_open()) {
        cout << "*****  ERROR !!! *****" << endl;
        cout << "Не могу открыть файл " << this->fileName() << endl;
        return _data;
    }

    fin.seekg(-2, ios::end);
    while (true) {
        char sym = fin.get(); // тоже сдвигает указатель на +1
        fin.seekg(-2, ios::cur);
        if (sym == '\n' || fin.tellg() == 0) {
            if (sym == '\n') {
                fin.seekg(1, ios::cur);
            }
            fin >> _data.initSeq >>
                   _data.polynominal >>
                   _data.length >>
                   _data.sequence >>
                   _data.peakSideLobe >>
                   _data.meritFactor;
            break;
        }
    }

    fin.close();

    return _data;
}


// setters
// ********************************************************************************
void MlsDataFile::setFileName(const string &file_name)
{
    _file_name = file_name;
}

void MlsDataFile::setFilePath(const string &file_path)
{
    _file_path = file_path;
}

void MlsDataFile::writeData(const MLSData &data)
{
    ofstream fout;
    fout.open(this->fullName(), ios::app); // запись в конец файла

    fout << data.initSeq      << _sep <<
            data.polynominal  << _sep <<
            data.length       << _sep <<
            data.sequence     << _sep <<
            data.peakSideLobe << _sep <<
            data.meritFactor  << '\n';

    fout.close();
}


// overload operations
// ********************************************************************************
MlsDataFile &MlsDataFile::operator=(const MlsDataFile &mls_data_file)
{
    if (this == &mls_data_file) {
        return *this;
    }
    initialize(mls_data_file);

    return *this;
}


// inside functions
// ********************************************************************************
void MlsDataFile::initialize(const MlsDataFile &mls_data_file)
{
    _file_name = mls_data_file.fileName();
    _file_path = mls_data_file.filePath();
}
