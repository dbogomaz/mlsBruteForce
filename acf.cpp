#include "acf.h"

// constructors
// ********************************************************************************
Acf::Acf()
    : _peak_side_lobe(0.0)
    , _merit_factor(0.0)
{
    _value.clear();
}

Acf::Acf(const Acf &acf)
{
    initialize(acf);
}



// getters
// ********************************************************************************
vec32_t Acf::value() const
{
    return _value;
}

double Acf::peakSideLobe() const
{
    return _peak_side_lobe;
}

double Acf::meritFactor() const
{
    return _merit_factor;
}



// setters
// ********************************************************************************
void Acf::setValue(const vec32_t &value)
{
    using namespace std;

    // получаем абсолютные значения
    for (auto d : value) {
        _value.push_back(abs(d));
    }

    // считаем _peak_side_lobe
    _peak_side_lobe = 20 * log10(static_cast<double>(*max_element(_value.begin() + 1, _value.end())) / _value[0]); // уровень боковых лепестков в дБ

    // считаем _merit_factor
    _merit_factor = 0;
    for (vec32_t::size_type i = 1; i < _value.size(); i++) {
        _merit_factor += _value[i] * _value[i];
    }
    _merit_factor *= 2;
    _merit_factor = _value[0] * _value[0] / _merit_factor;
}



// operators overloading
// ********************************************************************************
Acf &Acf::operator= (const Acf &acf)
{
    if(this == &acf) {
        return *this;
    }
    initialize(acf);

    return *this;
}

std::ostream &operator<< (std::ostream &out, const Acf &acf)
{
    using namespace std;

    out << "AKF = ";
    for (auto d : acf.value()) {
        out << d << " ";
    }
    out << endl;
    out << "PSL = " << acf.peakSideLobe();
    out << endl;
    out << " MF = " << acf.meritFactor();
    out << endl;

    return out;
}


// inside fucntion
// ********************************************************************************
void Acf::initialize(const Acf &acf)
{
    _value = acf.value();
    _peak_side_lobe = acf.peakSideLobe();
    _merit_factor = acf.meritFactor();
}
