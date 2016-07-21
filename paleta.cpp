#include "paleta.hpp"

namespace SHC
{
    Paleta::Paleta()
    {
        // Prueba de Paleta.
        equivalencias['a'] = new SHC::Patron();
        equivalencias['b'] = new SHC::Patron();
    }

    SHC::Patron* Paleta::get(char caracter)
    {
        return equivalencias[caracter];
    }

    void Paleta::add (char caracter, SHC::Patron* patron)
    {
        equivalencias[caracter] = patron;
    }
}
