#include "conversor.hpp"

namespace SHC
{
    Conversor::Conversor()
    {
    }

    void Conversor::convertir()
    {
        // 1 - Comprobar que tenemos todos los elementos necesarios.
        SHC::Paleta prueba;
        prueba.add('a',new SHC::Patron());
        prueba.add('b',new SHC::Patron());
        prueba.add('c',new SHC::Patron());
        this->setPaleta(prueba);

        // 2 - Leer una línea de la imagen.
        //std::string linea = imagen->readLine();
        std::string linea = "aaabbc";

        // 3 - Usar la paleta para convertir caracteres ASCII en patrones.
        char caracter = linea[0];

        while (true)//caracter != std::endl)
        {
            mapa->setPatron(0,0,*paleta->get(caracter));
        }
        // 4 - Repetir el paso dos hasta que se terminen las líneas.
    }

    void Conversor::setPaleta(SHC::Paleta& paletaEntrada)
    {
        this->paleta = &paletaEntrada;
    }

    void Conversor::setMapa(SHC::Mapa& mapaSalida)
    {

    }

    void Conversor::setImagenASCII(SHC::ImagenASCII& imagenASCII)
    {
    }
}
