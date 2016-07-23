#include "patron.hpp"
//#include <iostream>
#include <sstream>

namespace SHC
{
    Patron::Patron():
        MatBin(6,6)
    {
        (*this)[0][0]=(*this)[0][1]=SHC::Celda::full;
        (*this)[1][0]=(*this)[1][1]=SHC::Celda::full;
    }

    Patron::Patron(const std::string& cadena, unsigned int numfil, unsigned int numcol):
        MatBin(numfil,numcol)
    {
        std::istringstream ss(cadena);
        std::string fila;

        int i=0;
        while(std::getline(ss, fila, '\n'))
        {
            size_t longfila = fila.size();

            for (int j=0; j<longfila; j++)
            {
                if (fila[j]=='*')
                {
                    (*this)[j][i]=SHC::Celda::full;
                }
                else
                {
                    (*this)[j][i]=SHC::Celda::empty;
                }
            }
            i++;
        }
    }

}
