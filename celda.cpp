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

    int Celda::valorada()
    {
        int valor;
        switch (actual)
        {
            case empty:
            case next_full:
                valor = 0;
                break;
            case full:
            case next_empty:
                valor = 1;
                break;
            default:
                valor = 0;
        }
        return valor;
    }

    void Celda::update()
    {
        switch (actual)
        {
            case next_empty:
                actual = empty;
                break;
            case next_full:
                actual = full;
                break;
            default:
                break;
        }
    }

    bool Celda::operator==(Estado comparar)
    {
        return (actual == comparar);
    }

}
