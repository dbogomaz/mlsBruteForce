#include "mlsdatafile.h"

// constutions
MlsDataFile::MlsDataFile()
    : m_fileName("")
    , m_filePath("")
{

}

MlsDataFile::MlsDataFile(const MlsDataFile &mdf)
{
    m_fileName = mdf.fileName();
    m_filePath = mdf.filePath();
}

MlsDataFile::~MlsDataFile()
{
    cout << "Деструктор " << this->fileName() << endl;
}

// getters
string MlsDataFile::fileName() const
{
    return m_fileName;
}

string MlsDataFile::filePath() const
{
    return m_filePath;
}

string MlsDataFile::fullName() const
{
    return m_filePath + m_fileName;
}

s MlsDataFile::readLastData() const
{
    const char separator = ' ';
    ifstream fin;

    s r;

    fin.open(this->fullName());

    if(!fin.is_open()) {
        cout << "*****  ERROR !!! *****" << endl;
        cout << "Не могу открыть файл " << this->fileName() << endl;
        return r;
    }


//    string str = "";

    fin.seekg(-2, ios::end);

    while (true) {
        fin.seekg(-2, ios::cur);
        char sym = fin.get();
        if (sym == '\n') {
//            getline(fin, str);
            fin >> r.val1 >> r.val2 >> r.val3;
            break;
        }
    }

//    cout << r.val1 << separator <<
//            r.val2 << separator <<
//            r.val3 << endl;

    fin.close();

    return r;
}


// setters
void MlsDataFile::setFileName(const string &fileName)
{
    m_fileName = fileName;
}

void MlsDataFile::setFilePath(const string &filePath)
{
    m_filePath = filePath;
}

void MlsDataFile::writeData(const s &data)
{
    const char separator = ' ';
    ofstream fout;
    fout.open(this->fullName(), ios::app);

//    for (auto val : data) {
//        fout << val << " ";
//    }
    fout << data.val1 << separator <<
            data.val2 << separator <<
            data.val3 << '\n';

    fout.close();
}


// overload operations
MlsDataFile &MlsDataFile::operator=(const MlsDataFile &mdf)
{
    if (this == &mdf) {
        return *this;
    }
    m_fileName = mdf.fileName();
    m_filePath = mdf.filePath();

    return *this;
}
