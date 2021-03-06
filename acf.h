// класс автокорреляционной функции

#ifndef ACF_H
#define ACF_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "defines.h"

class Acf
{
public:
    // constructors
    Acf();
    Acf(const Acf &acf);

    // getters
    vec32_t value() const;
    double  peakSideLobe() const;
    double  meritFactor() const;

    // setters
    void setValue(const vec32_t &value);

    // operators overloading
    Acf &operator= (const Acf &acf);
    friend std::ostream &operator<< (std::ostream &out, const Acf &acf);

    // inside fucntions
private:
    void initialize(const Acf &acf);

    // inside members
private:
    vec32_t _value;                // значения АКФ
    double  _peak_side_lobe {0.0}; // уровень боковых лепестков
    double  _merit_factor {0.0};   // отношение энергии главного лепестка к суммарной энергии всех боковых лепестков

};


#endif // ACF_H
