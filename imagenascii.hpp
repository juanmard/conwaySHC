#ifndef IMAGENASCII_HPP
#define IMAGENASCII_HPP

#include <string>
#include <fstream>

namespace SHC
{
    class ImagenASCII
    {
    public:
        ImagenASCII(const std::string &fichero);
        ~ImagenASCII();

        std::string readLine();
        std::string getCaracteres();

    private:
        std::ifstream inFile;
    };

}

#endif // IMAGENASCII_HPP
