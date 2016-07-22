#include "patron.hpp"

namespace SHC
{
    Patron::Patron():
        MatBin(6,6)
    {
        (*this)[0][0]=(*this)[0][1]=SHC::Celda::full;
        (*this)[1][0]=(*this)[1][1]=SHC::Celda::full;
    }
}
