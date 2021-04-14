#include "acf.h"

// constructors
Acf::Acf()
    : _peakSideLobe(0)
{

}

Acf::Acf(const Acf &acf)
{
    _peakSideLobe = acf.peakSideLobe();
}

int32_t Acf::peakSideLobe() const
{
    return _peakSideLobe;
}


// operators overloading
Acf &Acf::operator= (const Acf &acf)
{
    if(this == &acf) {
        return *this;
    }
    _peakSideLobe = acf.peakSideLobe();

    return *this;
}

std::vector<int32_t> Acf::value() const
{
    return _value;
}

void Acf::setValue(const std::vector<int32_t> &value)
{
    _value = value;
}

std::ostream &operator<< (std::ostream &out, const Acf &acf)
{
    out << "acf(" << acf.peakSideLobe() << ")";

    return out;
}


