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
        prueba.add(' ',new SHC::Patron("------\n------\n------\n------\n------\n------\n"));
        prueba.add('S',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('C',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('I',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('E',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('N',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('H',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('A',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('K',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('U',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('L',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('B',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('s',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('c',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('i',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('e',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('n',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('h',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('a',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('k',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('u',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('l',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        prueba.add('b',new SHC::Patron("******\n******\n******\n******\n******\n******\n"));
        this->setPaleta(prueba);

        // 2 - Leer una línea de la imagen.
        imagen = new SHC::ImagenASCII("prueba.txt");
//        std::string linea = imagen->getCaracteres();
        //std::string linea = "aaabbbc";

        // 3 - Usar la paleta para convertir caracteres ASCII en patrones.
        std::string linea;
        int j=1;
        while (j<=mapa->numfil())
        {
            linea = imagen->readLine();
            int i=1;
            size_t tamlin = linea.size();
            while (i <= tamlin)
            {
                mapa->setPatron(j*6,i*6,*paleta->get(linea[i-1]));
                i++;
            }
            j++;
        }
    }

    void Conversor::setPaleta(SHC::Paleta& paletaEntrada)
    {
        paleta = &paletaEntrada;
    }

    void Conversor::setMapa(SHC::Mapa& mapaSalida)
    {
        mapa = &mapaSalida;
    }

    void Conversor::setImagenASCII(SHC::ImagenASCII& imagenASCII)
    {
        imagen = &imagenASCII;
    }
}
