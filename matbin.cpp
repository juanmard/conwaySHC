#include "matbin.hpp"

namespace SHC
{
    MatBin::MatBin ():
    vectores()
    {
    }

    MatBin::MatBin (unsigned int filas, unsigned int columnas)
    {
        vectores.resize(columnas, *new VecBin(filas));
    }

    SHC::VecBin& MatBin::operator[] (unsigned int i)
    {
        return vectores[i];
    }

    unsigned int MatBin::numcol () const
    {
        return vectores.size();
    }

    unsigned int MatBin::numfil () const
    {
        return vectores[0].size();
    }
}
