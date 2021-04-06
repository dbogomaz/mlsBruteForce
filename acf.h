#ifndef ACF_H
#define ACF_H
// класс автокорреляционной функции

class Acf
{
public:
    // constructors
    Acf();
    Acf(const Acf &acf);

    // getters
    int peakSideLobe() const;

    // setters

    // operators overloading
    Acf &operator= (const Acf &acf);


private:
    int m_peakSideLobe {0}; // пиковый боковой лепесток

};

#endif // ACF_H
