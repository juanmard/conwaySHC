#include "imagenascii.hpp"
#include <sstream>

namespace SHC
{
    ImagenASCII::ImagenASCII(const std::string& fichero)
    {
        inFile.open(fichero);
    }

    ImagenASCII::~ImagenASCII()
    {
        if (inFile.is_open())
        {
            inFile.close();
        }
    }

    std::string ImagenASCII::readLine()
    {
        std::string linea;
        if (inFile.is_open())
        {
            std::getline(inFile, linea);
        }
        return linea;
    }

    std::string ImagenASCII::getCaracteres()
    {
        std::ostringstream caracteres;

        char ch;
        while (inFile >> ch)
        {
            if (caracteres.str().find(ch) == std::string::npos)
            {
                caracteres << ch;
            }
        }
        return caracteres.str();
    }
}
