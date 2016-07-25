#include "conversor.hpp"

namespace SHC
{
    Conversor::Conversor()
    {
        // Se incia la paleta con patrones asociados a las letras del club.
        SHC::Paleta &prueba = *new SHC::Paleta();
        prueba.add(' ',new SHC::Patron("------\n------\n------\n------\n------\n------\n"));
        prueba.add('S',new SHC::Patron("------\n--**--\n-*--*-\n--**--\n------\n------\n"));
        prueba.add('C',new SHC::Patron("------\n------\n--**--\n-*--*-\n--**--\n------\n"));
        prueba.add('I',new SHC::Patron("------\n--*---\n-*-*--\n-*-*--\n--*---\n------\n"));
        prueba.add('E',new SHC::Patron("------\n---*--\n--*-*-\n--*-*-\n---*--\n------\n"));
        prueba.add('N',new SHC::Patron("------\n--**--\n-*--*-\n--*-*-\n---*--\n------\n"));
        prueba.add('H',new SHC::Patron("------\n--*---\n-*-*--\n--**--\n------\n------\n"));
        prueba.add('A',new SHC::Patron("------\n-**---\n-**---\n------\n------\n------\n"));
        prueba.add('K',new SHC::Patron("------\n--**--\n--**--\n------\n------\n------\n"));
        prueba.add('U',new SHC::Patron("------\n---**-\n---**-\n------\n------\n------\n"));
        prueba.add('L',new SHC::Patron("------\n------\n---**-\n---**-\n------\n------\n"));
        prueba.add('B',new SHC::Patron("------\n------\n--**--\n--**--\n------\n------\n"));
        prueba.add('s',new SHC::Patron("------\n------\n-**---\n-**---\n------\n------\n"));
        prueba.add('c',new SHC::Patron("------\n------\n------\n-**---\n-**---\n------\n"));
        prueba.add('i',new SHC::Patron("------\n------\n------\n--**--\n--**--\n------\n"));
        prueba.add('e',new SHC::Patron("------\n------\n------\n---**-\n---**-\n------\n"));
        prueba.add('n',new SHC::Patron("------\n--**--\n--*-*-\n---**-\n------\n------\n"));
        prueba.add('h',new SHC::Patron("------\n------\n-**---\n-*-*--\n--**--\n------\n"));
        prueba.add('a',new SHC::Patron("------\n------\n--**--\n--*-*-\n---*--\n------\n"));
        prueba.add('k',new SHC::Patron("------\n-**---\n-*-*--\n-*--*-\n--**--\n------\n"));
        prueba.add('u',new SHC::Patron("------\n---*--\n--*-*-\n-*--*-\n--**--\n------\n"));
        prueba.add('l',new SHC::Patron("------\n---*--\n--*-*-\n---**-\n------\n------\n"));
        prueba.add('b',new SHC::Patron("------\n------\n---*--\n--*-*-\n---**-\n------\n"));
        setPaleta(prueba);

        // Se lee una imagen de prueba del disco.
        setImagenASCII(*new SHC::ImagenASCII("prueba.txt"));
    }

    void Conversor::convertir()
    {
        // 1 - Comprobar que tenemos todos los elementos necesarios.
        // if (conversor.OK())
        // {
        // 2 - Usar la paleta para convertir caracteres ASCII en patrones.
        SHC::Patron patronActual;
        unsigned int anchoPatron = 6;
        unsigned int altoPatron = 6;
        unsigned int altoMapa = mapa->numfil();
        std::string linea;
        unsigned int i = 1;
        while (i <= altoMapa)
        {
            linea = imagen->readLine();
            int j = 1;
            size_t tamlin = linea.size();
            while (j <= tamlin)
            {
                patronActual = *paleta->get(linea[j-1]);
                // anchoPatron = patronActual.getAncho();
                // altoPatron = patronActual.getAlto();
                mapa->setPatron(i*anchoPatron,j*altoPatron,patronActual);
                j++;
            }
            i++;
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
