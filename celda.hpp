#ifndef CELDA_HPP
#define CELDA_HPP

namespace SHC
{
    class Celda
    {
    public:
        enum Estado {empty=0, full};

        Celda(Estado inicial=empty);
        Celda& operator=(Estado nuevo);

    private:
        Estado actual;
    };
}

#endif // CELDA_HPP