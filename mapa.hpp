#ifndef MAPA_HPP
#define MAPA_HPP

#include "matbin.hpp"
#include "patron.hpp"

namespace SHC
{
    class Mapa : public MatBin
    {
    public:
        Mapa();
        void setPatron (unsigned int x, unsigned int y, SHC::Patron& estructura);
    };
}
#endif // MAPA_HPP
