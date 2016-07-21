#include "matbin.hpp"

namespace SHC
{
    MatBin::MatBin ():
    vectores()
    {
    }

    MatBin::MatBin (unsigned int filas, unsigned int columnas)
    {
        vectores.resize(columnas, *new VecBin(filas));
    }

    SHC::VecBin& MatBin::operator[] (unsigned int i)
    {
//        if (i < vectores.size())
//        {
//            return vectores[i];
//        }
//        else
//        {
//            throw *new std::exception("Se ha intentado obtener un número de vector que no existe en la matriz.\nRevise sus índices y el tamaño de la matriz.");
//        }
        return vectores[i];
    }
}
