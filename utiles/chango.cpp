#include <iostream>
#include "chango.h"

using namespace std;

Chango::Chango(int cantidaEnChango = 0)
{
    this->cantidaEnChango = cantidaEnChango;
    this->productosChango = nullptr;
}

void Chango::agrearAChango(string nombre, float precio, bool oferta, int cantidad)
{

    Producto **nuevoVectorChango = new Producto *[cantidaEnChango + 1];
    if (cantidaEnChango != 0)
    {
        for (int i = 0; i < cantidaEnChango; i++)
        {
            nuevoVectorChango[i] = productosChango[i];
        }
    }
    delete[] productosChango;

    nuevoVectorChango[cantidaEnChango++] = new Producto(nombre, precio, oferta, cantidad);
    productosChango = nuevoVectorChango; // se puede estar espcapando memoria?
}
void Chango::mostrar()
{
    cout << "-----------------PRODUCTOS EN CHANGO-----------------" << endl;
    for (int i = 0; i < cantidaEnChango; i++)
    {
        cout << productosChango[i]->getNombre() << "\t"
             << productosChango[i]->getPrecios() << "\t"
             << productosChango[i]->getOferta() << "\t"
             << productosChango[i]->getCantidad() << "\t"
             << productosChango[i]->getCantidad() * productosChango[i]->getPrecios() << endl;
    }
}

Chango::~Chango()
{
    for (int i = 0; i < cantidaEnChango; i++)
    {
        delete productosChango[i];
    }
    delete[] productosChango;
}
