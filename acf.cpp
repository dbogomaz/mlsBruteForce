#include "acf.h"

// constructors
Acf::Acf()
    : m_peakSideLobe(0)
{

}

Acf::Acf(const Acf &acf)
{
    m_peakSideLobe = acf.peakSideLobe();
}

int Acf::peakSideLobe() const
{
    return m_peakSideLobe;
}


// operators overloading
Acf &Acf::operator= (const Acf &acf)
{
    if(this == &acf) {
        return *this;
    }
    m_peakSideLobe = acf.peakSideLobe();

    return *this;
}

std::ostream &operator<< (std::ostream &out, const Acf &acf)
{
    out << "acf(" << acf.m_peakSideLobe << ")";

    return out;
}


