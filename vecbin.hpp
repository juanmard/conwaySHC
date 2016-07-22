#ifndef VECBIN_HPP
#define VECBIN_HPP

#include <vector>
#include "celda.hpp"

namespace SHC
{
    class VecBin
    {

    public:        
        VecBin();
        VecBin(unsigned int tam);
        unsigned int size () const;

        Celda& operator[](unsigned int i);
    private:
        // std::vector<bool> componentes;  // Clase especial a nivel de bits, cálculo intensivo, se descarta.
        std::vector<Celda> componentes;
    };
}

#endif // VECBIN_HPP
