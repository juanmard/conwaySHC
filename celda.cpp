#include "celda.hpp"

namespace SHC
{
    Celda::Celda(Estado inicial):
        actual(inicial)
    {
    }

    Celda& Celda::operator=(Estado nuevo)
    {
        actual = nuevo;
        return *this;
    }

    bool Celda::operator==(Estado comparar)
    {
        return (actual == comparar);
    }

}
