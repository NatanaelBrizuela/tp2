#include "funciones.h"
#include <iostream>
#include <fstream>

using namespace std;

fstream abrirArch(string path, ModoLectura modo)
{
    ios_base::openmode modoApertura;

    if (modo == ModoLectura::Lectura)
    {
        modoApertura = ios::in;
    }
    else if (modo == ModoLectura::Escritura)
    {
        modoApertura = ios::out | ios::trunc;
    }

    fstream archivo(path, modoApertura);

    if (!archivo.is_open())
    {
        cout << "no se pudo abrir el arhcivo:" << path << endl;
        exit(EXIT_FAILURE);
    }
    return archivo;
}

void llenarGondola(Gondola &gondolaN, fstream &archProductos)
{
    string nombre;
    float precio;
    bool oferta;
    int cantidad;

    while (archProductos >> nombre >> precio >> oferta >> cantidad)
    {
        gondolaN.agregarProducto(nombre, precio, oferta, cantidad);
    }
}

void llenarChango(Chango &changoN, fstream &archCompras, Gondola &gondolaN)
{
    string nombreCompra;
    int cantidadCompra;
    while (archCompras >> nombreCompra >> cantidadCompra)
    {
        bool seEncontro = false;
        for (int i = 0; i < gondolaN.getCantProductos(); i++)
        {
            if (gondolaN.getNombreEnGodnola(i) == nombreCompra)
            {
                seEncontro = true;
                procesarCompra(changoN, nombreCompra, cantidadCompra, gondolaN, i);
                actualizarCantidadGondola(i, gondolaN, cantidadCompra);
            }
        }
        if (!seEncontro)
        {
            cout << " no se encontro el producto" << nombreCompra << endl;
        }
    }
}

void procesarCompra(Chango &ChangoN, string nombreCompra, int cantidadCompra, Gondola &gondolaN, int indice)
{
    string nombre = nombreCompra;
    float precio = gondolaN.getPrecioEnGodnola(indice);
    bool oferta = gondolaN.GetOfertaEnGondola(indice);
    int cantidadGondola = gondolaN.getCantProductEnGodnola(indice);

    if (cantidadCompra > cantidadGondola)
    {
        cout << "no hay " << cantidadCompra
             << " productos de " << nombre
             << "en la gondola, se agregaran solo: " << cantidadGondola << endl;
        cantidadCompra = cantidadGondola;
    }
    ChangoN.agrearAChango(nombre, precio, oferta, cantidadCompra);
}

void actualizarCantidadGondola(int indice, Gondola &gondolaN, int cantidadCompra)
{
    int nuevCantidadGondola = gondolaN.getCantProductEnGodnola(indice) - cantidadCompra;

    if (nuevCantidadGondola <= 0)
    {
        gondolaN.quitarProductoGondola(indice);
    }
    else
    {
        gondolaN.setCantidadGondola(indice, nuevCantidadGondola);
    }
}

void actualizarArchivos(Gondola &godnolaN)
{

    fstream nAchProductos = abrirArch(PATH_PRODUCTOS, Escritura);

    for (int i = 0; i < godnolaN.getCantProductos(); i++)
    {
        nAchProductos << godnolaN.getNombreEnGodnola(i) << "\t"
                      << godnolaN.getPrecioEnGodnola(i) << "\t"
                      << godnolaN.GetOfertaEnGondola(i) << "\t"
                      << godnolaN.getCantProductEnGodnola(i) << endl;
    }

    nAchProductos.close();
}