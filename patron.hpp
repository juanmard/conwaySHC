#ifndef PATRON_HPP
#define PATRON_HPP

#include "matbin.hpp"

namespace SHC
{
    class Patron : public MatBin
    {
    public:
        Patron();
        Patron(const std::string& cadena, unsigned int numfil=6, unsigned int numcol=6);
    };
}

#endif // PATRON_HPP
