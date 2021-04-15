#include "acf.h"

// ********** constructors **********
Acf::Acf()
    : _acf_side_lobes_ratio(0.0)
    , _merit_factor(0.0)
{
    _value.clear();
}

Acf::Acf(const Acf &acf)
{
    init(acf);
}



// ********** getters **********
vec32_t Acf::value() const
{
    return _value;
}

double Acf::acfSideLobesRatio() const
{
    return _acf_side_lobes_ratio;
}

double Acf::meritFactor() const
{
    return _merit_factor;
}


// ********** setters **********
void Acf::setValue(const vec32_t &value)
{
    // получаем абсолютные значения
    for (auto d : value) {
        _value.push_back(abs(d));
    }

    typedef vec32_t::const_iterator iterator;
    iterator it_0 = _value.begin(); // начало АКФ
    iterator it_1 = _value.begin() + (_value.size() - 1) / 2 - 1; // левые боковой лепесток от максимума
    iterator it_main = it_1 + 1; // главный лепесток

    _acf_side_lobes_ratio = 20 * log10(1.0 * *max_element(it_0, it_1) / *(it_1 + 1)); // уровень боковых лепестков в дБ
}



// ********** operators overloading **********
Acf &Acf::operator= (const Acf &acf)
{
    if(this == &acf) {
        return *this;
    }
    init(acf);

    return *this;
}

std::ostream &operator<< (std::ostream &out, const Acf &acf)
{
    using namespace std;

    for (auto d : acf.value()) {
        out << d << " ";
    }
    out << endl;
    out << "SLR = " << acf.acfSideLobesRatio();
    out << endl;
    out << "MF = " << acf.meritFactor();
    out << endl;

    return out;
}

void Acf::init(const Acf &acf)
{
    _value = acf.value();
    _acf_side_lobes_ratio = acf.acfSideLobesRatio();
    _merit_factor = acf.meritFactor();
}

