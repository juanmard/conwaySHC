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

        for (int i=0; i < col; i++)
        {
            for (int j=0; j < fil; j++)
            {
                // Comprobar que el patrón se dibuja en el mapa y no sale de él.
                (*this)[j+y][i+x] = patron[j][i];
            }
        }
    }
}
