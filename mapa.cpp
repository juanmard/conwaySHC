#include "mapa.hpp"
//#include <iostream>   //std::cerr

namespace SHC
{
    Mapa::Mapa(unsigned int numfil, unsigned int numcol):
        MatBin(numfil, numcol)
    {
    }

    void Mapa::setPatron (unsigned int x, unsigned int y, SHC::Patron& patron)
    {
        int col = patron.numcol();
        int fil = patron.numfil();

//        try
//        {
            for (int i=0; i < col; i++)
            {
                for (int j=0; j < fil; j++)
                {
                    (*this)[j+y][i+x] = patron[j][i];
                }
            }
//        }
//        catch (const std::out_of_range& oor)
//        {
//            std::cerr << "Has intentado dibujar un patrón fuera del mapa. Háztelo mirar." << std::endl << oor.what() << std::endl;
//        }
    }
}
