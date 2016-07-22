#ifndef MATBIN_HPP
#define MATBIN_HPP

#include <vector>
#include "vecbin.hpp"

namespace SHC
{
    class MatBin
    {
    public:
        MatBin();
        MatBin(unsigned int filas, unsigned int columnas);

        unsigned int numcol () const;
        unsigned int numfil () const;
        SHC::VecBin& operator[](unsigned int i);


    private:
        std::vector<SHC::VecBin> vectores;
    };
}

#endif // MATBIN_HPP
