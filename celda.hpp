#ifndef CELDA_HPP
#define CELDA_HPP

namespace SHC
{
    class Celda
    {
    public:
        enum Estado {empty=0, full, next_empty, next_full};

        Celda(Estado inicial=empty);

        Celda& operator=(Estado nuevo);
        bool operator==(Estado comparar);

        /// Obtiene un valor según conectividad.
        /// NOTA: Para pruebas.
        int valorada();

        /// Actualiza los estados 'next' a los actuales.
        void update ();

    private:
        Estado actual;
    };
}

#endif // CELDA_HPP
