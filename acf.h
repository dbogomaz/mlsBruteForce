// класс автокорреляционной функции

#ifndef ACF_H
#define ACF_H

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int32_t> vec32_t;

class Acf
{
public:
    // constructors
    Acf();
    Acf(const Acf &acf);

    // getters
    vec32_t value() const;
    int32_t acf_peak_side_lobe() const;

    // setters
    void setValue(const vec32_t &value);

    // operators overloading
    Acf &operator= (const Acf &acf);
    friend std::ostream &operator<< (std::ostream &out, const Acf &acf);


private:
    int32_t _acf_peak_side_lobe {0}; // пиковый боковой лепесток (уровень боковых лепестков)
    vec32_t _value; // значения АКФ


};


#endif // ACF_H
