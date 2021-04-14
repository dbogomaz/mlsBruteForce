#include "mlsdatafile.h"

// constutions
MlsDataFile::MlsDataFile()
    : _fileName("")
    , _filePath("")
    , _sep(' ')
{

}

MlsDataFile::MlsDataFile(const MlsDataFile &mdf)
{
    _fileName = mdf.fileName();
    _filePath = mdf.filePath();
}

MlsDataFile::~MlsDataFile()
{
//    cout << "Деструктор " << this->fileName() << endl;
}

// getters
string MlsDataFile::fileName() const
{
    return _fileName;
}

string MlsDataFile::filePath() const
{
    return _filePath;
}

string MlsDataFile::fullName() const
{
    return _filePath + _fileName;
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
            fin >> _data.init_seq >>
                   _data.polynominal >>
                   _data.length >>
                   _data.sequence >>
                   _data.acf >>
                   _data.acf_peak_side_lobe;
            break;
        }
    }

    fin.close();

    return _data;
}


// setters
void MlsDataFile::setFileName(const string &fileName)
{
    _fileName = fileName;
}

void MlsDataFile::setFilePath(const string &filePath)
{
    _filePath = filePath;
}

void MlsDataFile::writeData(const MLSData &data)
{
    ofstream fout;
    fout.open(this->fullName(), ios::app);

    fout << data.init_seq           << _sep <<
            data.polynominal        << _sep <<
            data.length             << _sep <<
            data.sequence           << _sep <<
            data.acf                << _sep <<
            data.acf_peak_side_lobe << '\n';

    fout.close();
}


// overload operations
MlsDataFile &MlsDataFile::operator=(const MlsDataFile &mdf)
{
    if (this == &mdf) {
        return *this;
    }
    _fileName = mdf.fileName();
    _filePath = mdf.filePath();

    return *this;
}
