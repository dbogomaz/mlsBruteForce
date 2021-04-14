// класс автокорреляционной функции

#ifndef ACF_H
#define ACF_H

#include <iostream>
#include <vector>

class Acf
{
public:
    // constructors
    Acf();
    Acf(const Acf &acf);

    // getters
    std::vector<int32_t> value() const;
    int32_t peakSideLobe() const;

    // setters
    void setValue(const std::vector<int32_t> &value);

    // operators overloading
    Acf &operator= (const Acf &acf);
    friend std::ostream &operator<< (std::ostream &out, const Acf &acf);


private:
    int32_t _peakSideLobe {0}; // пиковый боковой лепесток (уровень боковых лепестков)
    std::vector<int32_t> _value; // значения АКФ


};


#endif // ACF_H
