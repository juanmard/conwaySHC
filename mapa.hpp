#ifndef MAPA_HPP
#define MAPA_HPP

#include "matbin.hpp"
#include "patron.hpp"

namespace SHC
{
    class Mapa : public MatBin
    {
    public:
        Mapa(unsigned int numfil=10, unsigned int numcol=10);

        void setPatron (unsigned int x, unsigned int y, SHC::Patron& patron);
    };
}
#endif // MAPA_HPP
