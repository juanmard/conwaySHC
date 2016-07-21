#ifndef CONVERSOR_HPP
#define CONVERSOR_HPP

#include "paleta.hpp"
#include "mapa.hpp"
#include "imagenascii.hpp"

namespace SHC
{
    class Conversor
    {
    public:
        Conversor();

        void convertir ();
        void setPaleta (SHC::Paleta& paletaEntrada);
        void setMapa (SHC::Mapa& mapaSalida);
        void setImagenASCII (SHC::ImagenASCII& imagenASCII);

    private:
        SHC::Paleta* paleta;
        SHC::Mapa* mapa;
        SHC::ImagenASCII* imagen;
    };
}

#endif // CONVERSOR_HPP
