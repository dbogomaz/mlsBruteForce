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
    // получаем абсолютные значения
    for (auto d : value) {
        _value.push_back(abs(d));
    }

    int main_lobe_index = (_value.size() - 1) / 2; // индекс главного лепестка

    typedef vec32_t::const_iterator iterator;
    iterator it_0 = _value.begin(); // начало АКФ
    iterator it_1 = _value.begin() + (_value.size() - 1) / 2 - 1; // левый от максимума боковой лепесток

    _peak_side_lobe = 20 * log10(1.0 * *max_element(it_0, it_1) / *(it_1 + 1)); // уровень боковых лепестков в дБ

    _merit_factor = 0;
    for (int i = 0; i < main_lobe_index; ++i) {
        _merit_factor += _value[i] * _value[i];
    }
    _merit_factor = _value[main_lobe_index] * _value[main_lobe_index] / (2 * _merit_factor);
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

    for (auto d : acf.value()) {
        out << d << " ";
    }
    out << endl;
    out << "PSL = " << acf.peakSideLobe();
    out << endl;
    out << "MF = " << acf.meritFactor();
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
