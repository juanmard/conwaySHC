#ifndef PALETA_HPP
#define PALETA_HPP

#include <map>
#include "patron.hpp"

namespace SHC
{
    class Paleta
    {
    public:
        Paleta();

        void add (char caracter, SHC::Patron *patron);
        SHC::Patron* get (char caracter);

    private:
        std::map<char, SHC::Patron*> equivalencias;
    };
}

#endif // PALETA_HPP
