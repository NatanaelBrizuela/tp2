#include <iostream>
#include "gondola.h"
#include "Productos.h"

using namespace std;

Gondola::Gondola(int capacidad, int cantProductos)
{
    this->capacidad = capacidad;
    this->cantProductos = cantProductos;
    this->productosEnGondola = new Producto *[capacidad];
}

Gondola::Gondola(const Gondola &otraGondola)
{
    this->capacidad = otraGondola.capacidad;
    this->cantProductos = otraGondola.cantProductos;

    this->productosEnGondola = new Producto *[capacidad];

    for (int i = 0; i < cantProductos; i++)
    {
        if (otraGondola.productosEnGondola[i] != nullptr)
        {
            this->productosEnGondola[i] = new Producto(*(otraGondola.productosEnGondola[i]));
        }
        else
        {
            this->productosEnGondola[i] = nullptr;
        }
    }
}
Gondola::~Gondola()
{
    for (int i = 0; i <= cantProductos; i++)
    {
        delete productosEnGondola[i];
    }
    delete[] productosEnGondola;
}

Producto *Gondola::getProductoI(int i) const
{
    if (i >= 0 && i < cantProductos)
    {
        return productosEnGondola[i];
    }
    else
    {
        return nullptr;
    }
}

void Gondola::agregarProducto(const string nombre, float precio, bool oferta, int cantidad)
{
    if (cantProductos >= capacidad)
    {
        Producto **nuevoVector = new Producto *[capacidad + 1];
        cout << "Gondola llena, se agrandara a " << capacidad + 1 << " espacios " << endl;

        for (int i = 0; i < capacidad; i++)
        {
            nuevoVector[i] = productosEnGondola[i];
        }

        delete[] productosEnGondola;
        capacidad++;
        productosEnGondola = nuevoVector;
    }

    productosEnGondola[cantProductos++] = new Producto(nombre, precio, oferta, cantidad);
}

void Gondola::quitarProductoGondola(int indice)
{
    if (indice >= cantProductos)
    {
        cout << "El producto no existe" << endl;
    }
    else
    {
        swap(indice);

        Producto **nuevoVector = new Producto *[cantProductos - 1];
        for (int i = 0; i < cantProductos - 1; i++)
        {
            nuevoVector[i] = productosEnGondola[i];
        }
        delete[] productosEnGondola;
        cantProductos--;

        productosEnGondola = nuevoVector;
    }
}

void Gondola::swap(int indice)
{
    // Verifica que el índice esté en el rango correcto
    if (indice >= 0 && indice < cantProductos)
    {
        // Intercambia los punteros sin eliminar ningún producto
        Producto *auxiliar = productosEnGondola[indice];
        productosEnGondola[indice] = productosEnGondola[cantProductos - 1];
        productosEnGondola[cantProductos - 1] = auxiliar;
    }
    else
    {
        cout << "Índice fuera de rango" << endl;
    }
}

void Gondola::mostrar()
{
    cout << "-----------------PRODUCTOS EN GONDOLA-----------------" << endl;
    for (int i = 0; i < cantProductos; i++)
    {
        cout
            << productosEnGondola[i]->getNombre() << "\t"
            << productosEnGondola[i]->getPrecios() << "\t"
            << productosEnGondola[i]->getOferta() << "\t"
            << productosEnGondola[i]->getCantidad() << endl;
    }
}

Producto *Gondola::getProductoI(int i)
{
    if (i >= 0 && i < cantProductos)
    {
        return productosEnGondola[i];
    }
    else
    {
        return nullptr;
    }
}

int Gondola::getCantProductos() { return cantProductos; }
string Gondola::getNombreEnGodnola(int i) { return productosEnGondola[i]->getNombre(); }
float Gondola::getPrecioEnGodnola(int i) { return productosEnGondola[i]->getPrecios(); }
bool Gondola::GetOfertaEnGondola(int i) { return productosEnGondola[i]->getOferta(); }
int Gondola::getCantProductEnGodnola(int i) { return productosEnGondola[i]->getCantidad(); }

void Gondola::setCantidadGondola(int indice, int nuevCantidad)
{
    productosEnGondola[indice]->setCantidad(nuevCantidad);
}