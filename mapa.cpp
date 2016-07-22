#include "mapa.hpp"

namespace SHC
{
    Mapa::Mapa()
    {
    }

    Mapa::Mapa(unsigned int numfil, unsigned int numcol):
        MatBin(numfil, numcol)
    {
    }

    void Mapa::setPatron (unsigned int x, unsigned int y, SHC::Patron& patron)
    {
        int col = patron.numcol();
        int fil = patron.numfil();

        for (int i=x; i < col; i++)
        {
            for (int j=y; j < fil; j++)
            {
                //(this->operator[](j)).operator [](i) = patron[j][i];
                //this[j][i] = patron[j][i];
            }
        }
    }
}
