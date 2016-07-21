#include "vecbin.hpp"

namespace SHC
{
    VecBin::VecBin():
    componentes()
    {
    }

    VecBin::VecBin(unsigned int tam)
    {
        componentes.resize(tam, *new Celda());
    }

    Celda& VecBin::operator[] (unsigned int i)
    {
        return componentes[i];
    }
}
