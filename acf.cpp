#include "acf.h"

// constructors
Acf::Acf()
    : _acf_peak_side_lobe(0)
{
    _value.clear();
}

Acf::Acf(const Acf &acf)
{
    _acf_peak_side_lobe = acf.acf_peak_side_lobe();
}

int32_t Acf::acf_peak_side_lobe() const
{
    return _acf_peak_side_lobe;
}


// operators overloading
Acf &Acf::operator= (const Acf &acf)
{
    if(this == &acf) {
        return *this;
    }
    _acf_peak_side_lobe = acf.acf_peak_side_lobe();

    return *this;
}

vec32_t Acf::value() const
{
    return _value;
}

void Acf::setValue(const vec32_t &value)
{
    // получаем абсолютные значения
    for (auto d : value) {
        _value.push_back(abs(d));
    }

    typedef vec32_t::const_iterator iterator;
    iterator it_0 = _value.begin(); // начало АКФ
    iterator it_middle = _value.begin() + (_value.size() - 1) / 2 - 1; // левые боковые лепестки без максимума

    _acf_peak_side_lobe = 20 * log10(1.0 * *max_element(it_0, it_middle) / *(it_middle + 1));
}

std::ostream &operator<< (std::ostream &out, const Acf &acf)
{
    using namespace std;

    for (auto d : acf.value()) {
        out << d << " ";
    }
    out << endl;
    out << "PSL = " << acf.acf_peak_side_lobe();
    out << endl;

    return out;
}


