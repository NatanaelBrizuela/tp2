#include <iostream>
#include <fstream>

#include "funciones.h"
using namespace std;

int main()
{
    fstream archProductos = abrirArch(PATH_PRODUCTOS, Lectura);
    fstream archCompras = abrirArch(PATH_COMPRA, Lectura);

    Gondola gondolaN(5, 0);
    Chango changoN(0);

    llenarGondola(gondolaN, archProductos);
    llenarChango(changoN, archCompras, gondolaN);

    changoN.mostrar();
    gondolaN.mostrar();

    archProductos.close();
    archCompras.close();

    actualizarArchivos(gondolaN);
    return 0;
}
